# -*- coding: utf-8 -*-

import sys
import os
import platform
import subprocess
import Queue
import threading
import ipaddress
import re

def worker_func(pingArgs, pending, done):
    try:
        while True:
            # Get the next address to ping.
            address = pending.get_nowait()

            ping = subprocess.Popen(pingArgs + [address],
                stdout = subprocess.PIPE,
                stderr = subprocess.PIPE
            )
            out, error = ping.communicate()
            
            if re.match(r".*, 0% packet loss.*", out.replace("\n", "")):
                done.put(address)

            # Output the result to the 'done' queue.
    except Queue.Empty:
        # No more addresses.
        pass
    finally:
        # Tell the main thread that a worker is about to terminate.
        done.put(None)

# The number of workers.
NUM_WORKERS = 14

plat = platform.system()
scriptDir = sys.path[0]
hosts = os.path.join(scriptDir, 'hosts.txt')

# The arguments for the 'ping', excluding the address.
if plat == "Windows":
    pingArgs = ["ping", "-n", "1", "-l", "1", "-w", "100"]
elif plat == "Linux":
    pingArgs = ["ping", "-c", "1", "-l", "1", "-s", "1", "-W", "1"]
else:
    raise ValueError("Unknown platform")

# The queue of addresses to ping.
pending = Queue.Queue()

# The queue of results.
done = Queue.Queue()

# Create all the workers.
workers = []
for _ in range(NUM_WORKERS):
    workers.append(threading.Thread(target=worker_func, args=(pingArgs, pending, done)))

# Put all the addresses into the 'pending' queue.
for ip in list(ipaddress.ip_network(u"10.69.69.0/24").hosts()):
    pending.put(str(ip))

# Start all the workers.
for w in workers:
    w.daemon = True
    w.start()

# Print out the results as they arrive.

numTerminated = 0
while numTerminated < NUM_WORKERS:
    result = done.get()
    if result is None:
        # A worker is about to terminate.
        numTerminated += 1
    else:
        print result # print out the ok ip

# Wait for all the workers to terminate.
for w in workers:
    w.join()
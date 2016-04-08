# -*- coding: utf-8 -*-

from gevent import subprocess
import itertools
from gevent.pool import Pool

pool = Pool(100) # concurrent action count

ips = itertools.product((10, ), (69, ), (69, ), range(1, 255))

def get_response_time(ip):
    try:
        out = subprocess.check_output('ping -c 1 -W 1 {}.{}.{}.{}'.format(*ip).split())
        for line in out.splitlines():
            if '0% packet loss' in line:
                return ip
    except subprocess.CalledProcessError:
        pass

    return None

resps = pool.map(get_response_time, ips)
reachable_resps = filter(lambda (ip): ip != None, resps)

for ip in reachable_resps:
    print ip

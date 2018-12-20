#include <algorithm>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <boost/bind.hpp>
#include <boost/cstdint.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/optional.hpp>
using namespace boost;
using namespace boost::asio;
using namespace std;

typedef ip::tcp::acceptor acceptor;
typedef ip::tcp::endpoint endpoint;
typedef std::shared_ptr<ip::tcp::socket> socket_ptr;

class server
{
public:
    server() : m_acceptor(m_io, endpoint(ip::tcp::v4(), 6688))
    {
        accept();
    }
    void run()
    {
        m_io.run();
    }
private:
    void accept()
    {
        socket_ptr sock(new ip::tcp::socket(m_io));
        m_acceptor.async_accept(*sock, bind(&server::accept_handler, this, boost::asio::placeholders::error, sock));
    }
    
    void accept_handler(const boost::system::error_code& ec, socket_ptr sock)
    {
        if (ec)return;
        cout << "client:" << endl;
        cout << sock->remote_endpoint().address() << endl;
        sock->async_write_some(buffer(boost::lexical_cast<std::string>(++a)), bind(&server::write_handler, this, boost::asio::placeholders::error, sock));
        accept();
    }
    void write_handler(const boost::system::error_code& ec, socket_ptr sock)
    {
        if (ec)return;
        sock->async_read_some(buffer(m_buffer, 100), bind(&server::read_handler, this, boost::asio::placeholders::error, sock));
    }
    void read_handler(const boost::system::error_code& ec, socket_ptr sock)
    {
        if (ec)return;
        cout << "read something:" << m_buffer << endl;
        cout << "ready to write again" << endl;
        sock->async_write_some(buffer(boost::lexical_cast<std::string>(++a)), bind(&server::write_handler, this, boost::asio::placeholders::error, sock));
    }
    io_service m_io;
    acceptor m_acceptor;
    int a = 0;
    char m_buffer[100];
};

class client
{
public:
    client() : m_ep(ip::address::from_string("127.0.0.1"), 8002)
    {
        start();
    }
    void run()
    {
        m_io.run();
    }
private:
    void start()
    {
        socket_ptr sock(new ip::tcp::socket(m_io));
        sock->async_connect(m_ep, bind(&client::conn_handler, this, boost::asio::placeholders::error, sock));
    }
    
    void conn_handler(const boost::system::error_code& ec, socket_ptr sock)
    {
        if (ec) return;
        cout << "receive from" << sock->remote_endpoint().address() << endl;
        sock->async_read_some(buffer(m_buffer, 100), bind(&client::read_handler, this, boost::asio::placeholders::error, sock));
    }
    void read_handler(const boost::system::error_code& ec, socket_ptr sock)
    {
        std::string a = "hello";
        auto b = std::make_shared<std::string>(a);
        cout << "get:" << m_buffer << endl;
        sock->async_write_some(buffer(*b), bind(&client::conn_handler, this, boost::asio::placeholders::error, sock));
    }
    io_service m_io;
    char m_buffer[100];
    endpoint m_ep;
};

char* temp, *serverPem, *operatorCert, *operatorKey;

std::string getCertPath(char* certPath)
{
    std::ostringstream strm{std::ios_base::ate};
    const char* workingDir = std::getenv("working_dir");
    strm << (workingDir == nullptr ? "/rom/config/ne3sadapt/configs" : workingDir)
    << "/certs/" << certPath;
    return strm.str();
}


class A
{
public:
    virtual void test(int a, int b = 10) = 0;
};

class B : public A
{
public:
    void test(int a, int b) override
    {
        cout << b << endl;
    }
    
};
boost::optional<std::pair<std::string, std::string>> getData(){
    return boost::optional<std::pair<std::string, std::string>>({"a", "b"});
}

int main()
{
    A* b = new B();
    
    b->test(5);
    
    std::cout << getData().get().first;
    std::pair<std::string, std::string> what;
    what = {"a", "b"};
    
    return 0;
}


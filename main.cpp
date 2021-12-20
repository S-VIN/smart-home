#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>

using Tcp = boost::asio::ip::tcp;

class Connection
{
private:
    Tcp::socket mSocket;
    boost::asio::io_context& mIoContext;

    Tcp::endpoint mEndpoint;
    char mBuffer[128];
    Tcp::acceptor mAcceptor;

    void read(const boost::system::error_code& err)
    {


    }
    void handler(const boost::system::error_code& err)
    {
        if (mSocket.available())
        {
            mSocket.async_read_some(boost::asio::buffer(mBuffer, 128),
                                    boost::bind(&Connection::handler, this, boost::asio::placeholders::error));
            std::cout << mBuffer << std::endl;
        }
        else
        {
            //mAcceptor.async_accept(mSocket, boost::bind(&Connection::handler, this, boost::asio::placeholders::error));
            mSocket.async_read_some(boost::asio::buffer(mBuffer, 128),
                                    boost::bind(&Connection::handler, this, boost::asio::placeholders::error));
        }
    }

public:
    Connection(boost::asio::io_context& aIoContext, Tcp::endpoint aEndpoint):
        mSocket(aIoContext),
        mIoContext(aIoContext),
        mEndpoint(aEndpoint),
        mAcceptor(aIoContext, aEndpoint)
    {
        mAcceptor.async_accept(mSocket, boost::bind(&Connection::handler, this, boost::asio::placeholders::error));
    }


    ~Connection()
    {
        mSocket.close();
    }

};


class Server
{
public:
    boost::asio::io_context mIoContext;
    std::vector<std::shared_ptr<Connection>> mConnections;

    Server()
    {

    }

    void createConnection(int aPort)
    {
        auto tmp = std::make_shared<Connection>(mIoContext, Tcp::endpoint(Tcp::v4(), aPort));
        mConnections.push_back(tmp);

    }

};
int main(int argc, char* argv[])
{

    Server s;
    s.createConnection(1111);
    s.mIoContext.run();

    return 0;
}
#include "IConnector.h"
#include <boost/asio.hpp>
#include <iostream>
#include <vector>


using Tcp = boost::asio::ip::tcp;

class UsualConnector
{
public:
  UsualConnector():
      acceptor(service, Tcp::endpoint(Tcp::v4(), 8001)),
      sock(service),
      buf(1024)
    {}
  ~UsualConnector()
  {
    stop();
  }

  int Connect(std::vector<std::string> argc)
  {

    return 0;
  }

private:
    boost::asio::io_service service;
    Tcp::socket sock;
    Tcp::acceptor acceptor;
    boost::asio::streambuf buf;


    void on_read(const boost::system::error_code& err, size_t bytes) {
        std::cout << endl << "on_read turn. { \n err: " << err.message() << endl << "bytes: " << bytes << "\n}" << std::endl;
        if (!err) {
            std::cout << "server echoed our " << "FAIL" << std::endl;
        }
    };

    size_t read_complete(const boost::system::error_code& err, size_t bytes) {
        std::this_thread::sleep_for(chrono::milliseconds(1000));
        boost::asio::async_read(sock, buf, read_complete(err, bytes), on_read(err, bytes));
        std::cout << endl << "read_complete turn. { \n err: " << err.message() << endl << "bytes: " << bytes << "\n}" << std::endl;
        service.run_one();
        return 0;
    };

    void connect_handler(const boost::system::error_code& ec) {
        std::cout << "connect_handler." << std::endl;
        cout << ec.value();
        cout << ec.message();
        boost::asio::async_read(sock, buf, read_complete, on_read);
        service.run_one();
    };

};




void handle_accept(talk_to_client::ptr client, const error_code & err)
{
    client->start();
    talk_to_client::ptr new_client = talk_to_client::new_();
    acceptor.async_accept(new_client->sock(),
                          boost::bind(handle_accept,new_client,_1));
}
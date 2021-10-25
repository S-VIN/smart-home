#include <pqxx/pqxx>

class Connections {
public:
    static Connections& getInstance() {
        static Connections  instance;
        // Instantiated on first use.
        return instance;
    }
    Connections(Connections const&) = delete;
    void operator=(Connections const&) = delete;
    pqxx::connection& getConection(){
        return *C;
    }


private:
    std::shared_ptr<pqxx::connection> C;
    Connections() {
        C = std::make_shared<pqxx::connection>("user=postgres password=3228 host=localhost port=5432 dbname=smarthome");
    }
};

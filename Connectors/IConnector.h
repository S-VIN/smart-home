#include <vector>

class IBasicConnector {
protected:
    IBasicConnector(){};
    virtual int Connect(std::vector<std::string> argc) = 0;
};
#include <iostream>
#include <vector>
#include <string>
#include "orm/statedb.h"

int main()
{
    States s;

    auto res = s.getIds();

    if(s.getStateById(11)){
        cout << s.getStateById(11).value();
    }


    return 0;
}
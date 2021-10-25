#include <iostream>
#include <vector>
#include <string>
#include "Orm/statedb.h"
#include "Connectors/Usual.h"

int main()
{
    UsualConnector connector;
    connector.Connect({"","",""});
    return 0;
}
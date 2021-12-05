#pragma once

#include "Connections.h"
#include "../Basis.h"
#include <pqxx/pqxx>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class States
{
private:
  pqxx::basic_connection_base<pqxx::connect_direct> &conn = Connections::getInstance().getConection();
public:
  std::vector<int> getIds()
  {
    pqxx::work W{conn};
    pqxx::result R{W.exec("SELECT id_device FROM statesdb")};
    std::vector<int> res;
    std::transform(
      R.begin(),
      R.end(),
      std::back_inserter(res),
      [](pqxx::row r){ return r.at(0).as<int>(); }
    );
    return res;
  }

  std::optional<bool> getStateById(int aId)
  {
    pqxx::work W{conn};
    try
    {
      pqxx::result R{W.exec("SELECT state FROM statesdb WHERE id_device = " + std::to_string(aId))};
      return R.at(0).at(0).as<bool>();
    }
    catch (pqxx::range_error e)
    {
      return std::nullopt;
    }
  }

  int createStateDevice(std::string aName, bool aInitState = false)
  {
    pqxx::work W{conn};
    W.exec(
      " INSERT INTO statesdb (id_device, name_of_device, state) VALUES (nextval('states_sequence'), '" + aName + "', " +
      boolToString(aInitState) + ");");
    return 0;
  }
};

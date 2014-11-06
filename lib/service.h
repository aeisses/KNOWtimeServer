#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include "route.h"
#include "database.h"

using namespace std;
using namespace pqxx;

class Service {

  public:
    static void startService();
};

#endif

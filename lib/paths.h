#ifndef PATHS_H
#define PATHS_H

#include <vector>
#include <algorithm>
#include "database.h"
#include "path.h"

using namespace std;
using namespace pqxx;

class Paths {

  private:
    typedef vector<Path*> PathList;
    static PathList paths;

  public:
    static void loadPaths();
    static Path* getPath(string);
    static void clearPaths();
};

#endif

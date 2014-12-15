#ifndef PATHELEMENT_H
#define PATHELEMENT_H

#include <string>
#include <pqxx/pqxx>
#include "utils.h"
#include <sstream>

using namespace std;
using namespace pqxx;

class PathElement {

  private:
    Location *location;

  public:
    int sequence;
    PathElement(double, double);
    PathElement(result::const_iterator);
    ~PathElement();
    Location* getLocation();
    bool operator== (const PathElement&);
    bool operator> (const PathElement&);
    bool operator< (const PathElement&);
};

#endif

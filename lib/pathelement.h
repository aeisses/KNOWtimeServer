#ifndef PATHELEMENT_H
#define PATHELEMENT_H

#include <string>
#include <pqxx/pqxx>
#include "utils.h"

using namespace std;
using namespace pqxx;

class PathElement {

  private:
    Location *location;
    bool operator== (const PathElement& lhs) {
      if (this->sequence == lhs.sequence) {
        return true;
      }
      return false;
    }
    bool operator> (const PathElement& lhs) {
      if (this->sequence > lhs.sequence) {
        return true;
      }
      return false;
    }
    bool operator< (const PathElement& lhs) {
      if (this->sequence < lhs.sequence) {
        return true;
      }
      return false;
    }

  public:
    int sequence;
    PathElement(double, double);
    PathElement(result::const_iterator);
    ~PathElement();
    Location* getLocation();
};

#endif

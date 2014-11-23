#ifndef PATHELEMENT_H
#define PATHELEMENT_H

#include <string>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

class PathElement {

  private:
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
    double lat;
    double lng;
    int sequence;
    PathElement(double, double);
    PathElement(result::const_iterator);
    ~PathElement();
};

#endif

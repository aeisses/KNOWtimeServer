#ifndef PATH_H
#define PATH_H

#include <string>
#include <pqxx/pqxx>
#include <algorithm>
#include "pathelement.h"
#include "utils.h"

using namespace std;
using namespace pqxx;

typedef vector<PathElement*> PathElements;

class Path {

  private:
    double reducePercision(double);
    bool operator== (const Path& lhs) {
      if (this->id.compare(lhs.id) == 0) {
        return true;
      }
      return false;
    }
    bool operator> (const Path& lhs) {
      if (this->id.compare(lhs.id) > 0) {
        return true;
      }
      return false;
    }
    bool operator< (const Path& lhs) {
      if (this->id.compare(lhs.id) < 0) {
        return true;
      }
      return false;
    }

  public:
    PathElements pathElements;
    PathElements reversePathElements;
    string id;
    Path(string);
    Path(result::const_iterator);
    ~Path();
    void addElement(result::const_iterator);
    void sortPathElements();
    PathElements::const_iterator getPathElementForStop(Location*, PathElements::const_iterator, int);
};

#endif

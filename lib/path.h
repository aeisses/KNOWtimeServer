#ifndef PATH_H
#define PATH_H

#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include <algorithm>
#include "pathelement.h"

using namespace std;
using namespace pqxx;

class Path {

  private:
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
    typedef vector<PathElement*> PathElements;
    PathElements pathElements;
    string id;
    Path(string);
    Path(result::const_iterator);
    ~Path();
    void addElement(result::const_iterator);
    void sortPathElements();
};

#endif

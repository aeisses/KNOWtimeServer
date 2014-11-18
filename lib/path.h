#ifndef PATH_H
#define PATH_H

#include <string>
#include <pqxx/pqxx>

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
    string id;
    double lat;
    double lng;
    int sequence;
    Path(string);
    Path(result::const_iterator);
    ~Path();
};

#endif

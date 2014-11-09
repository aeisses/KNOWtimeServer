#ifndef PATH_H
#define PATH_H

#include <string>

using namespace std;

class Path {
  public:
    string id;
    double lat;
    double lng;
    int sequence;
    Path(string, double, double, int);
};

#endif

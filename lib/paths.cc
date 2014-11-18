#include "paths.h"

vector<Path*> Paths::paths;

void Paths::loadPaths() {
  queryResult myResult = DataBase::executeQuery("SELECT * FROM shapes");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      Path *path = new Path(c);
      paths.push_back (path);
    }
  }
}

Path* Paths::getPaths(string id) {
  Path *path = new Path(id);
  PathList::iterator it = find(paths.begin(), paths.end(), path);
  if (it != paths.end()) {
    return (*it);
  }
  return NULL;
}

void Paths::clearPaths() {
  PathList().swap(paths);
}


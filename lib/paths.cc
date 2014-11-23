#include "paths.h"

vector<Path*> Paths::paths;

void Paths::loadPaths() {
  queryResult myResult = DataBase::executeQuery("SELECT id,lat,long,sequence FROM shapes");
  if (myResult.code == DB_SUCCESS) {
    for (result::const_iterator c = myResult.R.begin(); c != myResult.R.end(); ++c) {
      if (!c[0].is_null()) {
        Path *checkPath = new Path(c[0].as<string>());
        PathList::iterator it = find(paths.begin(), paths.end(), checkPath);
        if (it != paths.end()) {
          (*it)->addElement(c);
        } else {
          Path *path = new Path(c);
          paths.push_back (path);
        }
      }
    }
  }
  for (PathList::const_iterator it = paths.begin(); it != paths.end(); ++it) {
    (*it)->sortPathElements();
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


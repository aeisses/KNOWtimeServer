#include "path.h"

Path::Path(string _id) {
  id = _id;
}

Path::Path(result::const_iterator c) {
  
  // Get the id if the value is not NULL
  if (c[0].is_null()) {
    id = "";
  } else {
    id = c[0].as<string>();
  }
  
  addElement(c);
}

Path::~Path() {
  PathElements().swap(pathElements);
}

void Path::addElement(result::const_iterator c) {
  cout << "Added Path Element" << endl;
  PathElement *pathElement = new PathElement(c);
  pathElements.push_back(pathElement);
}

void Path::sortPathElements() {
  sort(&(*pathElements.begin()),&(*pathElements.end()));
}

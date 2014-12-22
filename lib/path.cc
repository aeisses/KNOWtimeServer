#include "path.h"

// Private Methods
double Path::reducePercision(double value) {
  int tempValue = value * 1000;
  rint(tempValue);
  return (double)(tempValue / (double)(1000.0));
}

// Public Methods
// Constructor
Path::Path(string _id) {
  id = _id;
}

// Constructor
Path::Path(result::const_iterator c) {
  
  // Get the id if the value is not NULL
  if (c[0].is_null()) {
    id = "";
  } else {
    id = c[0].as<string>();
  }
  
  addElement(c);
}

// Destructor
Path::~Path() {
  PathElements().swap(pathElements);
}

// Add a path element to the vector of path elements
void Path::addElement(result::const_iterator c) {
  PathElement *pathElement = new PathElement(c);
  pathElements.push_back(pathElement);
}

// Sort the vector of path elements by the sequence number
// Sort is not working -> NOTE
void Path::sortPathElements() {
  sort(&(*pathElements.begin()),&(*pathElements.end()));
}

// Get the path element that is located on a stop. We need to reduce the presision of the long and lat to ensure we get a match
PathElements::const_iterator Path::getPathElementForStop(Location *location, PathElements::const_iterator startIterator, int direction) {
  if (location->latitude == -1 && location->longitude == -1) {
    return pathElements.begin();
  }
  for (PathElements::const_iterator it = startIterator; it != pathElements.end(); ++it) {
    Location *elementLocation = new Location();
    elementLocation->latitude = (*it)->getLocation()->latitude;
    elementLocation->longitude = (*it)->getLocation()->longitude;
    if (reducePercision(elementLocation->latitude) == reducePercision(location->latitude) && reducePercision(elementLocation->longitude) == reducePercision(location->longitude)) {
      delete elementLocation;
      return it;
    }
    delete elementLocation;
  }
  return pathElements.begin();
}

bool Path::operator== (const Path& lhs) {
  if (this->id.compare(lhs.id) == 0) {
    return true;
  }
  return false;
}

bool Path::operator> (const Path& lhs) {
  if (this->id.compare(lhs.id) > 0) {
    return true;
  }
  return false;
}

bool Path::operator< (const Path& lhs) {
  if (this->id.compare(lhs.id) < 0) {
    return true;
  }
  return false;
}


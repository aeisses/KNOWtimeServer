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
void Path::sortPathElements() {
  sort(&(*pathElements.begin()),&(*pathElements.end()));
}

// Get the path element that is located on a stop. We need to reduce the presision of the long and lat to ensure we get a match
PathElements::const_iterator Path::getPathElementForStop(Location *location, PathElements::const_iterator startIterator, int direction) {
  cout.precision(20);
  cout << "location lat: " << location->latitude << " long: " << location->longitude << endl;
  cout << "Start Iterator: " << (*startIterator)->sequence << endl;
//  cout << "Direction: " << direction << endl;
//  if (direction == 0) {
    if (location->latitude == -1 && location->longitude == -1) {
      return pathElements.begin();
    }
    cout << "Path Elements Size: " << pathElements.size() << endl;
    for (PathElements::const_iterator it = startIterator; it != pathElements.end(); ++it) {
      Location *elementLocation = new Location();
      elementLocation->latitude = (*it)->getLocation()->latitude;
      elementLocation->longitude = (*it)->getLocation()->longitude;
//      cout << "Element Latitude: " << reducePercision(elementLocation->latitude) << " Longitude: " << reducePercision(elementLocation->longitude) << endl;
//      cout << "Location Latitude: " << reducePercision(location->latitude) << " Longitude: " << reducePercision(location->longitude) << endl;
      if (reducePercision(elementLocation->latitude) == reducePercision(location->latitude) && reducePercision(elementLocation->longitude) == reducePercision(location->longitude)) {
        delete elementLocation;
        cout << "Found value" << endl;
        return it;
      }
      delete elementLocation;
    }
/*  } else if (direction == 1) {
    if (location->latitude == -1 && location->longitude == -1) {
      return pathElements.end();
    }
    cout << "Path Elements Size: " << pathElements.size() << endl;
    for (PathElements::const_iterator it = startIterator; it != pathElements.begin(); --it) {
      Location *elementLocation = new Location();
      elementLocation->latitude = (*it)->getLocation()->latitude;
      elementLocation->longitude = (*it)->getLocation()->longitude;
//      cout << "Element Latitude: " << elementLocation->latitude << " Longitude: " << elementLocation->longitude << endl;
//      cout << "Location Latitude: " << location->latitude << " Longitude: " << location->longitude << endl;
      if (reducePercision(elementLocation->latitude) == reducePercision(location->latitude) && reducePercision(elementLocation->longitude) == reducePercision(location->longitude)) {
        delete elementLocation;
        cout << "Found value" << endl;
        return it;
      }
      delete elementLocation;
    }*/
//  }
  // Need something better here
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


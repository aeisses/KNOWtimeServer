
// Constructor
module.exports = function Route(id, shortname, longname, type) {
  this.id = id;
  this.shortname = shortname;
  this.longname = longname;
  this.type = type;

  // Start the route
  console.log("Created route: "+shortname);
}



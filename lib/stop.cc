#include "stop.h"

Stop::Stop(int _id, string _name, string _stop_desc, double _lat, double _lng, string _street, string _city, string _region, string _postcode, string _country, string _zone_id) {
  id = _id;
  name = _name;
  stop_desc = _stop_desc;
  lat = _lat;
  lng = _lng;
  street = _street;
  city = _city;
  region = _region;
  postcode = _postcode;
  country = _country;
  zone_id = _zone_id;
}

create table routes(id text primary key not null, short_name text, long_name text, route_desc text, type int);
\copy routes from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/routes.csv' WITH CSV;
create table trips(route_id text, service_id text, trip_id text primary key not null, trip_headsign text, direction_id text, block_id text, shape_id text);
\copy trips from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/trips.csv' WITH CSV;

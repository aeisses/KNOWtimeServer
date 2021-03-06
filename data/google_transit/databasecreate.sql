create table calendar_dates(id text,date int,exception_type int);
\copy calendar_dates from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/calendar_dates.csv' WITH CSV;
create table calendar(id text,start_date int,end_date int,monday int,tuesday int,wednesday int,thursday int,friday int,saturday int,sunday int);
\copy calendar from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/calendar.csv' WITH CSV;
create table routes(long_name text,id text primary key not null,type int,route_text_colour text,agency_id text,route_color text,route_url text,route_desc text,short_name text);
\copy routes from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/routes.csv' WITH CSV;
create table shapes(id text,lat decimal,long decimal,sequence int,distanceTravelled text);
\copy shapes from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/shapes.csv' WITH CSV;
create table stop_times(id text,arrival_time text,departure_time text,stop_id text,stop_sequence int,stop_headsign text,pickup_type int,drop_off_type int,dist_traveled text);
\copy stop_times from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/stop_times.csv' WITH CSV;
create table stops(street text,lat real,name text,region text,zone_id text,country text ,long real,city text,id text primary key not null,stop_desc text,postcode text,type int);
\copy stops from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/stops.csv' WITH CSV;
create table trips(block_id text,route_id text,direction_id int,trip_headsign text,shape_id text,service_id text,trip_id text primary key not null);
\copy trips from '/Users/aeisses/Heroku/KNOWtimeServer/data/google_transit/trips.csv' WITH CSV;

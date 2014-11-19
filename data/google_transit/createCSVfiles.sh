#/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
rm "databasecreate.sql"
rm "calendar_dates.csv"
cdline="$(head -n 1 "calendar_dates.txt" | tr -d '\r' )"
cdput="create table calendar_dates("
IFS=',' read -a array <<< "$cdline"
for i in "${array[@]}"
do
  if [ "$i" == "service_id" ]; then
    id="id text"
    cdput="$cdput$id,"
  fi
  if [ "$i" == "date" ]; then
    date="date int"
    cdput="$cdput$date,"
  fi
  if [ "$i" == "exception_type" ]; then
    exception="exception_type int"
    cdput="$cdput$exception,"
  fi
done
cdput="${cdput%?});"
echo $cdput >> databasecreate.sql
echo "\copy calendar_dates from '$DIR/calendar_dates.csv' WITH CSV;" >> databasecreate.sql
tail -n +2 "calendar_dates.txt" >> "calendar_dates.csv"

rm "calendar.csv"
cline="$(head -n 1 "calendar.txt" | tr -d '\r' )"
cput="create table calendar("
IFS=',' read -a array <<< "$cline"
for i in "${array[@]}"
do
  if [ "$i" == "service_id" ]; then
    id="id text"
    cput="$cput$id,"
  fi
  if [ "$i" == "start_date" ]; then
    sd="start_date int"
    cput="$cput$sd,"
  fi
  if [ "$i" == "end_date" ]; then
    ed="end_date int"
    cput="$cput$ed,"
  fi
  if [ "$i" == "monday" ]; then
    mon="monday int"
    cput="$cput$mon,"
  fi
  if [ "$i" == "tuesday" ]; then
    tues="tuesday int"
    cput="$cput$tues,"
  fi
  if [ "$i" == "wednesday" ]; then
    wed="wednesday int"
    cput="$cput$wed,"
  fi
  if [ "$i" == "thursday" ]; then
    thur="thursday int"
    cput="$cput$thur,"
  fi
  if [ "$i" == "friday" ]; then
    fri="friday int"
    cput="$cput$fri,"
  fi
  if [ "$i" == "saturday" ]; then
    sat="saturday int"
    cput="$cput$sat,"
  fi
  if [ "$i" == "sunday" ]; then
    sun="sunday int"
    cput="$cput$sun,"
  fi
done
cput="${cput%?});"
echo $cput >> databasecreate.sql
echo "\copy calendar from '$DIR/calendar.csv' WITH CSV;" >> databasecreate.sql
tail -n +2 "calendar.txt" >> "calendar.csv"

rm "routes.csv"
rline="$(head -n 1 "routes.txt" | tr -d '\r' )"
rput="create table routes("
IFS=',' read -a array <<< "$rline"
for i in "${array[@]}"
do
  if [ "$i" == "route_long_name" ]; then
    ln="long_name text"
    rput="$rput$ln,"
  fi
  if [ "$i" == "route_id" ]; then
    id="id text primary key not null"
    rput="$rput$id,"
  fi
  if [ "$i" == "route_type" ]; then
    type="type int"
    rput="$rput$type,"
  fi
  if [ "$i" == "route_text_color" ]; then
    tc="route_text_colour text"
    rput="$rput$tc,"
  fi
  if [ "$i" == "agency_id" ]; then
    aid="agency_id text"
    rput="$rput$aid,"
  fi
  if [ "$i" == "route_color" ]; then
    rc="route_color text"
    rput="$rput$rc,"
  fi
  if [ "$i" == "route_url" ]; then
    rurl="route_url text"
    rput="$rput$rurl,"
  fi
  if [ "$i" == "route_desc" ]; then
    rdesc="route_desc text"
    rput="$rput$rdesc,"
  fi
  if [ "$i" == "route_short_name" ]; then
    sn="short_name text"
    rput="$rput$sn,"
  fi
done
rput="${rput%?});"
echo $rput >> databasecreate.sql
echo "\copy routes from '$DIR/routes.csv' WITH CSV;" >> databasecreate.sql
tail -n +2 "routes.txt" >> "routes.csv"

rm "shapes.csv"
shline="$(head -n 1 "shapes.txt" | tr -d '\r' )"
shput="create table shapes("
IFS=',' read -a array <<< "$shline"
for i in "${array[@]}"
do
  if [ "$i" == "shape_id" ]; then
    id="id text"
    shput="$shput$id,"
  fi
  if [ "$i" == "shape_pt_lat" ]; then
    slat="lat decimal"
    shput="$shput$slat,"
  fi
  if [ "$i" == "shape_pt_lon" ]; then
    slon="long decimal"
    shput="$shput$slon,"
  fi
  if [ "$i" == "shape_pt_sequence" ]; then
    sequence="sequence int"
    shput="$shput$sequence,"
  fi
  if [ "$i" == "shape_dist_traveled" ]; then
    dist="distanceTravelled text"
    shput="$shput$dist,"
  fi
done
shput="${shput%?});"
echo $shput >> databasecreate.sql
echo "\copy shapes from '$DIR/shapes.csv' WITH CSV;" >> databasecreate.sql
tail -n +2 "shapes.txt" >> "shapes.csv"

rm "stop_times.csv"
stline="$(head -n 1 "stop_times.txt" | tr -d '\r' )"
stput="create table stop_times("
IFS=',' read -a array <<< "$stline"
for i in "${array[@]}"
do
  if [ "$i" == "trip_id" ]; then
    tid="trip_id text"
    stput="$stput$id,"
  fi
  if [ "$i" == "arrival_time" ]; then
    at="arrival_time text"
    stput="$stput$at,"
  fi
  if [ "$i" == "departure_time" ]; then
    dt="departure_time text"
    stput="$stput$dt,"
  fi
  if [ "$i" == "stop_id" ]; then
    sid="stop_id text"
    stput="$stput$sid,"
  fi
  if [ "$i" == "stop_sequence" ]; then
    sequence="stop_sequence int"
    stput="$stput$sequence,"
  fi
  if [ "$i" == "stop_headsign" ]; then
    headsign="stop_headsign text"
    stput="$stput$headsign,"
  fi
  if [ "$i" == "pickup_type" ]; then
    pickup="pickup_type int"
    stput="$stput$pickup,"
  fi
  if [ "$i" == "drop_off_type" ]; then
    drop="drop_off_type int"
    stput="$stput$drop,"
  fi
  if [ "$i" == "shape_dist_traveled" ]; then
    dist="dist_traveled text"
    stput="$stput$dist,"
  fi
done
stput="${stput%?});"
echo $stput >> databasecreate.sql
echo "\copy stop_times from '$DIR/stop_times.csv' WITH CSV;" >> databasecreate.sql
tail -n +2 "stop_times.txt" >> "stop_times.csv"

rm "stops.csv"
sput="create table stops("
sline="$(head -n 1 "stops.txt" | tr -d '\r' )"
IFS=',' read -a array <<< "$sline"
for i in "${array[@]}"
do
  if [ "$i" == "stop_street" ]; then
    ss="street text"
    sput="$sput$ss,"
  fi
  if [ "$i" == "stop_lat" ]; then
    lat="lat real"
    sput="$sput$lat,"
  fi
  if [ "$i" == "stop_name" ]; then
    name="name text"
    sput="$sput$name,"
  fi
  if [ "$i" == "stop_region" ]; then
    region="region text"
    sput="$sput$region,"
  fi
  if [ "$i" == "zone_id" ]; then
    zone="zone_id text"
    sput="$sput$zone,"
  fi
  if [ "$i" == "stop_country" ]; then
    country="country text "
    sput="$sput$country,"
  fi
  if [ "$i" == "stop_lon" ]; then
    lon="long real"
    sput="$sput$lon,"
  fi
  if [ "$i" == "stop_city" ]; then
    city="city text"
    sput="$sput$city,"
  fi
  if [ "$i" == "stop_id" ]; then
    id="id text primary key not null"
    sput="$sput$id,"
  fi
  if [ "$i" == "stop_desc" ]; then
    desc="stop_desc text"
    sput=$sput$desc,""
  fi
  if [ "$i" == "stop_postcode" ]; then
    postcode="postcode text"
    sput="$sput$postcode,"
  fi
  if [ "$i" == "location_type" ]; then
    type="type int"
    sput="$sput$type,"
  fi
done
sput="${sput%?});"
echo $sput >> databasecreate.sql
echo "\copy stops from '$DIR/stops.csv' WITH CSV;" >> databasecreate.sql
tail -n +2 "stops.txt" >> "stops.csv"

rm "trips.csv"
tline="$(head -n 1 "trips.txt" | tr -d '\r' )"
tput="create table trips("
IFS=',' read -a array <<< "$tline"
for i in "${array[@]}"
do
  if [ "$i" == "block_id" ]; then
    block="block_id text"
    tput="$tput$block,"
  fi 
  if [ "$i" == "route_id" ]; then
    route="route_id text"
    tput="$tput$route,"
  fi
  if [ "$i" == "direction_id" ]; then
    route="direction_id int"
    tput="$tput$route,"
  fi
  if [ "$i" == "trip_headsign" ]; then
    headsign="trip_headsign text"
    tput="$tput$headsign,"
  fi
  if [ "$i" == "service_id" ]; then
    service="service_id text"
    tput="$tput$service,"
  fi
  if [ "$i" == "shape_id" ]; then
    shape="shape_id text"
    tput="$tput$shape,"
  fi
  if [ "$i" == "trip_id" ]; then
    trip="trip_id text primary key not null"
    tput="$tput$trip,"
  fi
done
tput="${tput%?});"
echo $tput >> databasecreate.sql
echo "\copy trips from '$DIR/trips.csv' WITH CSV;" >> databasecreate.sql
tail -n +2 "trips.txt" >> "trips.csv"

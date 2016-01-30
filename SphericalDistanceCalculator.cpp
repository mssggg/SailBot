#include "SphericalDistanceCalculator.h"
#include <iostream>
#include"GPSCoordinate.h"
using namespace std;

SphericalDisanceCalculator::SphericalDistanceCalculator(double r) {};
 double SphericalDisanceCalculator::calculateDistance( GPSCoordinate *coord1,  GPSCoordinate *coord2) {
	 double lat1r, lon1r, lat2r, lon2r, u, v;
	 double lat1 = coord1->lat;
	 double lon1 = coord1->lon;
	 double lat2 = coord2->lat;
	 double lon2 = coord2->lon;


	 lat1r = deg2rad(lat1* pi / 180);
	 lon1r = deg2rad(lon1* pi / 180);
	 lat2r = deg2rad(lat2* pi / 180);
	 lon2r = deg2rad(lon2* pi / 180);
	 u = sin((lat2r - lat1r) / 2);
	 v = sin((lon2r - lon1r) / 2);
	 return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r)* v * v));
	}


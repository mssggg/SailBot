#include <stdio.h>
#include <math.h> 
#include <cmath> 
#include <set>
#include "GPSCoordinte.h"
#include<gtest/gtest.h>

#define pi 3.14159265358979323846
#define earthRadiusm 6378100.0

bool IsAngleBetween(double firstAngle, double middleAngle, double secondAngle) {
	if ((firstAngle < middleAngle < secondAngle) || (firstAngle>middleAngle > secondAngle)) return true;
	else  return false;
}
double deg2rad(double deg) {
	return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
	return (rad * 180 / pi);
}

/**
* Returns the distance between two points on the Earth.
* Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
* @param lat1d Latitude of the first coord in degrees
* @param lon1d Longitude of the first coord in degrees
* @param lat2d Latitude of the second coord in degrees
* @param lon2d Longitude of the second coord in degrees
* @return The distance between the two coord in kilometers
*/
//assume coord store a set containing lat(first),lon(second)
double calculateDistance(GPSCoordinate *coord1, GPSCoordinate *coord2) {
	double lat1r, lon1r, lat2r, lon2r, u, v;
	double lat1 = coord1->lat;
	double lon1 = coord1->lon;
	double lat2 = coord2->lat;
	double lon2 = coord2->lon;


	lat1r = deg2rad(lat1);
	lon1r = deg2rad(lon1);
	lat2r = deg2rad(lat2);
	lon2r = deg2rad(lon2);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r)* v * v));
}
// could generate unit tests by unit test generator in visual studio 
int main()
{
	return 0;
}


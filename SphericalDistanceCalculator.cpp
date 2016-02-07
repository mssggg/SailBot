/*
 * SphericalDistanceCalculator.cpp

 */

#include "SphericalDistanceCalculator.h"

#include <cmath>

const double pi = 3.14159265358979323846;

SphericalDistanceCalculator::SphericalDistanceCalculator(double radius) {
	// TODO Auto-generated constructor stub
	radius_ = radius;
}

SphericalDistanceCalculator::~SphericalDistanceCalculator() {
	// TODO Auto-generated destructor stub
}


double SphericalDistanceCalculator::calculateDistance(GPSCoordinate *coord1, GPSCoordinate *coord2)
{
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
	return 2.0 * radius_ * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

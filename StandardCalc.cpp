#include <stdio.h>
#include <math.h> 
#include <cmath> 
#include <set>
#include <cassert>
#include <iostream>
using namespace std;


#define pi 3.14159265358979323846
#define earthRadiusm 6378100.0
class GPSCoordinate
{
public:

	double lat;
	double lon;
};

// this function checks whether or not
// the given angel is between -180 and 179
bool CheckInRange(double angle) {
	if (angle < -180 || angle > 179)
		return false;
	return true;
}

//this function should accept range of values, and bound them between-180 and 179.
//requires: three compass heading angles
//returns:wheter the middle angle is between angles one and two(exclusive)
bool IsAngleBetween(double firstAngle, double middleAngle, double secondAngle) {

	// first check given angles are in valid range
	if (!(CheckInRange(firstAngle) &&
			CheckInRange(middleAngle) &&
			CheckInRange(secondAngle)))
		return false;

	double min_angele, max_angle;
	if(firstAngle < secondAngle) {
		min_angele = firstAngle;
		max_angle = secondAngle;
	} else {
		min_angele = secondAngle;
		max_angle = firstAngle;
	}

	if (min_angele < middleAngle && middleAngle < max_angle) {
		return true;
	}else {
		return false;
	}
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


//requires:coord1, coord2 to be set of valid coordinates with latitude and longtitude
//returns: the "as the bird flies" distance between both coordinates in meters
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
	return 2.0 * earthRadiusm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

// test case for function TestIsAngleBetween
void TestIsAngleBetween() {
	cout << "begin testing function TestIsAngleBetween ... " << endl;
	assert(IsAngleBetween(10, 20, 30));
	assert(!IsAngleBetween(10, 30, 20));
	cout << "Testing function TestIsAngleBetween passed" << endl;
	cout << endl;
}

// test case for function TestIsAngleBetween
void TestcalculateDistance() {
	cout << "begin testing function calculateDistance ... " << endl;
	// test data from web: http://boulter.com/gps/distance/#more
	// NY 40.712784 -74.005941
	// BJ 39.904211 116.407395
	GPSCoordinate start, end;
	start.lat = 40.712784;
	start.lon = -74.005941;
	end.lat = 39.904211;
	end.lon = 116.407395;
	assert(fabs(calculateDistance(&start, &end) - 1.10013e7) < 1e3);
	cout << "Testing function calculateDistance passed" << endl;
}


int main()
{
	TestIsAngleBetween();
	TestcalculateDistance();
	return 0;
}


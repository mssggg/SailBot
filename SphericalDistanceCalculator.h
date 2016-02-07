/*
 * SphericalDistanceCalculator.h

 */

#ifndef SPHERICALDISTANCECALCULATOR_H_
#define SPHERICALDISTANCECALCULATOR_H_


extern const double pi;

class GPSCoordinate
{
public:

	double lat;
	double lon;
};

class SphericalDistanceCalculator {
public:
	SphericalDistanceCalculator(double radius);
	virtual ~SphericalDistanceCalculator();
	double calculateDistance(GPSCoordinate *coord1, GPSCoordinate *coord2);
private:
	double deg2rad(double deg) {
		return (deg * pi / 180);
	}
	double radius_;
};

#endif /* SPHERICALDISTANCECALCULATOR_H_ */

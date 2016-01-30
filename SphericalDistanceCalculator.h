#ifndef SPHERICAL_DISTANCE_CALCULATOR_H
#define SPHERICAL_DISTANCE_CALCULATOR_H
include"Gps_Coordinate"

using namespace std;


class SphericalDistanceCalculator
{
   public:
     
      SphericalDistanceCalculator:: SphericalDistanceCalculator(double r); // constructor
	  double( distanceDistanceGPSCoordinate& , GPSCoordinate& );
     
   protected:
      double radius;
};

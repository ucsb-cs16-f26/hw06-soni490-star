#include <iostream>
#include <string>
#include <sstream>  // for ostringstream
#include <iomanip> // for setprecision

using namespace std;


#include "shapes.h"
#include "shapeFuncs.h"
#include "utility.h"

#include <cmath> //only way to use std::pow and std::sqrt

// Compute distance between two points

double distanceBetween(Point p, Point q) {
  // sqrt((y2-y1)^2 + (x2-x1)^2)
  // std has sqrt function
  return sqrt(pow(q.x-p.x, 2)+pow(q.y-p.y, 2));
}

void initPoint(struct Point *p, double xVal, double yVal) {
  // use ->
  p->x = xVal;
  p->y = yVal;
}


string pointToString(Point p, int precision) {
  ostringstream oss;
  oss << setprecision(precision); // set precision to 3 decimal places
  oss << "(" << p.x << "," << p.y << ")";
  return oss.str();
}

string boxToString(Box b, int precision) {
  // SAMPLE FORMAT (precision = 2): "ul=(3.4,-5),w=5,h=7"
  ostringstream oss;
  oss << setprecision(precision); // set precision to 3 decimal places
  oss << "ul=(" << b.ul.x << "," << b.ul.y << "),w=" << b.width << ",h=" << b.height;
  //oss << "(" << p.x << "," << p.y << ")";
  return oss.str();
}
 


bool pointsApproxEqual(Point p1, 
		       Point p2, 
		       double tolerance) {
  // Two points are approximately equal if the distance between them
  // is less than our tolerance.  (If we want to test for 
  // exact equality, we can pass in a value of zero.)

  return distanceBetween(p1,p2) < tolerance;

}

bool boxesApproxEqual(Box b1, Box b2, double tolerance) {
  return pointsApproxEqual(b1.ul, b2.ul, tolerance)
      && approxEqual(b1.width, b2.width, tolerance)
      && approxEqual(b1.height, b2.height, tolerance);
}


void initBox(struct Box *b, double ulx, double uly, double w, double h){
  (b->ul).x = ulx;
  (b->ul).y = uly;
  b->width = w;
  b->height = h;
}

double areaOfBox(Box b) {
  return b.width*b.height;
}

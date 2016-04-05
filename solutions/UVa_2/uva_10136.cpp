/* UVa problem: 10136 - Chocolate Chip Cookies
 * Topic: Geometry
 * Brief problem description:
 *     Given a set of chocolate chips (points) on a grid, find the max number
 *     of points that fit inside a circle with a fixed radius of 2.5.
 *
 * Solution Summary:
 *     The Circle2PtsRad algorithm works like this, for every
 * 	   two points that are within a given radius (ex 2.5), it determines
 * 	   if it possible to create two circles which touch both points along
 * 	   their circumferences. If so, then it generates the middle points of
 * 	   those circles. With two circles of radius 2.5, and touching at the
 * 	   least 2 chocolate chips do a complete search of the rest of the
 * 	   chocolate chips to see if they fit into either of the circles.
 *
 * 	   Take the max of either circle and then move on by generating
 * 	   circles for the next two points.
 */
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

class point {
public:
	double x, y;
	point() {
		x = 0.0;
		y = 0.0;
	}
	point(double a, double b) {
		x = a;
		y = b;
	}
	bool operator==(point &p1) {
		return ((x == p1.x) && (y == p1.y));
	}
	bool operator!=(point &p1) {
		return !((x == p1.x) && (y == p1.y));
	}
};

double distance(point c, point p) {
	return sqrt((c.x - p.x) * (c.x - p.x) + (c.y - p.y) * (c.y - p.y));
}

//Competitive Programming 3: page 278
bool circle2PtsRad(point p1, point p2, double r, point *c) {
	double distsquare = (p1.x - p2.x) * (p1.x - p2.x)
			+ (p1.y - p2.y) * (p1.y - p2.y);
	double det = r * r / distsquare - 0.25;
	if (det < 0.0)
		return false;
	double h = sqrt(det);
	c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true;
}

int main() {
	int cases;
	double radius = 2.5;
	double diameter = 5.0;
	double epsilon =  1e-9; //hint from uDebug for 10136
	string line;
	vector<point> chips;
	vector<point>::iterator it, on, up;

	cin >> cases;
	getline(cin, line);
	getline(cin, line); // first space
	while (cases--) {
		int chocolate = 0, temp = 0, n = 0;
		double x, y;
		while (getline(cin, line) && line != "") {
			stringstream ss(line);
			ss >> x >> y;
			chips.push_back(point(x, y));
			n++;
		}

		for (it = chips.begin(); it != chips.end(); it++) {
			for (on = chips.begin(); on != chips.end(); on++) {
				point circle1, circle2;
				if (*it != *on) {
					if (circle2PtsRad(*it, *on, radius, &circle1)) {
						circle2PtsRad(*on, *it, radius, &circle2);
						int countfirst = 0, countsecond = 0;
						for (up = chips.begin(); up != chips.end(); up++) {
							if (distance(circle1, *up) <= radius + epsilon)
								countfirst++;
							if (distance(circle2, *up) <= radius + epsilon)
								countsecond++;
						}
						temp = max(countfirst, countsecond);
						if (temp > chocolate)
							chocolate = temp;
					}
				}
			}
		}
		if (chocolate == 0)
			cout << 1 << endl;
		else
			cout << chocolate << endl;

		if (cases > 0)
			cout << endl;
		chips.clear();
	}

	return 0;

}

/* UVa problem: 10065 - Useless Tile Packers
 * Topic: Geometry
 * Brief problem description:
 *    Given a series of points, find the area of the polygon it makes,
 *    find its convex hull, find the area of the convex hull, and then
 *    calculate how much more area the hull has over the original polygon.
 * Solution Summary:
 * 	  Used the code from the code archive for this problem.
 *
 * 	  Start by getting the area of the polygon we've read in. Area is made my summing up the
 * 	  cross product of two points and dividing by 2. Next we gather all the points and sort
 * 	  by the point with the lowest y and x coordinate. This is point is guarenteed to be
 * 	  part of our hull. Next we go through the list of points and compare the angle of that
 * 	  point to previous points. This is part of the 'rope' method of making a convex hull.
 * 	  Imagine that you start at the origin point and walk CCW around your group of points,
 * 	  if at any point we encounter a point that will result in a CW angle, we know that that
 * 	  is not part of our hull and discard it.
 *
 * 	  Then get the area of the hull same way as the original polygon and subtract.
 *
 */
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const double Epsilon = 1E-10;

typedef complex<double> Point;

//Code Archive: convex_hull.cpp
bool operator<(const Point & p1, const Point &p2)
{
    return p1.imag() < p2.imag() ||
            (fabs(p1.imag() - p2.imag()) < Epsilon && p1.real() < p2.real());
}

double cross(const Point &a, const Point &b) {
    return imag(conj(a)*b);
}


Point P0;

enum Direction {CCW, CW, CL};

Direction cross_prod_dir(const Point &p1, const Point &p2, const Point &p0)
{
    double res = cross(p1 - p0, p2 - p0);

    if (fabs(res) < Epsilon)
        return CL;
    else if (res > 0.0)
        return CW;
    else
        return CCW;
}


bool polar_cmp(Point p1, Point p2)
{
    Direction res = cross_prod_dir(p1, p2, P0);

    if (res == CW)
        return true;
    else if (res == CCW)
        return false;
    else {
        double d = norm(p1 - P0) - norm(p2 - P0);

        if (fabs(d) < Epsilon)
            return false;
        else if (d < 0.0)
            return true;
        else
            return false;
    }
}

vector<Point> convex_hull(vector<Point> &poly)
{
    if (poly.size() <= 1)
        return poly;

    vector<Point> hull;

    int min = 0;
    P0 = poly[0];

    // Find point that has lowest y, and then has lowest x
    for (int i = 1; i < poly.size(); i++) {
        if (poly[i].imag() < P0.imag() || (fabs(poly[i].imag() - P0.imag()) < Epsilon && (poly[i].real() < P0.real()))) {
          min = i;
          P0 = poly[i];
        }
    }

    // Put P0 into start of poly
    poly[min] = poly[0];
    poly[0] = P0;
    hull.push_back(P0);

    sort(poly.begin() + 1, poly.end(), polar_cmp);

    // Find first distinct element from P0
    int i;
    for (i = 1; i < poly.size(); i++) {
        if (norm(poly[i] - P0) > Epsilon)
          break;
    }

    if (i == poly.size())
        return hull;

    hull.reserve(poly.size());
    hull.push_back(poly[i++]);

    for ( ; i < poly.size(); i++) {
        while (hull.size() > 1 && cross_prod_dir(poly[i], *(hull.end() - 1), *(hull.end() - 2)) != CCW)
            hull.pop_back();

        hull.push_back(poly[i]);
    }

    return hull;
}

//Code Archive: area_poly.cpp
double area_poly(const vector<Point> &poly){
    double sum = 0;

    for(int i = poly.size()-1, j = 0; j < poly.size(); i = j++)
        sum += cross(poly[i], poly[j]);

    return sum/2.0;
}

int main(void)
{
    vector<Point> polygon, hull;
    cout << setprecision(2) << fixed;
    int n, x=1;

    while (cin >> n && n > 0) {
        polygon.resize(n);
        double hull_area, poly_area;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            polygon[i] = Point(x, y);
        }

        poly_area = fabs(area_poly(polygon));
        hull = convex_hull(polygon);
        hull_area = fabs(area_poly(hull));

        cout << "Tile #" << x << endl;
        cout << "Wasted Space = " << (1 - (poly_area / hull_area)) * 100 << " %" << endl;
        cout << endl;
        x++;

    }
    return 0;
}

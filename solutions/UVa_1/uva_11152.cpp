/* UVa problem: 11152 - Colourful Flowers
 * Topic: Geometry
 *
 * Brief problem description: 
 *   Find the incircle and circumcircle of a triangle when you are given the lengths
 *   of the triangles sides. Then find the area of each of these shapes. 
 *
 * Solution Summary:
 *
 *   You need to find the area of the triangle calculate the radius and area of the incircle
 *   and circumcircle using known equations, and then subtracting the area of the triangle from the
 *   circumcircle, and the area of the incircle from the triangle.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323846;

int main(){

	double a, b, c;
	double violets_A, sunflower_A, roses_A;
	double sem_perim, in_radius, out_radius;

	cout << std::setprecision(4) << std::fixed;

	while(cin >> a >> b >> c){
		//Area of the triangle
		sem_perim = (a + b + c)  * 0.5;
		violets_A = sqrt(sem_perim*(sem_perim - a)*(sem_perim - b)*(sem_perim -c));

		//Area of the incircle of the triangle
		in_radius = violets_A / sem_perim;
		roses_A = PI * in_radius * in_radius;

		//Area of the circumcircle
		out_radius = (a * b * c) / (4 * violets_A);
		sunflower_A = (PI * out_radius * out_radius) - violets_A;

		//Area of triangle without incircle
		violets_A -= roses_A;

		cout << sunflower_A << " " << violets_A << " " << roses_A << endl;

	}

	return 0;
}



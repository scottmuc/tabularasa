
/*****************************************************************

COPYRIGHT (C):    1999, All Rights Reserved. 
PROJECT:          Assignemnt #3
FILE:             assign.cpp
PURPOSE:          draws a Sierpinski Gasket on the screen
COMPILER:         Borland C++ 5.02
TARGET:           IBM PC/DOS
PROGRAMMER:       Scott Muc (55600-4787)
START DATE:   October 13 '99

*****************************************************************/

/* NOTES ********************************************************* 

	This program builds a Sierpinski Gasket using the mathematical
algorithm given with the assignment. I have seeded the random number
generator to prove that this formula works for any random choices and that
I didn't just save my program when the output looked the best.

EXTRA FEATURE

	The extra feature I have put in this program is a test for the area of
the triangle made by the 3 points inputed by the user. This makes sure a
decent sized triangle is made so that a good Sierpinski Gasket is made. By
keeping the coordinate system small in this program, it removes the chances
that someone will make a very long, thin triangle that could have an area
large enough to pass the test.
	To figure out the dimensions of the triangle, I have made a function that
computes the difference between the largest and smallest of a 3 number series.
This calculates the dimensions of the triangle so they can be applied to the
simple calculation of area ( length * width * 1/2 ).
	I have added the function that computes the area of a triangle for the
purpose of future expansion. For example, a user may want the program to be
alter so it displays multiple Sierpinski Gaskets, now the modifier/programmer
can just make a quick call to the area function.


*****************************************************************/ 


/* INCLUDE ******************************************************/

#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
#include "f:\ccc\cccfiles\ccc_win.cpp"


/* GLOBALS ******************************************************/


/* FUNCTIONS ****************************************************/

void rand_seed()
/* PURPOSE: Set the seed of the random number generator
*/
{	int seed = static_cast<int>(time(0));
   srand(seed);
}

int rand_int(int low, int high)
/* PURPOSE : Return a random integer in a range
	RECEIVES: a-the bottom of the range
   			 b-the top of the range
   RETURNS : A random number x, a <= x and x <= b
*/
{	return low + rand() % (high - low + 1);
}

Point midpoint(Point p1, Point p2)
/*	PURPOSE : Return the midpoint of two points
	RECEIVES: p1 and p2, the two points
   RETURNS : A point value that is the midpoint of p1 and p2
*/
{	Point mid = Point(((p1.get_x() + p2.get_x()) / 2 ), ((p1.get_y() + p2.get_y()) / 2 ));
      return mid;
}

double max_minus_min(double a, double b, double c)
/*	PURPOSE : To determine the difference between the max and min value of 3 numbers
	RECEIVES: a,b,c
   REMARKS : This function can only be used with 3 numbers
   RETURNS : 1 double figure that is the difference between the max and min of a series
*/
{  double min, max;

	if ( a > b && c)
		 max = a;
   if ( b > c)
   	 min = c;
   else
   	 min = b;

   if ( b > a && c)
   	 max = b;
   if ( a > c)
   	 min = c;
   else
   	 min = a;

   if ( c > a && b)
   	 max = c;
   if ( a > b)
   	 min = b;
   else
   	 min = a;

   double length = max - min;
   return length;
}

double area(double l, double w)
/*	PURPOSE  :	Computes the area of a triangle
   RECEIVES :	l - length of triangle
   				w - width of triangle
   RETURNS	: 	a double that is the area of the triangle
*/
{	double a = l * w * 0.5;
	return a;
}


int main()
{  //
	// getting the points of the triangle from the user
   //
   Point mot(-10, 8);
   Message motive(mot, "This program will make a Sierpinski gadget; Please click on 3 different points");
   cwin << motive;

   Point A1 = cwin.get_mouse("Click at desired point 'A'");
   cwin << A1;

   Point B1 = cwin.get_mouse("Click at desired point 'B'");
   cwin << B1;

   Point C1 = cwin.get_mouse("Click at desired point 'C'");
   cwin << C1;
   //
   // getting the x values of each point.
   //
   double x1 = A1.get_x();
   double x2 = B1.get_x();
   double x3 = C1.get_x();
   //
   // getting the y values of each point.
   //
   double y1 = A1.get_y();
   double y2 = B1.get_y();
   double y3 = C1.get_y();
   //
   // calling the function max_minus_min to calculate the
   // dimensions of the triangle.
   //
   double width  = max_minus_min(x1, x2, x3);
   double height = max_minus_min(y1, y2, y3);
   //
   // this is a test to make sure the triangle is of a decent size so
   // the demonstration has its full affect. Also eliminates non triangle input.
   //
   double a = area(height, width);
   if ( a < 25)
   	{	Point m(-1, 7);
      	Message err(m, "Please make a larger triangle");
         cwin << err;
      	return 1;
      }

   Point M = midpoint(A1, B1);
   cwin << M;
   //
   // this plots 10000 points in the triangle.
   //
   for ( int count = 0; count < 10000; count++)
   {	Point X;
   	int x = rand_int(1, 3);
   	if ( x == 1)
    		X = A1;
   	if ( x == 2)
    		X = B1;
   	if ( x == 3)
    		X = C1;

   	M = midpoint(M, X);
   	cwin << M;
   }


return 0;
}

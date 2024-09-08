
/*****************************************************************

COPYRIGHT (C):    1999, All Rights Reserved. 
PROJECT:          Assignment #1
FILE:             assign1.cpp
PURPOSE:          To solve a linear equation problem
COMPILER:         Borland C++ 5.02
TARGET:           IBM PC/DOS
PROGRAMMER:       Scott Muc (55600-4878)
START DATE:   		September 16, 1999

*****************************************************************/

/* NOTES *********************************************************

	This C++ program will calculate the values of two unknowns in
a problem. This is done using a basic mathematical problem solving
formula using two linear equations.

*****************************************************************/

/* INCLUDE ******************************************************/

#include <iostream>
#include <conio>    // needed for the getch function.

/* CLASSES ******************************************************/


/* GLOBALS ******************************************************/

//using namespace std;

double a, b, c, d, e, f;
double X, Y;

/* FUNCTIONS ****************************************************/


int main()
{	for ( int count = 1; count < 6; count++)

      {

   	cout << "Example #" << count << "\n\n";

      cout << "Please enter 'a' through 'f'\n";

      // this is where we enter out input
      cin  >> a, cin >> b, cin >> c, cin >> d, cin >> e, cin >> f;

            // this displays what the expressions look like
      cout << a << "X" << " + " << b << "Y" << " = " << c << "\n";
      cout << d << "X" << " + " << e << "Y" << " = " << f << "\n\n";


      // this tests whether the demoninator is 0
      if ( a * e == b * d )
      	{	cout << "The equations don't have a unique solution.\n\n";
         }
      else
      // this calculates X and Y
      	{	X = ( c * e - b * f ) / ( a * e - b * d );
         	Y = ( c * d - a * f ) / ( b * d - a * e );
            cout << "X = " << X << "  Y = " << Y << "\n\n";
         }


      if ( count == 5 )
      	{ 	cout << "You have reached the end of assignment #1 !!!\n";
         	int end = getch(); // needed to declare a value for getch
            						 // even though it is not used.
         }
      else
         // this allows for a pause between examples
         {	cout << "Press any key to see the next example.\n\n";
      		int cont = getch();
         }

      }
   return 0;
}

/* Output ********************************************************************

Example #1

Please enter 'a' through 'f'
1 1 5 10 5 40
1X + 1Y = 5
10X + 5Y = 40

X = 3  Y = 2

Press any key to see the next example.

Example #2

Please enter 'a' through 'f'
 1.43 -41 50034 120 0.335 40
1.43X + -41Y = 50034
120X + 0.335Y = 40

X = 3.73976  Y = -1220.21

Press any key to see the next example.

Example #3

Please enter 'a' through 'f'
22 0 4.07 120 0.335 81
22X + 0Y = 4.07
120X + 0.335Y = 81

X = 0.185  Y = 175.522

Press any key to see the next example.

Example #4

Please enter 'a' through 'f'
 0 0 0 0 0 0
0X + 0Y = 0
0X + 0Y = 0

The equations don't have a unique solution.

Press any key to see the next example.

Example #5

Please enter 'a' through 'f'
 3 9 4 2 6 34
3X + 9Y = 4
2X + 6Y = 34

The equations don't have a unique solution.

You have reached the end of assignment #1 !!!

 */



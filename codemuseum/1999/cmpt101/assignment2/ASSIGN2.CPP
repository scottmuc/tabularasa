/*****************************************************************

COPYRIGHT (C):    1999, All Rights Reserved.
PROJECT:          Assignment #2 CMPT-101 D2
FILE:             assign2.cpp
PURPOSE:          To print out the full date from 2 input statements.
COMPILER:         Borland C++ 5.02
TARGET:           IBM PC/DOS
PROGRAMMER:       Scott Muc (55600-4787)
START DATE:   		September 26, 1999

*****************************************************************/


/* NOTES *********************************************************

	This first part of the code is just basic user input and testing
of the input for validity. Next are two 'if'/'else' loops for each
year structure (leap/regular).


*****************************************************************/


/* INCLUDE ******************************************************/

#include <iostream>
#include <string>
#include <conio>

/* CLASSES ******************************************************/

using namespace std;

/* GLOBALS ******************************************************/

int year, day, day_of_month, cont;
string month_name, day_of_week;
string m = "Monday", t = "Tuesday", w = "Wednesday", th = "Thursday"
		 , f = "Friday", sat = "Saturday", sun = "Sunday";

/* FUNCTIONS ****************************************************/


int main()
{
   // input for year, and testing the year.
	cout << "Please enter a year : ";
	cin  >> year; cout << "\n";
   if (cin.fail())
   		{	cout << "Please enter a numerical value.\n";
            cout << "Press any key to exit";
      	   cont = getch();
            return 1;
         }
   if (year <= 0)
        	{	cout << "Please enter a number greater than zero.\n";
            cout << "Press any key to exit";
            cont = getch();
         	return 1;
   		}

   // input for day, and testing the day
   cout << "Please enter day    : ";
   cin  >> day; cout << "\n";
   if (cin.fail())
   		{	cout << "Please enter a numerical value.\n";
            cout << "Press any key to exit";
      	   cont = getch();
         	return 1;
   		}
   if (day <= 0)
         {	cout << "Please enter a number greater than zero.\n";
            cout << "Press any key to exit";
      	   cont = getch();
         	return 1;
         }

   // this 'if' tests if the year is not a leap year.
   if ((year % 100) != 0 || (year % 400) != 0)
         {  if (day > 365)
         		{  // this is an error message for entering too many days
               	cout << "There aren't that many days in that year.\n";
                  cout << "Press any key to exit";
      			   cont = getch();
               	return 1;
               }
            int x;
   			x = day - ((day / 7) * 7 );

            int y;
   			y = year - ((year / 28) * 28 )  ;

   			if ((y == 1) || (y == 7) || (y == 18))
   			{	if (x == 1)
      				day_of_week = sun;
      			if (x == 2)
      				day_of_week = m;
      			if (x == 3)
      				day_of_week = t;
      			if (x == 4)
      				day_of_week = w;
      			if (x == 5)
      				day_of_week = th;
      			if (x == 6)
      				day_of_week = f;
      			if (x == 0)
      				day_of_week = sat;
      		}

   			if ((y == 2) || (y == 13) || (y == 19))
   			{	if (x == 1)
      				day_of_week = m;
      			if (x == 2)
      				day_of_week = t;
      			if (x == 3)
      				day_of_week = w;
      			if (x == 4)
      				day_of_week = th;
      			if (x == 5)
      				day_of_week = f;
      			if (x == 6)
      				day_of_week = sat;
      			if (x == 0)
      				day_of_week = sun;
      		}

   			if ((y == 3) || (y == 14) || (y == 25))
   			{	if (x == 1)
      				day_of_week = t;
      			if (x == 2)
      				day_of_week = w;
      			if (x == 3)
      				day_of_week = th;
      			if (x == 4)
      				day_of_week = f;
      			if (x == 5)
      				day_of_week = sat;
      			if (x == 6)
      				day_of_week = sun;
      			if (x == 0)
      				day_of_week = m;
      		}

   			if ((y == 9) || (y == 15) || (y == 26))
      		{	if (x == 1)
      				day_of_week = w;
      			if (x == 2)
      				day_of_week = th;
      			if (x == 3)
      				day_of_week = f;
      			if (x == 4)
               	day_of_week = sat;
      			if (x == 5)
      				day_of_week = sun;
      			if (x == 6)
      				day_of_week = m;
      			if (x == 0)
      				day_of_week = t;
      		}

   			if ((y == 10) || (y == 21) || (y == 27))
      		{	if (x == 1)
      				day_of_week = th;
      			if (x == 2)
      				day_of_week = f;
      			if (x == 3)
      				day_of_week = sat;
      			if (x == 4)
      				day_of_week = sun;
      			if (x == 5)
      				day_of_week = m;
      			if (x == 6)
      				day_of_week = t;
      			if (x == 0)
      				day_of_week = w;
      		}

   			if ((y == 5) || (y == 11) || (y == 22))
      		{	if (x == 1)
      				day_of_week = f;
      			if (x == 2)
      				day_of_week = sat;
      			if (x == 3)
      				day_of_week = sun;
      			if (x == 4)
      				day_of_week = m;
      			if (x == 5)
      				day_of_week = t;
      			if (x == 6)
      				day_of_week = w;
      			if (x == 0)
      				day_of_week = th;
      		}

   			if ((y == 6) || (y == 17) || (y == 23))
      		{	if (x == 1)
      				day_of_week = sat;
      			if (x == 2)
      				day_of_week = sun;
      			if (x == 3)
      				day_of_week = m;
      			if (x == 4)
      				day_of_week = t;
      			if (x == 5)
      				day_of_week = w;
      			if (x == 6)
      				day_of_week = th;
      		  	if (x == 0)
      				day_of_week = f;
      		}


            if (day < 32)
      			{	month_name = "January";
         			day_of_month = day;
               }
            else if (day < 60)
         		{	month_name = "Febuary";
                 	day_of_month = day - 31;
               }
            else if (day < 91)
               {	month_name = "March";
               	day_of_month = day - 59;
               }
            else if (day < 121)
         		{	month_name = "April";
         			day_of_month = day - 90;
               }
            else if (day < 152)
         		{	month_name = "May";
         			day_of_month = day - 120;
               }
            else if (day < 182)
         		{	month_name = "June";
         			day_of_month = day - 151;
               }
            else if (day < 213)
         		{	month_name = "July";
         			day_of_month = day - 181;
               }
            else if (day < 244)
         		{	month_name = "August";
         			day_of_month = day - 212;
               }
            else if (day < 274)
         		{	month_name = "September";
         			day_of_month = day - 243;
               }
            else if (day < 305)
         		{	month_name = "October";
         			day_of_month = day - 273;
               }
            else if (day < 335)
         		{	month_name = "November";
               	day_of_month = day - 304;
               }
            else
            	{	month_name = "December";
               	day_of_month = day - 334;
         		}
         }  // this bracket nests the first 'if'/'else' loop

            // this 'if' tests for leap years.
    if  ((year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0)
         {  if (day < 366)
         			{	cout << "There aren't that many days in that year!\n";
            			cout << "Press any key to exit";
      			   	cont = getch();
               		return 1;
                  }

         	cout << "it's a leap year\n\n";
            int x;
   			x = day - ((day / 7) * 7 );

				if (((year / 4) % 7) == 0)
      		{	if (x == 1)
      				day_of_week = f;
      			if (x == 2)
      				day_of_week = sat;
      			if (x == 3)
      				day_of_week = sun;
      			if (x == 4)
      				day_of_week = m;
      			if (x == 5)
      				day_of_week = t;
      			if (x == 6)
      				day_of_week = w;
      			if (x == 0)
      				day_of_week = th;
     			 }

   			if (((year / 4) % 7) == 1)
      		{	if (x == 1)
      				day_of_week = w;
      			if (x == 2)
      				day_of_week = th;
            	if (x == 3)
      				day_of_week = f;
      			if (x == 4)
      				day_of_week = sat;
      			if (x == 5)
      				day_of_week = sun;
      			if (x == 6)
      				day_of_week = m;
      			if (x == 0)
      				day_of_week = t;
     			 }

   			if (((year / 4) % 7) == 2)
            {	if (x == 1)
      				day_of_week = m;
      			if (x == 2)
      				day_of_week = t;
      			if (x == 3)
      				day_of_week = w;
      			if (x == 4)
      				day_of_week = th;
      			if (x == 5)
      				day_of_week = f;
      			if (x == 6)
      				day_of_week = sat;
      			if (x == 0)
      				day_of_week = sun;
      		}

   			if (((year / 4) % 7) == 3)
      		{	if (x == 1)
      				day_of_week = sat;
      			if (x == 2)
      				day_of_week = sun;
      			if (x == 3)
      				day_of_week = m;
      			if (x == 4)
      				day_of_week = t;
               if (x == 5)
      				day_of_week = w;
      			if (x == 6)
      				day_of_week = th;
      			if (x == 0)
      				day_of_week = f;
      		}

   			if (((year / 4) % 7) == 4)
      		{	if (x == 1)
      				day_of_week = th;
      			if (x == 2)
      				day_of_week = f;
      			if (x == 3)
      				day_of_week = sat;
      			if (x == 4)
      				day_of_week = sun;
      			if (x == 5)
      				day_of_week = m;
      			if (x == 6)
      				day_of_week = t;
      			if (x == 0)
      				day_of_week = w;
      		}

      		if (((year / 4) % 7) == 5)
   			{	if (x == 1)
      				day_of_week = t;
      			if (x == 2)
      				day_of_week = w;
      			if (x == 3)
      				day_of_week = th;
      			if (x == 4)
      				day_of_week = f;
      			if (x == 5)
      				day_of_week = sat;
      			if (x == 6)
      				day_of_week = sun;
      			if (x == 0)
      				day_of_week = m;
      		}

      		if (((year / 4) % 7) == 6)
      		{	if (x == 1)
      				day_of_week = sun;
      			if (x == 2)
      				day_of_week = m;
      			if (x == 3)
      				day_of_week = t;
      			if (x == 4)
      				day_of_week = w;
      			if (x == 5)
      				day_of_week = th;
      			if (x == 6)
      				day_of_week = f;
      			if (x == 0)
      				day_of_week = sat;
      		}



         	{ if (day < 32)
      			{	month_name = "January";
         			day_of_month = day;
               }
            else if (day < 61)
         		{	month_name = "Febuary";
         			day_of_month = day - 31;
               }
            else if (day < 92)
         		{	month_name = "March";
         			day_of_month = day - 60;
               }
            else if (day < 122)
         		{	month_name = "April";
         			day_of_month = day - 91;
               }
            else if (day < 153)
         		{	month_name = "May";
         			day_of_month = day - 121;
               }
            else if (day < 183)
         		{	month_name = "June";
         			day_of_month = day - 152;
               }
            else if (day < 214)
         		{	month_name = "July";
         			day_of_month = day - 182;
               }
            else if (day < 245)
         		{	month_name = "August";
         			day_of_month = day - 213;
               }
            else if (day < 275)
         		{	month_name = "September";
         			day_of_month = day - 244;
               }
            else if (day < 306)
         		{	month_name = "October";
         			day_of_month = day - 274;
               }
            else if (day < 336)
               {	month_name = "November";
         			day_of_month = day - 305;
               }
            else
            	{	month_name = "December";
         			day_of_month = day - 335;
               }
           	}
         }


         cout << "(" << year << ", " << day << ") is, " << day_of_week << " " <<
              month_name << " " << day_of_month << ", " << year << ".\n";
        // this allows for a pause between examples
         {	cout << "Press any key to exit";
      	   cont = getch();
         }


return 0;
}

/* OUTPUT *********************************************************************

EXAMPLE 1

Please enter a year : 1999

Please enter day    : 275

(1999, 275) is, October 2, 1999.
Press any key to exit

EXAMPLE 2

Please enter a year : 1900

Please enter day    : 60

(1900, 60) is, March 1, 1900.
Press any key to exit

EXAMPLE 3

Please enter a year : 1632

Please enter day    : 60

it's a leap year

(1632, 60) is, Febuary 29, 1632.
Press any key to exit

EXAMPLE 4

Please enter a year : -1935

Please enter a number greater than zero.
Press any key to exit

EXAMPLE 5

Please enter a year : 2100

Please enter day    : 366

There aren't that many days in that year.
Press any key to exit

EXAMPLE 6

Please enter a year : thisyear

Please enter a numerical value.
Press any key to exit

EXAMPLE 7

Please enter a year : 5734

Please enter day    : sixteen

Please enter a numerical value.
Press any key to exit

*/

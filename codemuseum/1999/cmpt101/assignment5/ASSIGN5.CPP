
/*****************************************************************

COPYRIGHT (C):    1999, All Rights Reserved. 
PROJECT:          Assignment #5
FILE:             Assign5.cpp
							|- date.txt (input)
                     |- sortdate.txt (output)
PURPOSE:          Sorts dates into chronological order
COMPILER:         Borland C++ 5.02
TARGET:           IBM PC/DOS
PROGRAMMER:       Scott A. Muc ( 55600 - 4787 )
START DATE:   November 23, 1999

*****************************************************************/


/* NOTES *********************************************************

	Credit goes to Cay Horstman for the selection sort algorithm taken
from Chapter 12 (p.509) of Computing Concepts With C++ Essentials.
	This program will take an input file with an assortment of different
dates and will sort them and print the sorted dates into a seperate output
file, namely sortdate.txt in this program.

*****************************************************************/ 


/* INCLUDE ******************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

/* CLASSES ******************************************************/

class Date
{
public:
   Date(); // default constructor

   Date(string m, int d, int y); // constructor
   /* PURPOSE  : To construct a Date object
      RECEIVES : string m - a month value
      			  int d and y - the numerical values day and year
   */
	string get_month() const; // accessor
   /* PURPOSE	: To access the month
   	RETURNS  : The month of Date
   */
   int get_day() const; // accessor
   /*	PURPOSE	: To access the day
   	RETURNS	: The day of Date
   */
   int get_year() const;// accessor
   /*	PURPOSE	: To access the year
   	RETURNS	: The year of Date
   */
private:
	string month;
   int day;
   int year;
};

/* GLOBALS ******************************************************/


/* FUNCTIONS ****************************************************/

Date::Date()
{  day = 0;
   year = 0;
}

Date::Date(string m, int d, int y)
{	month = m;
	day = d;
   year = y;
}

string Date::get_month() const
{ 	return month;
}

int Date::get_year() const
{	return year;
}

int Date::get_day() const
{ return day;
}

int month_value(string month)
/*	PURPOSE  : To give a month a numerical value
	RECEIVES : The month as a string from Date
   RETURNS	: A number that represents the order of the month
*/
{	if (month == "January")
		return 1;
	if (month == "Febuary")
		return 2;
	if (month == "March")
		return 3;
	if (month == "April")
		return 4;
	if (month == "May")
		return 5;
	if (month == "June")
		return 6;
	if (month == "July")
		return 7;
	if (month == "August")
		return 8;
	if (month == "September")
		return 9;
	if (month == "October")
		return 10;
   if (month == "November")
		return 11;
	if (month == "December")
		return 12;
}

int min_year(vector<Date>& a, int from, int to)
/*	PURPOSE	: Finds the minimum year in a vector of Dates
	RECEIVES : a - a vector of Date objects
   RETURNS	: An integer that represents the location of the minimum year in
   	        the vector Date
*/
{  int min_year = from;
	int i;
   for (i = from + 1; i <= to; i++)
   	{	if (a[i].get_year() < a[min_year].get_year())
      		min_year = i;
      }
   return min_year;
}

void print_to_file(vector<Date> a)
/*	PURPOSE	: To store the sorted data into a file
	RECEIVES : The sorted vector of dates
*/
{  ofstream output_data;
	output_data.open("sortdate.txt");

	int i;
	for ( i = 0; i < a.size(); i++)
   	output_data <<  a[i].get_month() << " " << a[i].get_day() << " "
       << a[i].get_year() << "\n";
}

void swap(Date& a, Date& b)
/* PURPOSE	: Swaps Date positions
	RECEIVES : Two Date objects to be swapped
*/
{
	Date temp = a;
	a = b;
   b = temp;
}

void min_month(Date& a, Date& b)
/*	PURPOSE	: Find the minimum month if years are the same, and swaps them if
				  one is before the other
	RECEIVES : Two Dates to be compared
   NOTES		: This function is only accessed if the years are the same
*/
{	if ( month_value(a.get_month()) > month_value(b.get_month()))
		swap(a, b);
}

void min_day(Date& a, Date& b)
/*	PURPOSE  : Find the minimum day if the years and the months are the same
				  between two Date objects, and it will swap two Dates if one day
              comes before the other.
	RECEIVES : Two Date objects to be compared
*/
{	if ( a.get_day() > b.get_day())
		swap(a, b);
}

void selection_sort(vector<Date>& a)
/* PURPOSE	: To sort a vector of Date objects into chronological order
	RECEIVES : a Date vector
   NOTES		: This function first compares the year, month, then day and rearanges
   			  the object so they are printed in order.
*/
{	int next;
	for (next = 0; next < a.size() - 1 ; next++)
   {	int min_pos = min_year(a, next, a.size() - 1);
   	if (min_pos != next)
      	swap(a[min_pos], a[next]);
   }
   for (next = 0; next < a.size() - 1 ; next++)
   {	if (a[next].get_year() == a[next + 1].get_year())
   		min_month(a[next], a[next + 1]);
   }
   for (next = 0; next < a.size() - 1 ; next++)
   {	if	(a[next].get_year() == a[next + 1].get_year())
      	if (a[next].get_month() == a[next + 1].get_month())
          min_day(a[next], a[next + 1]);
   }

}

int main()
{  //
	// opening the input stream
   //
	ifstream input_data;
	input_data.open("date.txt");

	vector<Date> d;

   bool more = true;
   //
   //	this reads all the data into the vector
   //
   while (more)
   {
   	string a;
		int b, c;
		input_data >> a >> b >> c;

   	Date x(a, b, c);
      d.push_back(x);

      if ( a == "" )
      {  d.pop_back(); // this removes the empty date object
      	more = false;
      }
   }

   selection_sort(d);
   print_to_file(d);

	return 0;
}

/* Misc, Bugs, Etc... *********************************************************

	Some drawbacks to this program is that the spelling of the months has to be
done perfect or else the program will crash. Also this program does not deal with
dates that are the same. Also the formatting could have been improved

*/


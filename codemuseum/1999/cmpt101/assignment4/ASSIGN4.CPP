
/*****************************************************************

COPYRIGHT (C):    1999, All Rights Reserved. 
PROJECT:          Assignment #4
FILE:             assign4.cpp
PURPOSE:          prints two paragraphs in column structure
COMPILER:         Borland C++ 5.02
TARGET:           IBM PC/DOS
PROGRAMMER:       Scott Muc ( 55600-4787 )
START DATE:   November 7, 1999

*****************************************************************/ 


/* NOTES ********************************************************* 

	This program receives two strings of user input in order to make
two adjacent columns of text. The user can enter whatever strings he/she
wants and can also determine the width of each column as well as the
spacing between them.

*****************************************************************/


/* INCLUDE ******************************************************/

#include <iostream>
#include <string>
#include <conio>

using namespace std;

/* CLASSES ******************************************************/

class Paragraph
{
public:
	Paragraph(string text, int width); // constructor
   /*
   	PURPOSE  : constructs a paragraph containing the given text, and the
      			  with the given width
      RECEIVES : text  - a string; every \n in text should be replaced by a space
      			  width - a positive number representing the maximum length of
                 			 any line in the paragraph
   */
   int width() const; // accessor
   /*
   	PURPOSE  : returns the width of this paragraph
      RETURNS  : the width of this paragraph
   */
   bool hasMoreLines(); // accessor
   /*
   	PURPOSE  : indicates if the paragraph has any more lines to return in calls
                 to nextLine()
      RETURNS  : true if a call to nextLine() will return a line in this paragraph;
      			  false if all the lines have been returned
      NOTE	   : once hasMoreLines() returns false, it will always return false;
                 there is no way to "reset" a paragraph object --- once they are
                 done they can't ne used anymore
   */
   string nextLine();
   /*
   	PURPOSE  : returns the next line of this paragraph
      RETURNS  : the next line of the text; this line is at most width() characters
      			  long; if hasMoreLines() is false, then an empty string is returned
   */
private:
   int wid_par;
   string para;
};

/* GLOBALS ******************************************************/


/* FUNCTIONS ****************************************************/

Paragraph::Paragraph(string text, int width)
{  para = text;
	wid_par = width;
}

int Paragraph::width() const
{	return wid_par;
}

bool Paragraph::hasMoreLines()
{  if (para.length() > 0)
   	return true;
   return false;
}

string Paragraph::nextLine()
{  int count = 1;
   //
   // this if statement tests whether a paragraph was set as an
   // empty string. It then prints the a width amount of spaces
   // to fill up the area where the paragraph would have been printed
   //
	if (para == "")
   	{	count = wid_par;
      	string spaces;
         for (int c = 0; c < count; c++)
      		spaces = spaces + " ";
         return spaces;
      }
   //
   // this if statement test whether a lines length is less than the
   // desired width. It then sets the text as an empty string so
   // hasMoreLines() will return false
   //
   if (para.length() <= wid_par)
      {  string spaces;
      	for (int c = 0; c < (wid_par - para.length()); c++)
         	spaces = spaces + " ";
      	string x = para.substr(0, para.length()) + spaces;
         para = "";
			return x;
      }
   //
   // this next segment is checking for a regular line structure
   //
   int length;

   bool is_char = true;
   while (is_char)
   	{  if (para.substr(wid_par - count, 1) == " ")
      		{	is_char = false;
         		break;
            }
         count++;

         if ((wid_par - count) == 0)
         	break;

      }
   length = wid_par - count;
   //
   // this segment tests for lines that contain one word, or a word larger
   // than the width
   //
   if (length == 0)
   	{     count = 0;
            is_char = true;
      	   while (is_char)
      		{  if ((wid_par + count) == para.length())
            		{	break;
                  }
            	if (para.substr(wid_par + count, 1) == " ")
               {	is_char = false;
               	break;
               }
            	count++;
            }
      length = wid_par + count;
      }
   //
   // this prints spaces after a line so that that the column is always
   // as wide as width
   //
   string spaces;
   	for (int c = 0; c < count; c++)
      	spaces = spaces + " ";

   string x = para.substr(0, length) + spaces; // this saves the string

   para = para.substr(length + 1, para.length()); /* this snips off the begining
   																  of para, creating a smaller,
                                                     unprinted string.
   															  */
   return x;

}

string left_justified(Paragraph p1, Paragraph p2, string space)
/*
	PURPOSE  : to left justify nextLine()
   RECEIVES : two paragraph objects and string of spaces.
   RETRUNS  : two columns of text with each line containing one line from each
              paragraph seperated by the space string
*/
{	string result;
   while (p1.hasMoreLines() || p2.hasMoreLines())
   	result = result + p1.nextLine() + space + p2.nextLine() + "\n";

   return result;
}

bool range_test(int min, int max, int testing)
/*
	PURPOSE  : tests if a given int is in range
   RECEIVES : min, max - range of test
   			  testing - the int the function tests
   RETURNS  : true if testing is out of range
   			  false if testing is in range
*/
{  if (testing > max || testing < min)
   	{	cout << "Please enter a better size, so the output looks neater.\n";
         return true;
      }
	return false;
}


Paragraph read_par()
/*
	PURPOSE  : to construct a paragraph object
   RETURNS  : a paragraph with the text entered and a given width
*/
{
	string text;
	int width;
   string remainder;
   //
   // used getline to receive an entire string with spaces
   //
   getline(cin, remainder, '\n');

	cout << "Please enter the text of your paragraph (press Enter when done)\n";
	getline(cin, text, '\n');
   cout << "\nPlease enter width of column ( between 10 - 30) (press Enter when done)\n";
   cin >> width;
   const int WIDTH_MIN = 10;
   const int WIDTH_MAX = 30;

   while (range_test(WIDTH_MIN, WIDTH_MAX, width))
   {  cout << "\nPlease enter width of column ( between 10 - 30) (press Enter when done)\n";
   	cin >> width;
   }

   Paragraph x(text, width);

   return x;
}



string two_columns(Paragraph p1, Paragraph p2, int space)
/*
	PURPOSE  : to uses left_justified to make two columns of text
   RECEIVES : p1,p2 - the two paragraphs to be printed in columns
   			  spaces - the desired space between columns
   RETURNS  : a string that is constructed so that it prints out two
              adjacent columns
*/
{  string s;
   for (int count = 0; count < space; count++)
   	s = s + " ";
   string x = left_justified(p1, p2, s);

   return x;
}


int main()
{  const int SPACE_MIN = 3;
	const int SPACE_MAX = 15;

	cout << "Hello and welcome to Scott Muc's paragraph to column conversion machine.\n"
		  << "This program will ask you to write down to paragraphs, and it will ask you\n"
        << "how wide you want your columns and the space between the columns. For the\n"
        << "program to run as desired, please enter values within reason or else you will\n"
        << "just get an error message and the program will terminate.\n\n";


   cout << "How many spaces would you like between your columns? ( between 3 - 15 )" << endl;
   int spaces;
   cin >> spaces;

   while (range_test(SPACE_MIN, SPACE_MAX, spaces))
   {	cout << "How many spaces would you like between your columns? ( between 3 - 15 )" << endl;
   	cin >> spaces;
   }

   Paragraph x = read_par();
   Paragraph y = read_par();

   cout << two_columns(x, y, spaces) << "\n";
   int exit;
   cout << "Press any key to exit\n";
   exit = getch();
	return 0;
}

/* BUS, LIMITATIONS, EXTRA FEATURES ************************************************

	So far there aren't any known bugs. Some of the limitations are : It can only print
two columns wide. This could be altered by a programmer to create another function
where the user could enter desired amount of columns. It can't handle large words if
the column width is small ( it handles it, but the output is ugly ), the is program
could be modified so that words ar cut and one fragment ends a line and the second
fragment starts the next line ie...

Computer Sci-
ence is the
coolest clas-
s in the wor-
ld.

	I also did not need the width() member function... The only times I needed the
width of the paragraph were in the member functions so the width was accessed using
the private variable 'wid_par'.
	Another useful feature would have been to allow the input using file streams.
That way someone could see all kinds of outputs without having to rewrite the
paragraphs all over again.
	Also, since I modified 'para' after each call to nextLine() it makes it impossible
to access the original string 'text'. Therefore this program can only print the
paragraph once.


/* OUTPUT **************************************************************************

Trial 1

Hello and welcome to Scott Muc's paragraph to column conversion machine.
This program will ask you to write down to paragraphs, and it will ask you
how wide you want your columns and the space between the columns. For the
program to run as desired, please enter values within reason or else you will
just get an error message and the program will terminate.

How many spaces would you like between your columns? ( between 3 - 15 )
10
Please enter the text of your paragraph (press Enter when done)
The art of card palming can be brought to a degree of perfection that borders on
 the wonderful. It is very simple to place one or several cards in the palm and
concealing them.

Please enter width of column ( between 10 - 30) (press Enter when done)
20
Please enter the text of your paragraph (press Enter when done)
Excessive vanity proves the undoin of many experts. The temptation to show off i
s great.

Please enter width of column ( between 10 - 30) (press Enter when done)
20
The art of card               Excessive vanity
palming can be                proves the undoin
brought to a degree           of many experts.
of perfection that            The temptation to
borders on the                show off is great.
wonderful. It is
very simple to
place one or
several cards in
the palm and
concealing them.

Press any key to exit

Trial 2

Hello and welcome to Scott Muc's paragraph to column conversion machine.
This program will ask you to write down to paragraphs, and it will ask you
how wide you want your columns and the space between the columns. For the
program to run as desired, please enter values within reason or else you will
just get an error message and the program will terminate.

How many spaces would you like between your columns? ( between 3 - 15 )
5
Please enter the text of your paragraph (press Enter when done)
This trial is showing two paragraphs with different widths. I will make the firs
t one of a width 30, while I will make the second one width 10.

Please enter width of column ( between 10 - 30) (press Enter when done)
30
Please enter the text of your paragraph (press Enter when done)
This is the second paragraph, which I am going to make the width 10.

Please enter width of column ( between 10 - 30) (press Enter when done)
10
This trial is showing two          This is
paragraphs with different          the
widths. I will make the first      second
one of a width 30, while I         paragraph,
will make the second one           which I
width 10.                          am going
                                   to make
                                   the width
                                   10.

Press any key to exit

Trial 3

Hello and welcome to Scott Muc's paragraph to column conversion machine.
This program will ask you to write down to paragraphs, and it will ask you
how wide you want your columns and the space between the columns. For the
program to run as desired, please enter values within reason or else you will
just get an error message and the program will terminate.

How many spaces would you like between your columns? ( between 3 - 15 )
10
Please enter the text of your paragraph (press Enter when done)


Please enter width of column ( between 10 - 30) (press Enter when done)
10
Please enter the text of your paragraph (press Enter when done)
This example I made an empty string for my first paragraph. Since I still chose
a width of 10 for it, my second paragraph should be indented 20 spaces.

Please enter width of column ( between 10 - 30) (press Enter when done)
20
                    This example I made
                    an empty string for
                    my first paragraph.
                    Since I still chose
                    a width of 10 for
                    it, my second
                    paragraph should be
                    indented 20 spaces.

Press any key to exit

Trial 4

Hello and welcome to Scott Muc's paragraph to column conversion machine.
This program will ask you to write down to paragraphs, and it will ask you
how wide you want your columns and the space between the columns. For the
program to run as desired, please enter values within reason or else you will
just get an error message and the program will terminate.

How many spaces would you like between your columns? ( between 3 - 15 )
10
Please enter the text of your paragraph (press Enter when done)
Thislineisgoingtobetolong.

Please enter width of column ( between 10 - 30) (press Enter when done)
10
Please enter the text of your paragraph (press Enter when done)
See what I mean.

Please enter width of column ( between 10 - 30) (press Enter when done)
15
Thislineisgoingtobetolong.                          See what I
                    mean.

Press any key to exit
*/


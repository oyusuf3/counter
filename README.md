# counter
Part 1
Counter class
The Counter class implements increment operators, such as ++x and x++.  The class stores a single int variable.  The following UML diagram describes the class.

Class Counter

+Counter()

A constructor that initializes a Counter object to the value zero

+Counter(int)

A constructor that initializes a Counter object to the value of the argument passed in.

+getCount():int

Returns the current value of the int stored in a Counter object

+operator++():Counter

Overloads the ++ operator to perform a pre-increment operation, adding one to the current Counter value before using the value in the expression.

+operator++(int):Counter

Overloads the ++ operator to perform a post-increment operation, adding one to the Counter value after using the current value in the expression.

 

Variables of type Counter will have the following properties:

Counter c1; // c1 is initialized to 0 
c1++;       // c1 value is now 1
++c1;       // c1 value is now 2
Counter c2; // c2 is initialized to 0
c2 = c1++;  // c2 is 2, c1 is now 3
c2 = ++c1;  // c2 is 4, c1 is now 4
Note:  This class can’t do use these expressions for math operations such as:  ++x + y++.  Counter type variables have not defined addition between objects.

Code Organization
A first implementation will be called p4.cpp.  The file structure should be in the order:

A comment section that includes the program name, a description (one sentence), your name, the course, and the date.
(#) Statements for libraries and namespace:
#include <iostream>
using namespace std;
(A) The Counter class interface definitions containing no implementation of methods (in other words, Counter has no inline functions).
(B) The Counter class implementation details.
(C) A main() function for testing the Counter class.
 

Implementation of the Counter class
Functions defined outside of the class require the scope resolution operator which is inserted just before the function name (that is, after the return type).  Example:

Counter::Counter() {  // init statement(s)  }

 

The tester function main()
int  main() {
  Counter c1, c2;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  ++c1;
  for(int i =0; i < 100; ++i)
     ++c2;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  c1++;
  c2++;
  cout << "c1:" << c1.getCount() << ", "
       << "c2:" << c2.getCount() << endl;

  Counter c3;
  Counter c4(2);
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  c3 = c4++;
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  c3 = ++c4;
  cout << "c3:" << c3.getCount() << ", "
       << "c4:" << c4.getCount() << endl;

  return 0;
}
To compile the file, use the command:  g++ -Wall -std=c++11 p4.cpp

To run the program, type: a.out.  See Part 2 for the expected output.

 

Deliverable
       Upload p4.cpp to Gradescope.

Part 2
A class developed and coded into separate files is a software component that can be used again in several different programs.  This reduces cost because the class doesn’t need to be redesigned, recoded, and retested for every application. It also increases reliability for two reasons:  you might spend more effort developing a component if it is to be reused, and each time it is reused the component gets retested.

We will separate p4.cpp into three files related to:

(A) the interface called counter.h

(B)  the implementation called counter.cpp

(C) the test application component testcounter.cpp

[I recommend that you get the program working correctly in one file before separating it. ]

 

Converting into three files
counter.cpp and testcounter.cpp:  

These need the directive for the interface,

#include "counter.h"

These files will also have

using namespace std;

and testcounter.cpp will need the library to use cout:

#include <iostream>

counter.h:     

C++ does not allow redefinition of a class. To avoid including the definition of class Counter more than once,  the header interface file needs (rather strange looking) but intuitive directives.

 

#ifndef COUNTER_H       // If stuff in this file is not defined yet
#define COUNTER_H       // then define it beginning here.

class Counter { … };    // The class definition goes here,

#endif                  // and the definition ends here.
 

When you have separated the files, compile them using the command: 

g++ -Wall -std=c++11 counter.cpp testcounter.cpp

This will produce an a.out executable file.  The output should be:

c1:0, c2:0
c1:1, c2:100
c1:2, c2:101
c3:0, c4:2
c3:2, c4:3
c3:4, c4:4

Makefile
The class component can be compiled separately from the application (test component).  A command:

g++ -c counter.cpp

will produce relocatable counter.o. which can later be linked with the application:

g++ -o p4 testcounter.cpp counter.o

But that starts to get complicated.  A make utility is a convenient way to gather all the compile commands together.  This works from the command line.  Create a file called makefile with the following content.  Where indentation is needed, use a tab character.

 

# Makefile for P4 - CS 320 Fall 2021
# @author Patty Kraft
CC=g++
CFLAGS=-g -Wall -std=c++11

p4: testcounter.cpp counter.o
        $(CC) $(CFLAGS) -o p4 testcounter.cpp counter.o

counter.o: counter.cpp counter.h
        $(CC) $(CFLAGS) -c counter.cpp

clean:
        rm *.o p4

In class, we will go over what this means and how it works.  For now, create the file.  The make utility uses a file called “makefile” by default.  Then create the executable p4 by typing: 

              make

To remove the old files, type:

              make clean

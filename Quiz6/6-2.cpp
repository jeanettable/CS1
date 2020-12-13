//Program 6-2, by Jeanette Abell :)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

void genRandnum(int &, int &, int &);   //prototypes
int findMin(int, int, int);       
void printResults(int, int, int, int);

int main()  {

  int n1, n2, n3;
  int min;

  genRandnum(n1, n2, n3);
  min = findMin(n1, n2, n3);
  printResults(n1, n2, n3, min);

return 0;
}

/* **********************************************************************

FUNCTION DEFINITIONS:
genRandnum:
-takes three integer variables you wish to assign random numbers to
-void type, no return statement
-assign a random number between 0 and 500 to each variable provided in main

&findMin:
-takes three numbers to compare
-returns an integer value to min inside main
-creates reference inside to change min from inside function
-compares values, reassigns min

printResult:
-takes the three generated values, and the min value as arguments
-void type, no return statement
-displays what the user entered, and the minimum

*********************************************************************** */

void genRandnum(int &a, int &b, int &c) {
  
  unsigned seed = time(0);    //setup randomization
  srand(seed);

  a = rand() % 500;       //generate and assign to each reference var
  b = rand() % 500;       //will update passed in var in main ^
  c = rand() % 500;
}

int findMin(int a, int b, int c)  {
  int &min = a;    //defaults to setup for testing, points to min in main
  
  if (b < min)    //compare to second val
    min = b;
  
  if (c < min)   //compare to third val
    min = c;
  
  return min;  

}

void printResults(int n1, int n2, int n3, int min)  {
  cout << "Original list: " << setw(5) << n1 << setw(5) << n2 << setw(5) << n3 << endl << endl;
  cout << "The minimum is: " << setw(5) << min << endl;
}
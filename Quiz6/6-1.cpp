//Quiz 6-1, by Jeanette Abell :)
#include <iostream>
#include <iomanip>
using namespace std;

void getinput(int &, int &);                 //prototypes
void getinput(float &, float &);
void swapTwoValues(int &, int &);    
void swapTwoValues(float &, float &);

int main()  {
  float f1, f2;   //variables for float
  int i1, i2;     //variables for ints
  int type;       //to determine type

  do {      //input validation
    cout << "Will your values be decimals or integers?\n Enter 1 for integers,\n  Enter 2 for decimals: ";
    cin >> type;
  } while (type < 1 || type > 2); 

  switch(type)  {
    case 1:   //case of ints
    cout << "You chose integer values...\n\n";
    getinput(i1, i2);
    cout << "You entered: " << setw(6) << i1 << setw(6) << i2 << endl;
    swapTwoValues(i1, i2);
    cout << "Now swapped: " << setw(6) << i1 << setw(6) << i2 << endl;
    break;
    case 2:   //case of floats
    cout << "You chose decimal values...\n\n";
    getinput(f1, f2);
    cout << "You entered: " << setw(8) << f1 << setw(8) << f2 << endl;
    swapTwoValues(f1, f2);
    cout << "Now swapped: " << setw(8) << f1 << setw(8) << f2 << endl;
    break;
  }

return 0;
}

/* ********************************************************

getinput DEFINITION:
-void type, not return statement
-prompt user to enter two input values (type already decided in main)
-assign the input entered from function to parameters in main

********************************************************* */

void getinput(float &a, float &b)  {        //floats
  cout << "Enter two values you wish to swap: ";    
  cin >> a >> b;
}

void getinput(int &a, int &b)  {          //integers
  cout << "Enter two values you wish to swap: ";    
  cin >> a >> b;
}

/* ********************************************************

swapTwoValues DEFINITION:
-void type, no return statement
-create a temp var to hold original argument of one value
-rename the variables inside func, which also assigns them in main

********************************************************* */


void swapTwoValues(float &n1, float &n2)  {  //floats
  float temp = n1;
  n1 = n2;
  n2 = temp;
}

void swapTwoValues(int &n1, int &n2)  {     //integers
  int temp = n1;
  n1 = n2;
  n2 = temp;
}


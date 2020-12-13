#include <iostream>
using namespace std;

int main()  {

int selection;
cout << "Geometry Calculator: \n\n";
cout << "1. Calculate the area of a circle\n";
cout << "2. Calculate the area of a rectangle\n";
cout << "3. Calculate the area of a triangle\n";
cout << "4. Quit\n\n";
cout << "Enter your choice (1-4): \n\n";

cin >> selection;

if (selection == 1 || selection == 2 || selection == 3 || selection == 4)  {
  if ( selection == 1)  {
      float r = 0.0;
      cout << "Area = pi * r squared. Please enter a radius length:\n";
      cin >> r;
      if (r > 0)  {
      cout << "Area = " << (3.14159 * (r * r)) << endl;
      } else {
        cout << "Radius cannot be negative!" << endl;
      }
  } else if (selection == 2)  {
      float w, l;
      cout << "Area = length x width. Please enter width, then length:\n";
      cin >> w >> l;
      if (l > 0 && w > 0) {
      cout << "Area = " << (l * w) << endl;
      } else {
        cout << "Length and width cannot be negative!" << endl;
      }
    } else if (selection == 3)  {
      float b, h;
      cout << "Area = base x height x 0.5  Please enter base length, then height:\n";
      cin >> b >> h;
      if ( b > 0 && h > 0 ) {
      cout << "Area = " << (b * h * 0.5) << endl;
      } else {
        cout << "Base and height cannot be negative!" << endl;
      }
    } else  { //selection ==4
      cout << "Program quit." << endl;
    } 
} else {  //invalid user input
      cout << "Invalid user input.\nYou must enter a number 1-4.\n";
}

return 0; 

}
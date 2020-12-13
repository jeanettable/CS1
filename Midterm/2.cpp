//Midterm program 2 by Jeanette Abell
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()  {

  ifstream ifs;   //create reading object
  int i = 2;      //each student has 2 scores given
  string name;
  int sc1, sc2;
  int sum = 0;

  //open action
  ifs.open("Midterm/students.txt");   

  //verify the file is opened
  if (ifs.fail()) {
    cout << "Error upon open\n";
    exit(0);
  }

  //"while line has this following format"
  while ( ifs >> name >> sc1 >> sc2 )  { 
    cout << "Student: " << name << endl;
    cout << "Score 1: " << sc1 << ", Score 2: " << sc2 << endl;
    sum = (sc1 + sc2);
    cout << "Sum: " << sum << endl;
    float avg = sum / i;
    cout << "Average: " << avg << endl << endl;
  }
  
  //close file, end program
  ifs.close();
  return 0;
}
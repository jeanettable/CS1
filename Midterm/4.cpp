//Midterm Program 4 by Jeanette Abell
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int getRdnum(int n1 = 0, int n2 = 100);   //base prototype with defaults

int main()  {

  int num;
  int n1, n2, val;
  unsigned seed = time(0);    //seed randomization
  srand(seed);

  do {            //input validation
      cout << "Enter 1, 2, or 0: ";
      cin >> num;
  } while (num < 0 || num > 2);

  switch(num) {
    case 1:
      do {        //input val to work with default n2
        cout << "You chose to enter one value,\n please enter a value below 100: ";
        cin >> n1;
      } while (n1 > 100 || n1 < 0);
      val = getRdnum(n1);
      cout << "Your random number between " << n1 << " and 100 is: " << val << endl << endl;
      break;
    case 2:
      do {
        cout << "You chose to enter two values,\n please enter two values between 1 and 1000\n the smaller of the two being entered first: ";
        cin >> n1 >> n2;
      } while (n1 < 0 && n2 >= 1000 && n1 > n2);
      val = getRdnum(n1, n2);
      cout << "Your random number between " << n1 << " and " << n2 << " is: " << val << endl << endl;
      break;
    case 0:
    cout << "You chose to enter no value,\n and so we have generated a random number for you \n between 0 and 100!\n";
    val = getRdnum();
    cout << "That random number is: " << val << endl << endl;
    break;
  }

  return 0;
}

int getRdnum()  {                             //uses defaults
  int randNum = rand() % (100) + 1;           //base starts at 0
  return randNum;
}

int getRdnum(int n1) {                       //uses one input as n1
  int randNum = rand() % ((100 - n1) +1) + n1;
  return randNum;
}

int getRdnum(int n1, int n2)  {             //uses two inputs n1, n2
  int randNum = rand() % ((n2 - n1) + 1) + n1;
  return randNum;
}
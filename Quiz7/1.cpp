//Program 1 checks for difference less than 10
#include <iostream>
#include <cmath>
using namespace std;

void  compareTen(int [], int);
const int N = 10;

int main()  {

  int number[N] = {10, 15, 0, -25, 19, 20, 25, 30, 45, 20};
  
  for(int i=0; i<N; i++)  {
    compareTen(number, i);
  }
  return 0;
}

void  compareTen(int n[], int i) {
    if ( i == 0 ) {
      if (abs(n[i] - n[i+1]) < 10)  {
        cout << "Value: " << n[i] << ", difference less than 10\n";
      }
    }
    else if ( i == N-1 )  {
        if (abs(n[i] - n[i-1]) < 10) {
          cout << "Value: " << n[i] << ", difference less than 10\n";
        } 
      } else {      //(all others) 
        if( (abs(n[i] - n[i+1]) < 10) && (abs(n[i] - n[i-1]) < 10) )
        cout << "Value: " << n[i] << ", difference less than 10\n";
      }
}

//I think it's done! Thanks, Professor!
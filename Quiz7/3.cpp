//finds the max val in two halves of array
#include <iostream>
using namespace std;

int findmax(int [], int, int);
const int N = 10;

int main()  {

  int number[N] = {10, 15, 0, -25, 19, 20, 25, 30, 45, 20};
  
  cout << "Max from first half: " <<
  findmax(number, 0, ((N/2) - 1) ) << endl;
  cout << "Max from second half: " <<
  findmax(number, (N/2), (N-1)) << endl;

}


int findmax(int number[], int from, int to)
{
  static int max = number[from];
  
  for (int i=from; i < to; i++)  {
    if(max < number[i+1])
      max = number[i+1];
  }
  return max;
}
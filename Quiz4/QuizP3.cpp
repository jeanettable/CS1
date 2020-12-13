#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//this program generates three random numbers, sum & avg in precision 5
int main()  {
  
  float num1, num2, num3;
  
  //seed the randomization
  unsigned seed = time(0);
  srand(seed);

  //generate three random num
  num1 = rand();
  num2 = rand();
  num3 = rand();

  //calculate summation and avg
  double sum = num1 + num2 + num3;
  double avg = sum / 3.0;

  //print statements
  cout << "The random numbers created were: \n"; 
  cout << setprecision(5) << fixed << num1 << ", \n";
  cout << setprecision(5) << fixed << num2 << ", and \n";
  cout << setprecision(5) << fixed << num3 << "\n\n";
  
  cout << "Their summation is: " << setprecision(5) << fixed << sum << endl;
  cout << "Their average is: " << setprecision(5) << fixed << avg << endl;
    
  return 0;
}
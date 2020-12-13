//Midterm program 3 by Jeanette Abell
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int getRdnum(void);
int isPrime(int);

int main()  {

  ofstream ofs;              //create output stream object
  const int N = 10;    
  unsigned seed = time(0);    //seed randomization
  srand(seed);
  int n;


  ofs.open("Midterm/primenumbers.txt");   //open file for writing

  //verify the file is opened
  if (ofs.fail()) {
    cout << "Error upon open\n";
    exit(0);
  }

  for (int i=0; i<N; i++) {
    n = getRdnum();
    //cout << n << endl;          //test ln
    if (isPrime(n)) {
      //cout << "writing this number as prime: " << n << endl << endl;  //test ln
      ofs << n << endl;
    }
  }

  ofs.close();                  //close file and terminate
  return 0;
}

int getRdnum(void)  {
  int randNum = rand() % 50;   //generate and return random int (1 - 50)
  return randNum;
}

int isPrime(int n)  {         //int returned will be flag
  int flag = 1;
  if (n < 2)       //catch cases of 0 and 1, not primes
    return 0;
    else {                    //n > 1
      for (int i = 2; i <= n/2 ; ++i) {
        if (n % i == 0){      //indicates divisibility...but is only evaluating @ i=2
          flag = 0;
        } else  
        flag = 1;              //indicates not divisible   
    }
    return flag;
  }   
}
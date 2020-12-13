//Program counts occurrences of th, quiz8, P1
//Jeanette Abell
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int findth ( string );

int main()  {

ifstream	ifso;     //to read python.txt
string pyword;     //to store string read in
int result;       //holds each iteration's count
int totalTh;     //to hold total

ifso.open("./Quiz8/python.txt", fstream::in);
if (ifso) {       //Open Successful
  while (ifso >> pyword)  {
    result = findth(pyword);
    totalTh += result;
    //cout << "Occurence:\t" << result << endl;
  } 
  cout << "The total:\t" << totalTh << endl;
}
}

int findth( string pyword ) {

  int count = 0;   //counter of 'th'
  int start = 0;  //starting point
  int pos;

  //cout << pypar << endl;
  while ( (pos = pyword.find("th", start)) != string::npos) 
    {
    count++;
    start = pos + 2; 
  }
  
  return count;
}

//THANK YOU FOR HINTS, PROFESSOR! :)
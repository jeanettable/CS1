//different version of Quiz 9, by Jeanette Abell
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream> 
using namespace std;

//structure prototype
const int NUMEMPS = 100;  
struct Employee {
	int id;           //6 digit numeric val
	string first;     //two separate words
  string last;      // ^
	int salary;     // 0 ~ 500000
	string 	dptname;  //one word
	string date;      //format Mon Day Year: Jan 31 2018
};

//function prototypes
int makingEmployeeRecords( Employee []);
void printEmployeeRecords( Employee [], int);
void printSixFig( Employee [], int);
void printComputerEmp( Employee [], int);
string getStartDate(string);

int main()  {
  int numOfRecords;
  Employee erArr[NUMEMPS]; 
  numOfRecords = makingEmployeeRecords(erArr);
  printEmployeeRecords(erArr, numOfRecords);

}

int makingEmployeeRecords( Employee erArr[] )  {
  
  Employee er;        //instance for populating structures
  string employee, field;    //holds individual employee, field
  stringstream ss;    //create ss obj
  int fcount=0;       //fields counter, switch control
  int numrecs=0;      //accumulator for records read
  
  // create fstream obj that opens employee.txt in read
  fstream fileReader("employee.txt", ios::in);

  if(!fileReader) {     //incase of error
    cout << "Error upon opening.";
      return 0;
  }
  
  //get each line as a string => employee
  // ************************
  //REMEMBER ">>" operator actually read just one word 
  while( getline(fileReader, employee, '\n') && !(fileReader.eof()) )   
  {
    ss << employee;
    //read and create fields separated by " "
    while( getline(ss, field, ' ') )  {
        switch(fcount)  {
          case 0:
            er.id = stoi(field);
            break;
          case 1:
            er.first = field;
            break;
          case 2:
            er.last = field;
            break;
          case 3:
            er.salary = stoi(field);
            break;
          case 4:
            er.dptname = field;
            break;
          case 5: 
            er.date.clear();     //reset string
            er.date += field + ' ';
            break;
          case 6:
            er.date += field + ' ';
            break;
          case 7:
          er.date += field;
          break;
        }
      fcount = ++fcount%8;
    }
      //populate er to erArr, then numrecs++
      erArr[numrecs] = er;
      numrecs++;
      ss.clear();
  }
  //close file stream
  fileReader.close();
  return numrecs;
}

void printEmployeeRecords( Employee erArr[], int numOfRecords )  {
    for(int i=0; i<numOfRecords; i++){
        cout << setw(7) << erArr[i].id << "\t";
        cout << setw(12) << erArr[i].first << "\t";
        cout << setw(12) << erArr[i].last << "\t";
        cout << setw(8) << erArr[i].salary << "\t";
        cout << setw(10) << erArr[i].dptname << "\t";
        cout << setw(12) << erArr[i].date << endl;
    }  
}   

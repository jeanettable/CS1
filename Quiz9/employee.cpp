//Quiz 9 parsing program by Jeanette Abell
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

//structure prototype
const int NUMEMPS = 500;  //number of employees
struct Employee {
	int id;           //6 digit numeric val
	string name;     //two separate words
	int salary;     // 0 ~ 500000
	string 	dptname;  //one word
	string date;      //format Mon Day Year: Jan 31 2018
};

//function prototypes
int makingEmployeeRecords( Employee []);
void printEmployeeRecords( Employee [], int);
void printSixFig( Employee [], int);
void printComputerEmp( Employee [], int);

//GET function prototypes; assuming readline will be passed in
int getID(string str);
string getName(string str);
int getSalary(string str);
string getDepartment(string str);
string getStartDate(string str);

int main()  {
  int				numOfRecords = 0;
	Employee 	er[NUMEMPS];      //create instance of Employees

	numOfRecords = makingEmployeeRecords(er);
	printEmployeeRecords(er, numOfRecords);
  printSixFig(er, numOfRecords);
  //printComputerEmp(er, numOfRecords);

}

int		makingEmployeeRecords(Employee er[])
{
	int			count=0;
	string		readline;
	ifstream	ifso;

	ifso.open("employee.txt");
	if (!ifso) {
		cout << "File Open Error\n";
		exit(0);
	}
	while((ifso >> readline) && (count < NUMEMPS) ) {
		er[count].id 	= getID(readline);
		er[count].name		= getName(readline);
		er[count].salary		= getSalary(readline);
		er[count].dptname 		= getDepartment(readline);
		er[count].date		= getStartDate(readline);
		count++;
	}
	return count;
}

void printEmployeeRecords( Employee er[], int numOfRecords)  {
    for(int i=0; i<numOfRecords; i++){
        cout << setw(8) << er[i].id << "\t";
        cout << setw(20) << er[i].name << "\t";
        cout << setw(8) << er[i].salary << "\t";
        cout << setw(14) << er[i].dptname << "\t\t";
        cout << setw(12) << er[i].date << endl;
	}
}

int getID(string str) {
  return 	stoi(str.substr(0,6));
}

string getName(string str)  {
  int pos, startpos;
  string fullname;                        //create empty string
  pos = str.find(' ');
  startpos = pos+1;                       //points at first name
  pos = str.find(' ', startpos);     
  fullname += str.substr(startpos, pos-1) + ' '; //end of first name
  startpos = pos+1;                       //points at last name
  pos = str.find(' ', startpos);          //end of last name
  fullname += str.substr(startpos, pos-1);  //concat full name

  return fullname;
}

int getSalary(string str) {   //third item
	int	startpos, pos, first;
  string salaryStr;          //to hold concat version of salary
  startpos=0;
	int	salarylen;
    for(int i=0; i<3; i++)  {
    pos = str.find(' ', startpos);
    startpos = pos+1;
    first = startpos;   //last loop leaves pointer to salary start
  }
  pos = str.find(' ', first); 
  salarylen = pos - first;
  for(int i=first; i<=(first + salarylen); i++)  {
    salaryStr += str[i];
  }
	int	salary = stoi(salaryStr);
  return salary;

}

string getDepartment(string str)  { //fourth item
  string dept;
  int		startpos, pos, endpos;
	startpos = 0;
	for(int i=0; i<4; i++) {          //iterates to 4th item via spaces
		pos = str.find(' ',startpos);
		startpos = pos+1;
	}
  endpos = str.find(' ', startpos);   
  dept = str.substr(startpos, endpos-1);
  return dept;
}

string getStartDate(string str) {   //fifth item
  string dateString;
  int		startpos, pos, count;
	startpos = 0;
	for(int i=0; i<5; i++) {
		pos = str.find(' ',startpos);
		startpos = pos+1;
	}
  dateString = str.substr(startpos, str.length());
	return dateString;
}

//special function that prints records of employees making $100000+
void printSixFig( Employee er[], int numOfRecords) {
    	for(int i=0; i<numOfRecords; i++){
          if(er[i].salary >= 100000)  {
              cout << setw(8) << er[i].id << "\t";
              cout << setw(20) << er[i].name << "\t";
              cout << setw(8) << er[i].salary << "\t";
              cout << setw(14) << er[i].dptname << "\t\t";
              cout << setw(12) << er[i].date << endl;
          }
      }
}

/*  NOT YET WORKING
//special function that finds all Computer Department employees
void printComputerEmp( Employee er[], int numOfRecords) {
    	for(int i=0; i<numOfRecords; i++){
          if(er[i].dptname == 'Computer')  {
              cout << setw(8) << er[i].id << "\t";
              cout << setw(20) << er[i].name << "\t";
              cout << setw(8) << er[i].salary << "\t";
              cout << setw(14) << er[i].dptname << "\t\t";
              cout << setw(12) << er[i].date << endl;
          }
      }
}
*/
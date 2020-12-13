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
	Employee 	er[NUMEMPS];    

	numOfRecords = makingEmployeeRecords(er);
	printEmployeeRecords(er, numOfRecords);
  cout << "\nThe following are making 6 figure salaries: " << endl;
  printSixFig(er, numOfRecords);
  //printComputerEmp(er, numOfRecords);     //NOT WORKING

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
	//use getline instead of line below, because we want to read the entire line
  // while((ifso >> readline) && (count < NUMEMPS) ) {
	while((getline(ifso, readline)) && (count < NUMEMPS) ) {
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

  stringstream ss;
  string fullname, field;                     //create empty string

  ss << str;
  getline(ss, field, ' ');
  getline(ss, field, ' ');
  fullname = field + ' ';
  getline(ss, field, ' ');
  fullname += field;

  return fullname;
}

int getSalary(string str) {   //third item
  stringstream ss;
	string salaryStr;     //to hold concat version of salary
  string field;
  ss << str;
  for(int i=0; i<3; i++)  {
    getline(ss, field, ' ');
  }
  getline(ss, salaryStr, ' ');
	int	salary = stoi(salaryStr);
  return salary;

}

string getDepartment(string str)  { //fourth item
  string dept, field;
  stringstream ss;

  ss << str;
	for(int i=0; i<4; i++) {          //iterates to 4th item via spaces
    getline(ss, field, ' ');
	}
  getline(ss, dept, ' ');
  return dept;
}

string getStartDate(string str) {   //fifth item
  stringstream ss;
  string dateString, field;

  ss << str;
	for(int i=0; i<5; i++) 
    getline(ss, field, ' ');
  
	for(int i=0; i<2; i++) {
    getline(ss, field, ' ');
    dateString += field + ' ';
  }
  dateString += field;

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
/* WHY IS THIS ONE NOT WORKING??
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

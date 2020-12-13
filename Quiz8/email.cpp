//Problem 2, Quiz 8 by Jeanette Abell
#include		<iostream>
#include		<cctype>
#include		<cstring>
using namespace std;

bool 	idcheck(char []);
bool 	domaincheck(char []);

int 	main()
{
		char 	email[25];

		cout 	<< "Enter your email:\n";
		cin.getline(email, 25);

		if( idcheck(email))
			cout << "ID check passed\n";
      else
        cout << "ID check failed\n";
		if( domaincheck(email))
			cout << "Domain check passed\n";
      else 
        cout << "Domain check failed\n";
}

//function definitions
bool 	idcheck( char email[] )
{
  int i=0;
  if(isalpha(email[i])){  //only looks at first char
    while( email[i] != '@' )   //until encounters @ sign
      i++;
    if(i > 5 && i < 15)   //use index of @ sign as id length
      return true;
    return false;
  }
	return false;
}

bool	domaincheck( char email[] )
{
  int length,i;
  length = strlen(email);
  i = length-1;     //last populated element
  do {
    if (email[i] == '.') 
      break;      //i will be at pointer for dot
    i--;       //decrement i, looking for dot
  } while (i > 0); 
  //following adds i to pointer val email to place at dot
  if ( strcmp(".com", email+i) == 0) //domain is com
    return true;
  else if ( strcmp(".org", email+i) == 0)  //org
    return true;
  else if ( strcmp(".edu", email+i) == 0)    //edu
    return true;
  else if ( strcmp(".net", email+i) == 0)    //net
    return true;
  else if ( strcmp(".gov", email + i) == 0)    //gov
    return true;
  else
    return false;
}


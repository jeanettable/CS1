//Problem 2, Quiz 8 by Jeanette Abell
//MIGHT REVISIT FOR PRACTICE...not working yet
#include		<iostream>
#include		<cctype>
#include    <string>
using namespace std;

//bool 	idcheck(string);
//bool 	domaincheck(string);

int 	main()
{
		string email;

		cout 	<< "Enter your email:\n";
		cin >> email;

    string splitID;
    int found = email.find('@', 0); //look for @ delim
    splitID.append(email, 0, found);  //creates ID only

/*
		if( idcheck(splitID))
			cout << "ID check passed\n";
      else
        cout << "ID check failed\n";
		if( domaincheck(email))
			cout << "Domain check passed\n";
      else 
        cout << "Domain check failed\n"; */
}
/*
//function definitions
bool 	idcheck( string )
{
  int i=0;
  if(!isalpha(email[i]))    //only looks at first char
    return false;
  while(!ispunct(email[i]) )   //until encounters @ sign
    i++;
  if(i < 5 || i > 15)       //use index of @ sign as length
    return false;
  //otherwise
	return true;
}

bool	domaincheck( string )
{
  int start = strlen(email)-4;  //place to begin check
  if ( !ispunct(email[start]) ) //indicates not .123 length
    return false;
  //Does it need to specifically check for .listnames?
	//otherwise
  return true;
}
*/
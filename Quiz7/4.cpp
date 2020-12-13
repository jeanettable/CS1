#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void makevector(vector<int> &, int);
void printvector(vector<int>);
void deleteone(vector<int> &);
int main()
{
 vector<int> number;
 int size = 20;
 srand(time(0));
 makevector(number, size);
 printvector(number);
 deleteone(number);
}
void makevector(vector<int> &vec, int size)
{
 for(int i=0; i<size; i++)
         vec.push_back(rand() % 10);
}
void printvector(vector<int> vec)
{
 for(int v : vec)
          cout << v << "\t";
 cout << endl;
}
void deleteone(vector<int> &vec)
{
      int deletecount = 0;
      int usernum;
      cout << "Enter value to delete: ";
      cin >> usernum;

      for (int i=0; i<vec.size(); i++)  {
        if (vec[vec.size()-1] == usernum){
          vec.pop_back();
          deletecount++;
        } else if (vec[i] == usernum)  {
          // It's great algorithm to delete one item with using pop_back(). 
          // When you have vector data structure, there are almost all member functions that you need to manipulate the elements.
            int temp = vec[vec.size()-1];
            vec[vec.size()-1] = usernum;
            vec[i] = temp;
            vec.pop_back();
            deletecount++;
        }
      }

      cout << usernum << " was deleted " << deletecount << " times \n";
      printvector(vec);
 
}

/*solution code:

void deleteone(vector<int> &vec)
{
    int     usernum, deletecount=0;
    vector<int>::iterator iter;
    cout << "Enter the one integer value\n";
    cin >> usernum;

    while( (iter = find(vec.begin(), vec.end(), usernum) ) != vec.end()){
        if ( iter != vec.end()){
            cout << *iter << " is deleting\n";
            vec.erase(iter);
            deletecount += 1;
        }
    }
    cout << usernum << "is deleted " << deletecount << " times \n";
    printvector(vec);
} 
*/
//Midterm program 1 by Jeanette Abell :)
#include <iostream>
using namespace std;

int main()  {

    const  int N=5, M=5;    //not mutable
    int     i, j;
    for(i=0;i<N;i++) {
        for(j=i; j<M-i; j++)
            cout << " (" << i << "," << j << ") " ;
        cout << endl;
    }

}
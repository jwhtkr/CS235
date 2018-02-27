#include <iostream>
using namespace std;
int main()
{
    int *badptr = new int[10];
    // *badptr = 0;
    cout << "everything worked";
    
    delete [] badptr;
}
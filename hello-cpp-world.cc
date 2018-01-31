#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str = "123 abc 1+2 (1a)";
    string token;
    stringstream ss (str);
    
    while (!ss.eof())
    {
        ss >> token;
        cout << token << endl;
    }
}

#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    char c;
    int found = 0;
    for (c = 'a'; c <= 'z'; c++) {
      if (s.find(c) == std::string::npos) {
        cout << c << endl;
        found = 1;
        break;
      }
    }
    if (found == 0) {
      cout << "None" << endl;
    }
    return 0;
}

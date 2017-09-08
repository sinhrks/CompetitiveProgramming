#include<iostream>
using namespace std;

int main()
{
    string s;
    string r("");
    cin >> s;

    int i;

    for (i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            r += s[i];
        }
    }
    cout << r << endl;
    return 0;
}

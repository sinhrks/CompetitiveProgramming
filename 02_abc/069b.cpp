#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.size();
    cout << s[0] + to_string(len - 2) + s[len-1]  << endl;
    return 0;
}

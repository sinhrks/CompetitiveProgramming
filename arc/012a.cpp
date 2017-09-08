#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string day;
    cin >> day;

    if (day == "Sunday" || day == "Saturday") {
      cout << 0 << endl;
    } else if (day == "Friday") {
      cout << 1 << endl;
    } else if (day == "Thursday") {
      cout << 2 << endl;
    } else if (day == "Wednesday") {
      cout << 3 << endl;
    } else if (day == "Tuesday") {
      cout << 4 << endl;
    } else if (day == "Monday") {
      cout << 5 << endl;
    }

    return 0;
}

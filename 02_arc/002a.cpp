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

    int Y;
    cin >> Y;

    if (Y % 400 == 0) {
      cout << "YES" << endl;
    } else if (Y % 100 == 0) {
      cout << "NO" << endl;
    } else if (Y % 4 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
}

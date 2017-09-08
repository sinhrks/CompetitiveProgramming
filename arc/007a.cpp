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

    char X;
    cin >> X;
    string s;
    cin >> s;

    string res("");

    for (int i = 0; i < s.size(); i++) {
      if (s[i] != X) {
        res += s[i];
      }
    }

    cout << res << endl;
    return 0;
}

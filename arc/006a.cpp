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

    bool er[10] = {};
    bool lr[10] = {};

    for (int i = 0; i < 6; i++) {
      char c;
      cin >> c;
      er[c - '0'] = true;
    }

    int B;
    cin >> B;

    for (int i = 0; i < 6; i++) {
      char c;
      cin >> c;
      lr[c - '0'] = true;
    }

    int same = 0;
    for (int i = 0; i < 10; i++) {
      if (er[i] && lr[i]) {
        same++;
      }
    }

    if (same == 6) {
      cout << 1 << endl;
    } else if (same == 5 && lr[B]) {
      cout << 2 << endl;
    } else if (same == 5) {
      cout << 3 << endl;
    } else if (same == 4) {
      cout << 4 << endl;
    } else if (same == 3) {
      cout << 5 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
}

#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
typedef long long ll;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string s;
    cin >> s;

    string replacer[16] = {
      "AA", "AB", "AX", "AY",
      "BA", "BB", "BX", "BY",
      "XA", "XB", "XX", "XY",
      "YA", "YB", "YX", "YY"};

    int current = s.size();

    for (int i = 0; i < 16; i++) {
      for (int j = 0; j < 16; j++) {
        if (i == j) {
          continue;
        }
        int cnt = 0;

        for (int k = 0; k < s.size(); k++) {
          if (k < s.size() - 1 &&
              s[k] == replacer[i][0] &&
              s[k + 1] == replacer[i][1]) {
            cnt++;
            k++;
          } else if (k < s.size() - 1 &&
                     s[k] == replacer[j][0] &&
                     s[k + 1] == replacer[j][1]) {
            cnt++;
            k++;
          } else {
            cnt++;
          }
        }
        current = min(current, cnt);
      }
    }

    cout << current << endl;
    return 0;
}

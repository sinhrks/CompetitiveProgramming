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

    int N, L;
    cin >> N >> L;
    cin.ignore();

    bool lines[21][20] = {};
    for (int i = 0; i < L; i++) {
      string s;
      getline(cin, s);

      for (int j = 0; j < s.size(); j++) {
        if (s[j] == '|' || s[j] == '-') {
          lines[i][j] = true;
        }
      }
    }
    string ans;
    getline(cin, ans);

    int current;
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] == 'o') {
        current = i;
      }
    }

    for (int i = L - 1; i >= 0; i--) {
      if (current >= 2 && lines[i][current - 1]) {
        current -= 2;
      } else if (current <= 2 * N - 2 && lines[i][current + 1]) {
        current += 2;
      }
    }
    cout << current / 2 + 1 << endl;
    return 0;
}

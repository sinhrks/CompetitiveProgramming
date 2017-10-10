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

const int DEFAULT = -9999;

bool is_ok(int q[]) {
  for (int i = 0; i < 7; i++) {
    for (int j = i + 1; j < 8; j++) {
      if (q[i] != DEFAULT) {
        if (q[i] == q[j]) {
          return false;
        }
        // 斜めのチェック
        if (abs(q[i] - q[j]) == j - i) {
          return false;
        }
      }
    }
  }
  return true;
}

bool put_ok(int q[], int remains) {
  if (remains == 0) {
    if (is_ok(q)) {
      return true;
    } else {
      return false;
    }
  }

  for (int i = 0; i < 8; i++) {
    if (q[i] == DEFAULT) {
      for (int j = 0; j < 8; j++) {
        q[i] = j;
        if (is_ok(q)) {
          if (put_ok(q, remains - 1)) {
            return true;
          }
        }
      }
      // 次の試行のためにリセット
      q[i] = DEFAULT;
    }
  }
  return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // i 行目の queenの位置を入れる
    int q[8];
    for (int i = 0; i < 8; i++) {
      q[i] = DEFAULT;
    }

    for (int i = 0; i < 8; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < 8; j++) {
        if (s[j] == 'Q') {
          if (q[i] != DEFAULT) {
            cout << "No Answer" << endl;
            return 0;
          }
          q[i] = j;
        }
      }
    }
    if (!is_ok(q)) {
      cout << "No Answer" << endl;
      return 0;
    }
    if (put_ok(q, 5)) {
      for (int i = 0; i < 8; i++) {
        string s("........");
        s[q[i]] = 'Q';
        cout << s << endl;
      }
      return 0;
    }
    cout << "No Answer" << endl;
    return 0;
}

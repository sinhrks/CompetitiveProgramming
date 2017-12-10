#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
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
#include <bitset>
typedef long long ll;
typedef unsigned long long ull;

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

bool sheep[100010] = {};

bool check(string s, int n) {
  for (int i = 0; i < n; i++) {
    int nx = (i + 1) % n;
    int nx2 = (i + 2) % n;

    if (i >= n - 2) {
      if (sheep[nx]) {
        if (s[nx] == 'o') {
          if (sheep[i] != sheep[nx2]) return false;
        } else {
          if (sheep[i] == sheep[nx2]) return false;
        }
      } else {
        if (s[nx] == 'o') {
          if (sheep[i] == sheep[nx2]) return false;
        } else {
          if (sheep[i] != sheep[nx2]) return false;
        }
      }

    } else {
      if (sheep[nx]) {
        sheep[nx2] = s[nx] == 'o' ? sheep[i] : !sheep[i];
      } else {
        sheep[nx2] = s[nx] == 'o' ? !sheep[i] : sheep[i];
      }
    }
  }
  return true;
}

void output(int n) {
  REP(i, n) {
    if (sheep[i]) {
      cout << "S";
    } else {
      cout << "W";
    }
  }
  cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  string s;
  cin >> s;

  sheep[0] = true;
  sheep[1] = true;
  if (check(s, N)) {
    output(N);
    return 0;
  }

  sheep[0] = true;
  sheep[1] = false;
  if (check(s, N)) {
    output(N);
    return 0;
  }

  sheep[0] = false;
  sheep[1] = false;
  if (check(s, N)) {
    output(N);
    return 0;
  }

  sheep[0] = false;
  sheep[1] = true;
  if (check(s, N)) {
    output(N);
    return 0;
  }

  cout << -1 << endl;
  return 0;
}

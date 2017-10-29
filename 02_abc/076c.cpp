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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S, T;
  cin >> S >> T;

  bool rep[50] = {};
  bool replaced = false;
  REPR(i, S.size() - T.size()) {
    replaced = true;
    REP(j, T.size()) {
      if (S[i + j] != T[j] && S[i + j] != '?') {
        replaced = false;
      }
    }
    if (replaced) {
      rep[i] = true;
      break;
    }
  }

  bool restorable = false;
  REP(i, S.size()) {
    if (rep[i]) {
      restorable = true;
    }
  }
  if (!restorable) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  REP(i, S.size()) {
    if (rep[i] == true) {
      cout << T;
      i += T.size() - 1;
    } else if (S[i] == '?') {
      cout << "a";
    } else {
      cout << S[i];
    }
  }
  cout << endl;
  return 0;
}

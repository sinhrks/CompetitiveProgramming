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

  string S;
  cin >> S;

  int ch[26] = {};
  REP(i, S.size()) {
    ch[S[i] - 'a']++;
  }
  int odd = 0;
  int pair = 0;
  REP(i, 26) {
    if (ch[i] % 2 == 1) odd++;
    pair += ch[i] / 2;
  }
  // cout << odd << "  " << pair << endl;
  if (odd == 0) {
    cout << S.size();
  } else {
    cout << pair / odd * 2 + 1 << endl;
  }
  return 0;
}

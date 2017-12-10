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

  string A;
  cin >> A;

  ll c[26] = {};
  REP(i, A.size()) {
    c[A[i] - 'a']++;
  }

  ll total = A.size() * (A.size() - 1) / 2;
  REP(i, 26) {
    total -= c[i] * (c[i] - 1) / 2;
  }

  cout << total + 1 << endl;
  return 0;
}

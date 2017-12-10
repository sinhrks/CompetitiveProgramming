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

  int N;
  ll K;
  cin >> N >> K;

  ll num[100010] = {};

  REP(i, N) {
    int a, b;
    cin >> a >> b;
    num[a] += b;
  }

  ll total = 0;
  REP(i, 100010) {
    total += num[i];
    if (total >= K) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

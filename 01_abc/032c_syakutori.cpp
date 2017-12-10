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

ll s[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, K;
  cin >> N >> K;
  REP(i, N) {
    cin >> s[i];
    if (s[i] == 0) {
      cout << N << endl;
      return 0;
    }
  }
  ll mxl = 0;
  ll current = 1;
  int li = 0;
  int ri = 0;
  while (li < N && ri < N) {
    while (current * s[li] <= K && li < N) {
      current *= s[li];
      li++;
    }
    if (li - ri > mxl) {
      mxl = li - ri;
    }
    if (current != 1) {
      current /= s[ri];
    }
    ri++;
  }

  cout << mxl << endl;
  return 0;
}

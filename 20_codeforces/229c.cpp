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

# define INF 0x3f3f3f3f

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int v[1000010] = {};

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  REP(i, M) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    v[a]++;
    v[b]++;
  }
  ll total = 0;
  total = N * (N - 1LL) * (N - 2LL) / 6LL;
  ll broken = 0;
  REP(i, N) {
    broken += v[i] * (N - 1 - v[i]);
  }

  cout << total - broken / 2 << endl;
  return 0;
}

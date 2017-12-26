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

int a[100010] = {};
bool wrote[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  REP(i, M) {
    cin >> a[i];
  }
  reverse(a, a + M);
  REP(i, M) {
    if (!wrote[a[i]]) {
      cout << a[i] << endl;
    }
    wrote[a[i]] = true;
  }
  for (int i = 1; i <= N; i++) {
    if (!wrote[i]) {
      cout << i << endl;
    }
  }
  return 0;
}

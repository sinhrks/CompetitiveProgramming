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

int num[5] = {};
bool prohibited[10] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  REP(i, K) {
    int x;
    cin >> x;
    prohibited[x] = true;
  }
  for (int i = N; i < 100000; i++) {
    int x = i;
    bool ok = true;
    while (x > 0) {
      if (prohibited[x % 10]) ok = false;
      x /= 10;
    }
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}

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

ll A[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, T;
  cin >> N >> T;
  REP(i, N) {
    cin >> A[i];
  }

  ll ma = A[1] - A[0];
  ll mi = A[0];
  int mac = 0;
  int c = 0;
  for (int i = 1; i < N; i++) {
    if (A[i] - mi > ma) {
      ma = A[i] - mi;
      c = 1;
    } else if (A[i] - mi == ma) {
      c++;
    }
    // cout << mi << " " << A[i] << " " << ma << " " << c << endl;
    mi = min(mi, A[i]);
    mac = max(mac, c);
  }

  cout << mac << endl;
  return 0;
}

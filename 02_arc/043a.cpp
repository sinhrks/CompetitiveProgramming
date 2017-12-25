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

ll S[100000] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, A, B;
  cin >> N >> A >> B;

  REP(i, N) {
    cin >> S[i];
  }
  ll mi = S[0];
  ll ma = S[0];
  REP(i, N) {
    mi = min(mi, S[i]);
    ma = max(ma, S[i]);
  }
  if (mi == ma) {
    cout << -1 << endl;
    return 0;
  }
  double P = 1.0 * B / (ma - mi);

  double avg = 0.0;
  REP(i, N) {
    avg += P * S[i] / N;
  }
  double Q = A - avg;

  printf("%.10f %.10f\n", P, Q);
  return 0;
}

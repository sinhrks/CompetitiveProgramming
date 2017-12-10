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

int L[10010] = {};
int R[10010] = {};
int S[110] = {};
int T[110] = {};
int ANS[110] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, D, K;
  cin >> N >> D >> K;
  REP(i, D) {
    cin >> L[i] >> R[i];
  }
  REP(i, K) {
    cin >> S[i] >> T[i];
  }

  REP(d, D) {
    REP(i, K) {
      if (L[d] <= S[i] && S[i] <= R[d] && ANS[i] == 0) {
        if (S[i] < T[i]) {
          if (T[i] <= R[d]) {
            ANS[i] = d + 1;
          }
          S[i] = max(S[i], R[d]);
          // cout << "move: " << i << " " << S[i] << endl;
        } else if (S[i] > T[i]) {
          if (T[i] >= L[d]) {
            ANS[i] = d + 1;
          }
          S[i] = min(S[i], L[d]);
          // cout << "move: " << i << " " << S[i] << endl;
        }
      }
    }
  }
  REP(i, K) {
    cout << ANS[i] << endl;
  }

  return 0;
}

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
ll B[100010] = {};
ll C[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) {
    cin >> A[i];
  }
  REP(i, N) {
    cin >> B[i];
  }
  REP(i, N) {
    cin >> C[i];
  }
  sort(A, A + N);
  sort(B, B + N);
  sort(C, C + N);

  ll total = 0;
  REP(i, N) {
    ll ai = lower_bound(A, A + N, B[i]) - A;
    ll ci = upper_bound(C, C + N, B[i]) - C;
    total += ai * (N - ci);
  }

  cout << total << endl;
  return 0;
}

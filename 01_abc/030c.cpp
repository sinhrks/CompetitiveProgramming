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

  int N, M;
  cin >> N >> M;
  int X, Y;
  cin >> X >> Y;

  vector<ll> a(N);
  vector<ll> b(M);
  REP(i, N) {
    cin >> a[i];
  }
  REP(i, M) {
    cin >> b[i];
  }
  ll total = 0;
  ll current = 0;
  while (true) {
    int i = lower_bound(a.begin(), a.end(), current) - a.begin();
    if (i >= a.size()) break;
    current = a[i];
    current += X;

    i = lower_bound(b.begin(), b.end(), current) - b.begin();
    if (i >= b.size()) break;
    current = b[i];
    current += Y;
    total++;
  }

  cout << total << endl;
  return 0;
}

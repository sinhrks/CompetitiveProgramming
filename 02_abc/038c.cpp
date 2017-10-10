#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

template <typename T>
T comb(T n, T k) {
  T r = 1;
  for (ull d = 1; d <= k; ++d) {
    r *= n--;
    r /= d;
  }
  return r;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int a[100001] = {};
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  a[N + 1] = -1;

  ll total = 0;
  ll cnt = 1;
  for (int i = 0; i < N; i++) {
    if (a[i] < a[i + 1]) {
      cnt++;
    } else {
      total += comb(cnt, 2LL) + cnt;
      cnt = 1;
    }
  }

  cout << total << endl;
  return 0;
}

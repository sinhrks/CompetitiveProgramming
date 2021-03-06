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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  for (int i = 0; i < N; i++) {
    ll mi = -D * i + (N - 1 - i) * C;
    ll ma = -C * i + (N - 1 - i) * D;
    if (mi <= B - A && B - A <= ma) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

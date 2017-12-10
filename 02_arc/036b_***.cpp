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

using namespace std;

int H[300010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  REP(i, N) {
    cin >> H[i];
  }

  int mx = 0;
  int l = 0;
  for (int i = 1; i < N - 1; i++) {
    if (H[i - 1] > H[i] && H[i] < H[i + 1]) {
      mx = max(mx, l - i + 1);
      l = i;
    }
  }
  mx = max(mx, N - l);

  cout << mx << endl;
  return 0;
}

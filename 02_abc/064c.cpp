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

  int N;
  cin >> N;

  int f = 0;
  int scores[8] = {};
  REP(i, N) {
    int a;
    cin >> a;
    if (a >= 3200) {
      f++;
    } else {
      scores[a / 400]++;
    }
  }
  int ans = 0;
  REP(i, 8) {
    if (scores[i] > 0) ans++;
  }

  cout << max(ans, 1) << " " << ns + f << endl;
  return 0;
}

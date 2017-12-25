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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, L;
  cin >> N >> M >> L;
  int P, Q, R;
  cin >> P >> Q >> R;

  int ans1 = (N / P) * (M / Q) * (L / R);
  int ans2 = (N / P) * (M / R) * (L / Q);
  int ans3 = (N / Q) * (M / R) * (L / P);
  int ans4 = (N / Q) * (M / P) * (L / R);
  int ans5 = (N / R) * (M / P) * (L / Q);
  int ans6 = (N / R) * (M / Q) * (L / P);
  int ans = max(max(max(ans1, ans2), max(ans3, ans4)), max(ans5, ans6));

  cout << ans << endl;
  return 0;
}

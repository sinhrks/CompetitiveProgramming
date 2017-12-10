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

int row[100010] = {};
int col[100010] = {};

int rowc[100010] = {};
int colc[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll R, C, K, N;
  cin >> R >> C >> K >> N;

  set<pair<ll, ll>> points;
  REP(i, N) {
    ll r, c;
    cin >> r >> c;
    r--;
    c--;
    // 行、列にある飴の数
    row[r]++;
    col[c]++;
    points.insert(make_pair(r, c));
  }
  // 行、列にある飴の個数の頻度
  REP(i, R) {
    rowc[row[i]]++;
  }
  REP(i, C) {
    colc[col[i]]++;
  }
  ll ans = 0;
  REP(i, K + 1) {
    // 合計 K になる行と列の組み合わせを数え上げ
    ans += rowc[i] * colc[K - i];
  }
  for (auto p : points) {
    // 飴のある位置を調べて補正
    if (row[p.first] + col[p.second] == K) ans--;
    if (row[p.first] + col[p.second] == K + 1) ans++;
  }

  cout << ans << endl;
  return 0;
}

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

  int N, R;
  cin >> N >> R;
  string S;
  cin >> S;

  int ans = 0;
  REPR(i, S.size() - 1) {
    if (S[i] == '.') {
      ans += max(0, i - R + 1);
      break;
    }
  }
  for (int i = S.size() - 1; i >= 0; i--) {
    if (S[i] == '.') {
      ans++;
      i -= R - 1;
    }
  }

  cout << ans << endl;
  return 0;
}

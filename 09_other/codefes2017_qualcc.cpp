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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  int l = 0;
  int r = S.size() - 1;

  int ans = 0;
  while (l < r) {
    if (S[l] == S[r]) {
      l++;
      r--;
    } else {
      if (S[l] == 'x') {
        ans++;
        l++;
      } else if (S[r] == 'x') {
        ans++;
        r--;
      } else {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << ans << endl;
  return 0;
}

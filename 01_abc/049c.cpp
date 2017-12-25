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

string prefixes[4] = {"maerd", "remaerd", "esare", "resare"};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  reverse(S.begin(), S.end());

  int pos = 0;
  while (pos < S.size()) {
    bool ok = false;
    REP(i, 4) {
      string prefix = prefixes[i];
      if (equal(prefix.begin(), prefix.end(), S.begin() + pos)) {
        pos += prefix.size();
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}

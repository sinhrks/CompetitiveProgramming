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

  int N, C;
  cin >> N >> C;

  vector<int> v;
  vector<bool> used;
  for (int i = 0; i < N; i++) {
    int l;
    cin >> l;
    v.push_back(l);
    used.push_back(false);
  }

  std::sort(v.begin(), v.end());

  int cases = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (!used[i]) {
      used[i] = true;
      int lim = C - v[i] - 1;
      auto it = upper_bound(v.begin(), v.end(), lim);
      int j = min((int)(it - v.begin()), i - 1);
      while (j >= 0) {
        if (!used[j] && v[j] <= lim) {
          used[j] = true;
          break;
        }
        j--;
      }

      /*
      for (int j = min(it - v.begin(), N - 1); j >= 0; j--) {
        if (!used[j] && v[j] <= lim) {
          used[j] = true;
          break;
        }
      }
      */
      cases++;
    }
  }

  cout << cases << endl;
  return 0;
}

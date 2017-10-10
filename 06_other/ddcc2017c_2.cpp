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
  for (int i = 0; i < N; i++) {
    int l;
    cin >> l;
    v.push_back(l);
  }

  std::sort(v.begin(), v.end());

  int cases = 0;
  int j = 0;

  for (int i = N - 1; i >= j; i--) {
    int lim = C - v[i] - 1;
    if (v[j] <= lim) {
      j++;
    }
    cases++;
  }

  cout << cases << endl;
  return 0;
}

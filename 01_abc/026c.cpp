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

int N;
int B[22] = {};
int s[22] = {};

int salary(int p) {
  if (s[p] > 0) {
    return s[p];
  }

  vector<int> buka;
  REP(i, N) {
    if (B[i] == p && i != p) {
      buka.push_back(i);
    }
  }
  // DEBUG(buka);
  if (buka.size() == 0) {
    s[p] = 1;
  } else {
    int mi = salary(buka[0]);
    int ma = salary(buka[0]);
    for (int i = 1; i < buka.size(); i++) {
      mi = min(mi, salary(buka[i]));
      ma = max(ma, salary(buka[i]));
    }
    s[p] = mi + ma + 1;
  }
  return s[p];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i < N; i++) {
    int b;
    cin >> b;
    b--;
    B[i] = b;
  }

  cout << salary(0) << endl;
  return 0;
}

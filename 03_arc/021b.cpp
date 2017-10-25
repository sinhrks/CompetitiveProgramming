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

  int L;
  cin >> L;

  int A[100010] = {};
  int B[100010] = {};
  REP(i, L) {
    cin >> B[i];
  }
  for (int i = 1; i < L; i++) {
    A[i] = B[i - 1] ^ A[i - 1];
  }
  if (A[0] == (B[L - 1] ^ A[L - 1])) {
    REP(i, L) {
      cout << A[i] << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}

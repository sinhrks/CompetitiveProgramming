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

ull T[100001] = {};
ull A[100001] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ull N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  if (T[N - 1] != A[0]) {
    cout << 0 << endl;
    return 0;
  }

  ull ans = 1;
  for (int i = 1; i < N - 1; i++) {
    if (T[i - 1] < T[i] && A[i] > A[i + 1]) {
      if (T[i] != A[i]) {
        cout << 0 << endl;
        return 0;
      }
    } else if (T[i - 1] < T[i] && A[i] == A[i + 1]) {
      if (T[i] > A[i]) {
        cout << 0 << endl;
        return 0;
      }
    } else if (T[i - 1] == T[i] && A[i] > A[i + 1]) {
      if (T[i] < A[i]) {
        cout << 0 << endl;
        return 0;
      }
    } else {
      ans *= min(A[i], T[i]);
      ans %= 1000000007;
    }
  }

/*
  ull ans = 1;
  for (int i = 1; i < N - 1; i++) {
    if (!(T[i - 1] < T[i] || A[i] > A[i + 1])) {
      ans *= min(A[i], T[i]);
      ans %= 1000000007;
    }
  }
  */

  cout << ans << endl;
  return 0;
}

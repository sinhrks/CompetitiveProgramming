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

  ll K;
  cin >> K;

  int N = 50;

  vector<ll> ans(N, 0);
  for (int j = 0; j < N; j++) {
    ans[j] = j + K / N;
  }
  ll remain = K % N;
  for (int j = 0; j < remain; j++) {
    ans[j] += N;
    for (int k = 0; k < N; k++) {
      if (k != j) {
        ans[k] -= 1;
      }
    }
  }
  cout << N << endl;
  for (int i = 0; i < N; i++) {
    cout << ans[i];
    if (i < N - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}

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

  ull N, K;
  cin >> N >> K;

  uint A[100001] = {};
  ull B[100001] = {};

  for (int i = 0; i < N; i++) {
    uint a;
    ll b;
    cin >> a >> b;
    A[i] = a;
    B[i] = b;
  }

  bitset<32> b;
  ll val = 0;

  for (int i = 0; i < 32; i++) {
    bitset<32> b(K);
    for (int j = 0; j < 32; j++) {
      if (j < i && (K >= (1 << i))) {
        b.set(j);
      } else if (j == i) {
        b.set(j, false);
      }
    }

    ll tmp = 0;
    for (int k = 0; k < N; k++) {
      if ((b | bitset<32>(A[k])) == b) {
        tmp += B[k];
      }
    }
    val = max(val, tmp);
  }
  cout << val << endl;
  return 0;
}

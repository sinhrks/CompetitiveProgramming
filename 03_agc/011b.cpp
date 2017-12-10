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

  int N;
  cin >> N;

  ull A[100001] = {};
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  int ans = 0;
  ull cum = 0;
  for (int i = 0; i < N - 1; i++) {
    cum += A[i];
    if (cum * 2 < A[i + 1]) {
      ans = i + 1;
    }
  }

  cout << N - ans << endl;
  return 0;
}

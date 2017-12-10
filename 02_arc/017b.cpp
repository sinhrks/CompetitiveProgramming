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

using namespace std;

int A[300000] = {};
int inc[300000] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  inc[0] = 1;
  for (int i = 1; i < N; i++) {
    if (A[i] > A[i - 1]) {
      inc[i] = inc[i - 1] + 1;
    } else {
      inc[i] = 1;
    }
  }

  int total = 0;
  for (int i = 0; i < N; i++) {
    if (inc[i] >= K) total++;
  }

  cout << total << endl;
  return 0;
}

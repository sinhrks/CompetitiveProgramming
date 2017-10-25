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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, A, B;
  cin >> N >> A >> B;

  ll X[100010] = {};
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }

  ll ma = 0;
  for (int i = 1; i < N; i++) {
    ma += min((X[i] - X[i - 1]) * A, B);
  }

  cout << ma << endl;
  return 0;
}

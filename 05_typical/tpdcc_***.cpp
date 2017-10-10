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

double dp[1024][11] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K;
  cin >> K;


  double R[1024] = {};
  cout << (1 << K) << endl;
  for (int i = 0; i < (1 << K); i++) {
    cin >> R[i];
  }
  for (int i = 0; i < (1 << K); i++) {
    dp[i][0] = 1.0;
  }
  for (int k = 1; k <= K; k++) {
    for (int g = 0; g < (1 << K); k += (1 << k)) {

    }
  }

  cout << "Yes" << endl;
  return 0;
}

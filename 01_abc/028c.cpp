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

int results[4][510] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int num[5] = {};
  cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];

  vector<int> results;
  REP(i, 5) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 5; k++) {
        if (i != k && k != j) {
          results.push_back(num[i] + num[k] + num[j]);
        }
      }
    }
  }
  sort(results.begin(), results.end());

  cout << results[results.size() - 3] << endl;
  return 0;
}

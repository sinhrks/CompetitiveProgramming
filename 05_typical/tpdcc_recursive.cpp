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
#define PRN(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int R[4010] = {};

double prob(int rp, int rq) {
  double ans = 1.0 / (1 + pow(10.0, (double)(rq - rp) / 400.0));
  return ans;
}

vector<double> search(int l, int r) {
  if (l == r) {
    return vector<double>(1, 1.0);
  }

  int m = (l + r) / 2;
  vector<double> lprob = search(l, m);
  vector<double> rprob = search(m + 1, r);

  // PRN(lprob);
  // PRN(rprob);

  int size = lprob.size();
  vector<double> results(size * 2, 0.0);
  REP(i, lprob.size()) {
    REP(j, rprob.size()) {
      // cout << m << " " << m + 1 + j << endl;
      results[i] += lprob[i] * rprob[j] * prob(R[l + i], R[m + 1 + j]);
      results[size + j] += rprob[j] * lprob[i] * prob(R[m + 1 + j], R[l + i]);
    }
  }
  return results;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K;
  cin >> K;

  REP(i, (1 << K)) {
    cin >> R[i];
  }
  vector<double> results = search(0, (1 << K) - 1);
  for (auto r : results) {
    printf("%.10f\n", r);
  }
  return 0;
}

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

int X[100010] = {};
int age[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  REP(i, N) {
    int order;
    cin >> order;
    X[i] = order;
    age[order] = i + 1;
  }

  priority_queue<int> p;
  REP(i, N) {
    p.push(X[i]);
    if (p.size() > K) {
      p.pop();
    }
    if (i >= K - 1) {
      int a = p.top();
      cout << age[a] << endl;
    }
  }
  return 0;
}

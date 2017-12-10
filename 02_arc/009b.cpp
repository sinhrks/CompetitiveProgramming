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

# define INF 0x3f3f3f3f

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int b[10] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 10) {
    int n;
    cin >> n;
    b[n] = i;
  }
  int N;
  cin >> N;

  vector<pair<ll, string>> nums;

  REP(i, N) {
    string s;
    cin >> s;

    ll n = 0;
    REP(j, s.size()) {
      n += b[s[j] - '0'];
      n *= 10;
    }
    nums.push_back(make_pair(n, s));
  }
  sort(nums.begin(), nums.end());
  REP(i, N) {
    cout << nums[i].second << endl;
  }
  return 0;
}

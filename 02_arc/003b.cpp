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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<pair<string, string>> dict;
  REP(i, N) {
    string s;
    cin >> s;

    string orig(s);
    reverse(s.begin(), s.end());
    dict.push_back(make_pair(s, orig));
  }
  sort(dict.begin(), dict.end());
  REP(i, N) {
    cout << dict[i].second << endl;
  }
  return 0;
}

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

  map<char, int> m;
  m['b'] = 1;
  m['c'] = 1;
  m['d'] = 2;
  m['w'] = 2;
  m['t'] = 3;
  m['j'] = 3;
  m['f'] = 4;
  m['q'] = 4;
  m['l'] = 5;
  m['v'] = 5;
  m['s'] = 6;
  m['x'] = 6;
  m['p'] = 7;
  m['m'] = 7;
  m['h'] = 8;
  m['k'] = 8;
  m['n'] = 9;
  m['g'] = 9;
  m['z'] = 0;
  m['r'] = 0;

  int N;
  cin >> N;
  cin.ignore();
  string s;
  getline(cin, s);

  string result("");
  REP(i, s.size()) {
    char c = tolower(s[i]);
    if (c == ' ') result += ' ';
    else if (m.find(c) != m.end()) {
      result += to_string(m[c]);
    }
  }
  bool started = false;
  REP(i, result.size()) {
    if (result[i] == ' ') {
      if (i < result.size() - 1 && result[i + 1] != ' ' && started) {
        cout << result[i];
      }
    } else {
      cout << result[i];
      started = true;
    }
  }

  cout << endl;
  return 0;
}

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

using namespace std;

bool is_alpha(char c) {
  return ('A' <= c && c <= 'Z');
}

string replace(string s, char from, char to) {
  REP(i, s.size()) {
    if (s[i] == from) {
      s[i] = to;
    }
  }
  return s;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  string s1, s2;
  cin >> s1 >> s2;

  map<char, char> mapper;

  bool updated = true;
  while (updated) {
    updated = false;
    REP(i, N) {
      // cout << s1[i] << " " << s2[i] << endl;
      if (s1[i] != s2[i]) {
        char c1 = s1[i];
        char c2 = s2[i];
        if (is_alpha(c1) && !is_alpha(c2)) {
          updated = true;
          s1 = replace(s1, c1, c2);
        }
        if (!is_alpha(c1) && is_alpha(c2)) {
          updated = true;
          s2 = replace(s2, c2, c1);
        }
      }
    }
  }

  updated = true;
  while (updated) {
    updated = false;
    REP(i, N) {
      if (s1[i] != s2[i]) {
        char c1 = s1[i];
        char c2 = s2[i];
        if (is_alpha(c1) && is_alpha(c2)) {
          updated = true;
          s1 = replace(s1, c1, c2);
        }
      }
    }
  }
  set<char> se;
  for (int i = 0; i < N; i++) {
    if (is_alpha(s1[i])) {
      se.insert(s1[i]);
    }
  }

  ll ans = 1;
  if (se.size() == 0) {
    ans = 1;
  } else if (is_alpha(s1[0])) {
    ans *= 9;
    if (se.size() > 1) {
      ans *= (se.size() - 1) * 10;
    }
  } else {
    ans *= se.size() * 10;
  }

  cout << ans << endl;
  return 0;
}

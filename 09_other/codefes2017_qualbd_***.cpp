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

string S;
bool s[500010] = {};

int search(int start, int end) {
  for (int i = start; i <= end; i++) {
    s[i] = S[i] - '0';
  }

  int total1 = 0;
  for (int i = start; i <= end - 2; i++) {
    if (s[i] && !s[i + 1] && s[i + 2]) {
      total1++;
      s[i] = false;
      s[i + 1] = true;
      s[i + 2] = false;
      i = max(i - 2, start);
    }
  }

  for (int i = start; i <= end; i++) {
    s[i] = S[i] - '0';
  }
  int total2 = 0;
  for (int i = end - 2; i >= start; i--) {
    if (s[i] && !s[i + 1] && s[i + 2]) {
      total2++;
      s[i] = false;
      s[i + 1] = true;
      s[i + 2] = false;
      i = min(i + 2, end - 2);
    }
  }
  return max(total1, total2);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  cin >> S;

  for (int i = 0; i <= N; i++) {
    s[i] = S[i] - '0';
  }

  int total = 0;
  int current = 0;

  for (int i = 0; i < N - 1; i++) {
    if (i == N - 2) {
      total += search(current, N - 1);
    } else if (s[i] == 0 && s[i + 1] == 0) {
      total += search(current, i);
      current = i + 1;
    }
  }

  cout << total << endl;
  return 0;
}

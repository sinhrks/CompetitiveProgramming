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

template<class T>
bool is_prime(T n) {
  switch (n) {
    case 0: return false;
    case 1: return false;
    case 2: return true;
    case 3: return true;
  }
  if (n % 2 == 0) return false;
  if (n % 3 == 0) return false;

  if (n % 6 != 1 && n % 6 != 5) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0) return false;
    if (n % (i + 2) == 0) return false;
  }
  return true;
}

bool is_dummy(int n) {
  if (n % 2 == 0) return false;
  if (n % 5 == 0) return false;
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  if (sum % 3 == 0) return false;
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  if (N == 1) {
    cout << "Not Prime" << endl;
  } else if (is_prime(N) || is_dummy(N)) {
    cout << "Prime" << endl;
  } else {
    cout << "Not Prime" << endl;
  }
  return 0;
}

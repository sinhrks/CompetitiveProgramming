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

using namespace std;

int get_days_in_month(int y, int m) {
  assert(m >= 1 && m <= 12);
  int days[12] = {31, 29, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};
  return days[m - 1];
}

int get_day_of_year(int y, int m, int d) {
  assert(m >= 1 && m <= 12);
  assert(d >= 1 && d <= get_days_in_month(y, m));
  for (int i = 1; i < m; i++) {
    d += get_days_in_month(2012, i);
  }
  return d;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    scanf("%d", &N);

    set<int> s;
    for (int i = 0; i < N; i++) {
      int m, d;
      scanf("%d/%d", &m, &d);
      s.insert(m * 100 + d);
    }

    bool holidays[366] = {};
    int cursor = 0;
    int weekday = 0;
    for (int m = 0; m < 12; m++) {
      int days = get_days_in_month(2012, m + 1);
      for (int d = 0; d < days; d++) {
        if (weekday == 0 || weekday == 6) {
          holidays[cursor] = true;
        }
        cursor++;
        weekday = (weekday + 1) % 7;
      }
    }

    for (auto& r : s) {
      int m = r / 100;
      int d = r % 100;
      d = get_day_of_year(2012, m, d) - 1;
      while (holidays[d]) {
        d++;
      }
      if (d < 366) {
        holidays[d] = true;
      }
    }

    int m = 0;
    int current = 0;
    for (int i = 0; i < 366; i++) {
      if (holidays[i]) {
        current++;
      } else {
        current = 0;
      }
      m = max(m, current);
    }
    cout << m << endl;
    return 0;
}

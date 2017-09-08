#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

// 日付処理
class MyDate{
 public:
  int day;
  int month;
  int year;

  MyDate tomorrow();

  MyDate(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
  }
};

// 閏年かどうか調べる
bool is_leap(int y) {
  if ((y % 400) == 0) {
    return true;
  } else if ((y % 100) == 0) {
    return false;
  } else if ((y % 4) == 0) {
    return true;
  }
  return false;
}

int get_days_in_month(int y, int m) {
  int days[] = {31, 28, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31};
  if (m == 2) {
    return is_leap(y) ? days[1] + 1 : days[1];
  } else {
    return days[m - 1];
  }
}

// 翌日の日付を返す
MyDate MyDate::tomorrow() {
  int td, tm, ty;
  td = day;
  tm = month;
  ty = year;

  td++;
  if (td > get_days_in_month(year, month)) {
    td = 1;
    tm++;
    if (tm > 12) {
      ty++;
      tm = 1;
    }
  }
  return MyDate(ty, tm, td);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    while (true) {
      if (y % (m * d) == 0) {
        printf("%d/%02d/%02d\n", y, m, d);
        return 0;
      }
      MyDate dt(y, m, d);
      MyDate tm = dt.tomorrow();
      y = tm.year;
      m = tm.month;
      d = tm.day;
    }
    return 0;
}

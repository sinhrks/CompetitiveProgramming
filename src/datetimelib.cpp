#include <assert.h>
#include <iostream>

using namespace std;

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

// ある年月の日数を返す
int get_days_in_month(int y, int m) {
  assert(m >= 1 && m <= 12);
  int days[] = {31, 28, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31};
  if (m == 2 && is_leap(y)) {
    return days[1] + 1;
  }
  return days[m - 1];
}

// ある日付の day of year を返す
int get_day_of_year(int y, int m, int d) {
  assert(m >= 1 && m <= 12);
  assert(d >= 1 && d <= get_days_in_month(y, m));
  for (int i = 1; i < m; i++) {
    d += get_days_in_month(y, i);
  }
  return d;
}

// 日付処理
struct MyDate{
  int day;
  int month;
  int year;

  MyDate(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
  }

  MyDate tomorrow() {
    int td = day, tm = month, ty = year;
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
};
bool operator==(const MyDate &lhs, const MyDate &rhs) {
  return (lhs.year == rhs.year) &&
         (lhs.month == rhs.month) &&
         (lhs.day == rhs.day);
}
bool operator!=(const MyDate &lhs, const MyDate &rhs) {
  return !(lhs == rhs);
}

void test_leap() {
  assert(!is_leap(1999));
  assert(is_leap(2000));
  assert(!is_leap(2001));
  assert(is_leap(2004));
  assert(!is_leap(2100));
}

void test_days_in_month() {
  assert(get_days_in_month(1999, 1) == 31);
  assert(get_days_in_month(1999, 2) == 28);
  assert(get_days_in_month(1999, 3) == 31);
  assert(get_days_in_month(1999, 4) == 30);
  assert(get_days_in_month(1999, 5) == 31);
  assert(get_days_in_month(1999, 6) == 30);
  assert(get_days_in_month(1999, 7) == 31);
  assert(get_days_in_month(1999, 8) == 31);
  assert(get_days_in_month(1999, 9) == 30);
  assert(get_days_in_month(1999, 10) == 31);
  assert(get_days_in_month(1999, 11) == 30);
  assert(get_days_in_month(1999, 12) == 31);

  assert(get_days_in_month(2004, 1) == 31);
  assert(get_days_in_month(2004, 2) == 29);
  assert(get_days_in_month(2004, 3) == 31);
  assert(get_days_in_month(2004, 4) == 30);
  assert(get_days_in_month(2004, 5) == 31);
  assert(get_days_in_month(2004, 6) == 30);
  assert(get_days_in_month(2004, 7) == 31);
  assert(get_days_in_month(2004, 8) == 31);
  assert(get_days_in_month(2004, 9) == 30);
  assert(get_days_in_month(2004, 10) == 31);
  assert(get_days_in_month(2004, 11) == 30);
  assert(get_days_in_month(2004, 12) == 31);
}

void test_day_of_year() {
  assert(get_day_of_year(1999, 1, 1) == 1);
  assert(get_day_of_year(1999, 1, 2) == 2);
  assert(get_day_of_year(1999, 2, 1) == 32);
  assert(get_day_of_year(1999, 3, 1) == 60);
  assert(get_day_of_year(1999, 12, 31) == 365);

  assert(get_day_of_year(2004, 1, 1) == 1);
  assert(get_day_of_year(2004, 1, 2) == 2);
  assert(get_day_of_year(2004, 2, 1) == 32);
  assert(get_day_of_year(2004, 3, 1) == 61);
  assert(get_day_of_year(2004, 12, 31) == 366);
}

void test_mydate() {
  assert(MyDate(1999, 1, 1) == MyDate(1999, 1, 1));
  assert(MyDate(1999, 1, 1) != MyDate(1999, 1, 2));

  assert(MyDate(1999, 1, 1).tomorrow() == MyDate(1999, 1, 2));
  assert(MyDate(1999, 2, 28).tomorrow() == MyDate(1999, 3, 1));
  assert(MyDate(2000, 12, 31).tomorrow() == MyDate(2001, 1, 1));

  assert(MyDate(2004, 1, 1).tomorrow() == MyDate(2004, 1, 2));
  assert(MyDate(2004, 2, 28).tomorrow() == MyDate(2004, 2, 29));
  assert(MyDate(2004, 2, 29).tomorrow() == MyDate(2004, 3, 1));
  assert(MyDate(2004, 12, 31).tomorrow() == MyDate(2005, 1, 1));
}

int main() {
  test_leap();
  test_days_in_month();
  test_day_of_year();
  test_mydate();

  cout << "SUCCESS!!" << endl;
  return 0;
}

#include <assert.h>
#include <iostream>

using namespace std;

// width の範囲で右回転シフト
template<class val>
unsigned rrotshift(val x, int n, int width) {
  assert(width > 0);
  n = n % width;
  if (n == 0) {
    return x;
  }
  val mask = (~((~0) << width));
  n %= width;
  return ((x >> n) | (x << (width - n)) & mask);
}

// width の範囲で左回転シフト
template<class val>
unsigned lrotshift(val x, int n, int width) {
  assert(width > 0);
  n = n % width;
  if (n == 0) {
    return x;
  }
  val mask = (~((~0) << width));
  n %= width;
  return ((x << n) & mask | (x >> (width - n)));
}

int main() {
  assert(rrotshift(3, 1, 4) == 9);
  assert(rrotshift(3, 2, 4) == 12);
  assert(rrotshift(3, 3, 4) == 6);
  assert(rrotshift(3, 4, 4) == 3);
  assert(rrotshift(3, 12, 4) == 3);
  assert(rrotshift(3, 13, 4) == 9);

  assert(lrotshift(3, 1, 4) == 6);
  assert(lrotshift(3, 2, 4) == 12);
  assert(lrotshift(3, 3, 4) == 9);
  assert(lrotshift(3, 4, 4) == 3);
  assert(lrotshift(3, 13, 4) == 6);
  assert(lrotshift(3, 14, 4) == 12);

  assert(lrotshift(5, 1, 4) == 10);
  assert(lrotshift(5, 2, 4) == 5);

  cout << "SUCCESS!!" << endl;
  return 0;
}

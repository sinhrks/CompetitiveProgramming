#include <assert.h>
#include <iostream>
#include <map>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<class key, class val>
map<val, key> map_inverse(const map<key, val>& from) {
map<val, key> result;
  for (auto& kv : from) {
    result[kv.second] = kv.first;
  }
  return result;
}

template <typename T>
struct Counter {
  map<T, ull> cnt;
  void add(T key) {
    if (cnt.count(key)) {
      cnt[key]++;
    } else {
      cnt[key] = 1;
    }
  }
  ll get(T key) {
    if (cnt.count(key)) {
      return cnt[key];
    } else {
      return 0;
    }
  }
  typename map<T, ll>::iterator begin() {
    return cnt.begin();
  }
  typename map<T, ll>::iterator end() {
    return cnt.end();
  }
  typename map<T, ll>::reverse_iterator rbegin() {
    return cnt.rbegin();
  }
  typename map<T, ll>::reverse_iterator rend() {
    return cnt.rend();
  }
};

void test_inverse() {
  map<int, int> input;
  input[1] = 3;
  input[2] = 1;
  map<int, int> result = map_inverse(input);

  map<int, int> ex;
  ex[3] = 1;
  ex[1] = 2;
  assert(result == ex);
}

void test_counter() {
  Counter<int> c;
  c.add(1);
  c.add(1);
  c.add(2);

  map<int, ull> ex;
  ex[1] = 2;
  ex[2] = 1;
  assert(c.cnt == ex);
  assert(c.get(1) == 2);
  assert(c.get(3) == 0);
}

int main() {
  test_inverse();
  test_counter();

  cout << "SUCCESS!!" << endl;
  return 0;
}

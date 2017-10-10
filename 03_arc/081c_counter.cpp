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


template <typename T>
struct Counter {
  map<T, ll> cnt;
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


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  Counter<int> counter;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    counter.add(a);
  }

  ll first = 0;
  ll second = 0;

  for (auto it = counter.rbegin(); it!= counter.rend(); it++) {
    if (it->second >= 2) {
      if (first == 0) {
        first = it->first;
        if (it->second >= 4) {
          second = it->first;
          break;
        }
      } else if (second == 0) {
        second = it->first;
        break;
      }
    }
  }

  cout << first * second << endl;
  return 0;
}

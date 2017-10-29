#include <assert.h>
#include <iostream>
#include <numeric>
#include <map>
#include <vector>

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
vector<int> argsort(const vector<T> &values) {
  vector<int> idx(values.size());
  iota(idx.begin(), idx.end(), 0);

  sort(idx.begin(), idx.end(),
       [&values](size_t i1, size_t i2) { return values[i1] < values[i2]; });

  return idx;
}

// カウンター
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
  void add(vector<T> keys) {
    for (auto key : keys) {
      add(key);
    }
  }
  ll get(T key) {
    if (cnt.count(key)) {
      return cnt[key];
    } else {
      return 0;
    }
  }
  pair<T, ull> max() {
    T key;
    ull mx = 0;
    for (auto kv : cnt) {
      if (kv.second > mx) {
        mx = kv.second;
        key = kv.first;
      }
    }
    return make_pair(key, mx);
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

template <typename T>
vector<T> uniquify(vector<T> values) {
  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());
  return values;
}

// 座標圧縮
template <typename T>
struct Compressor {
  map<T, int> compressor;
  vector<T> extractor;

  explicit Compressor(vector<T> originals) {
    vector<T> u = uniquify(originals);

    extractor = vector<T>(u.size(), 0);
    for (int i = 0; i < static_cast<int>(u.size()); i++) {
      compressor[u[i]] = i;
      extractor[i] = u[i];
    }
  }
  int size() {
    return static_cast<int>(compressor.size());
  }
  int compress(T value) {
    return compressor[value];
  }
  vector<int> compress(const vector<T> &values) {
    // <int> を返したいので for_each は使えない
    vector<int> results(values.size());
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
      results[i] = compress(values[i]);
    }
    return results;
  }
  // 座標圧縮後の各コードが、valuesの圧縮により現れるかどうかを返す
  vector<bool> compress_as_flag(const vector<T> &values) {
    vector<bool> results(this->size(), false);
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
      results[compress(values[i])] = true;
    }
    return results;
  }
  T extract(int index) {
    return extractor[index];
  }
};

template <typename T>
vector<T> accum_vec(const vector<T> &values) {
  vector<T> accumulated(values.size(), 0);
  accumulated[0] = values[0];
  for (int i = 1; i < static_cast<int>(values.size()); i++) {
    accumulated[i] = accumulated[i - 1] + values[i];
  }
  return accumulated;
}

// 累積和法 (1次元)
template <typename T>
struct Accumulator {
  vector<T> accumulated;

  explicit Accumulator(const vector<T> &values) {
    accumulated = accum_vec(values);
  }
  // from の後から to までの要素を合計する
  // (from, toは含まれる)
  T sum(int from, int to) {
    assert(0 <= from && from <= to);
    assert(to < static_cast<int>(accumulated.size()));
    if (from == 0) {
      return accumulated[to];
    } else {
      return accumulated[to] - accumulated[from - 1];
    }
  }
};

// 累積和法 (2次元)
template <typename T>
struct Accumulator2D {
  vector<vector<T>> accumulated;

  explicit Accumulator2D(const vector<vector<T>> &values) {
    accumulated = vector<vector<T>>(values.size());

    accumulated[0] = accum_vec(values[0]);
    for (int i = 1; i < static_cast<int>(values.size()); i++) {
      accumulated[i] = accum_vec(values[i]);
      for (int j = 0; j < static_cast<int>(values[i].size()); j++) {
        accumulated[i][j] += accumulated[i - 1][j];
      }
    }
  }
  // (x1, y1) の後から (x2, y2) までの要素を合計する
  // (x1, y1, x2, y2は含まれる)
  T sum(int x1, int y1, int x2, int y2) {
    assert(0 <= x1 && x1 <= x2);
    assert(x2 < static_cast<int>(accumulated[0].size()));
    assert(0 <= y1 && y1 <= y2);
    assert(y2 < static_cast<int>(accumulated.size()));

    T result = accumulated[y2][x2];
    if (x1 != 0) result -= accumulated[y2][x1 - 1];
    if (y1 != 0) result -= accumulated[y1 - 1][x2];
    if (x1 != 0 && y1 != 0) result += accumulated[y1 - 1][x1 - 1];
    return result;
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

void test_argsort() {
  vector<int> v1 = {1, 4, 2, 0};
  vector<int> e1 = {3, 0, 2, 1};
  assert(argsort(v1) == e1);

  vector<int> v2 = {1, 2, 2, 0};
  vector<int> e2 = {3, 0, 1, 2};
  assert(argsort(v2) == e2);

  vector<int> v3 = {1, 1, 1, 1};
  vector<int> e3 = {0, 1, 2, 3};
  assert(argsort(v3) == e3);

  vector<int> v4 = {};
  vector<int> e4 = {};
  assert(argsort(v4) == e4);
}

void test_uniquify() {
  vector<int> v1 = {1, 4, 4, 1, 2};
  vector<int> e1 = {1, 2, 4};
  assert(uniquify(v1) == e1);

  vector<int> v2 = {1, 1, 1, 1};
  vector<int> e2 = {1};
  assert(uniquify(v2) == e2);

  vector<int> v3 = {1};
  vector<int> e3 = {1};
  assert(uniquify(v3) == e3);

  vector<int> v4 = {};
  vector<int> e4 = {};
  assert(uniquify(v4) == e4);

  vector<string> v5 = {"aa", "bb", "aa", "cc", "bb"};
  vector<string> e5 = {"aa", "bb", "cc"};
  assert(uniquify(v5) == e5);
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

void test_counter2() {
  Counter<string> c;
  vector<string> v = {"a", "bb", "a", "ccc"};
  c.add(v);

  map<string, ull> ex;
  ex["a"] = 2;
  ex["bb"] = 1;
  ex["ccc"] = 1;
  assert(c.cnt == ex);
  assert(c.get("a") == 2);
  pair<string, ull> p = make_pair("a", 2);
  assert(c.max() == p);
}

void test_compressor() {
  vector<int> v = {10, 30, 10, 40};
  Compressor<int> c(v);

  // 破壊的に変更しない
  assert(v[0] == 10);
  assert(v[1] == 30);
  assert(v[2] == 10);
  assert(v[3] == 40);

  assert(c.compress(10) == 0);
  assert(c.compress(30) == 1);
  assert(c.compress(40) == 2);

  assert(c.extract(0) == 10);
  assert(c.extract(1) == 30);
  assert(c.extract(2) == 40);

  vector<int> i = {30, 40, 10};
  vector<int> e = {1, 2, 0};
  assert(c.compress(i) == e);
  // 破壊的に変更しない
  assert(i[0] == 30);
  assert(i[1] == 40);
  assert(i[2] == 10);

  vector<int> i2 = {30, 40, 30};
  vector<bool> e2 = {false, true, true};
  assert(c.compress_as_flag(i2) == e2);

  vector<int> i3 = {30};
  vector<bool> e3 = {false, true, false};
  assert(c.compress_as_flag(i3) == e3);
}

void test_compressor_string() {
  return;
  vector<string> v3 = {"aa", "bb", "aa", "cc"};
  Compressor<string> c3(v3);
  assert(c3.compress("aa") == 0);
  assert(c3.compress("bb") == 1);
  assert(c3.compress("cc") == 2);
  assert(c3.extract(0) == "aa");
  assert(c3.extract(1) == "bb");
  assert(c3.extract(2) == "cc");
}

void test_accumulate() {
  vector<int> v = {3, 2, 5, 10};
  Accumulator<int> a(v);
  assert(a.sum(0, 0) == 3);
  assert(a.sum(0, 2) == 10);
  assert(a.sum(1, 3) == 17);
  assert(a.sum(2, 3) == 15);
  assert(a.sum(3, 3) == 10);
}

void test_accumulate2D() {
  vector<int> v1 = {1, 0, 2, 5, 3};
  vector<int> v2 = {0, 2, 3, 1, 2};
  vector<int> v3 = {1, 1, 2, 2, 4};
  vector<int> v4 = {0, 3, 1, 0, 1};
  vector<vector<int>> v = {v1, v2, v3, v4};

  Accumulator2D<int> a(v);
  assert(a.sum(0, 0, 0, 0) == 1);
  assert(a.sum(0, 0, 1, 1) == 3);
  assert(a.sum(0, 0, 1, 2) == 5);
  assert(a.sum(0, 0, 2, 1) == 8);

  assert(a.sum(0, 0, 4, 3) == 34);
  assert(a.sum(1, 1, 4, 3) == 22);
  assert(a.sum(2, 2, 4, 3) == 10);
  assert(a.sum(4, 3, 4, 3) == 1);
  assert(a.sum(3, 0, 3, 0) == 5);

  assert(a.sum(0, 2, 4, 3) == 15);
  assert(a.sum(0, 3, 4, 3) == 5);

  assert(a.sum(1, 0, 4, 3) == 32);
  assert(a.sum(2, 0, 4, 3) == 26);
  assert(a.sum(4, 0, 4, 3) == 10);
}

int main() {
  test_inverse();
  test_argsort();
  test_uniquify();
  test_counter();
  test_counter2();
  test_compressor();
  test_compressor_string();
  test_accumulate();
  test_accumulate2D();

  cout << "SUCCESS!!" << endl;
  return 0;
}

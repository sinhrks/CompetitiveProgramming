#include <assert.h>
#include <iostream>
#include <numeric>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

struct SuffixArray {
  string s;
  int n;
  vector<int> sa;
  vector<int> lcp;
  vector<int> rank;

  explicit SuffixArray(string s) {
    this->s = s;
    this->n = s.length();
  }
  // (rank[i], rank[i + k])と(rank[j], rank[j + k])を比較
  bool compare_sa(int i, int j, int k) {
    if (rank[i] != rank[j]) {
      return rank[i] < rank[j];
    } else {
      int ri = i + k <= n ? rank[i + k] : -1;
      int rj = j + k <= n ? rank[j + k] : -1;
      return ri < rj;
    }
  }
  // 文字列Sの接尾辞配列を構築
  void construct_sa() {
    sa = vector<int>(n + 1);
    iota(sa.begin(), sa.end(), 0);

    rank = vector<int>(n + 1);
    // 最初は1文字、ランクは文字コードにすればよい
    for (int i = 0; i <= n; i++) {
      rank[i] = i < n ? s[i] : -1;
    }
    vector<int> tmp(n + 1, 0);
    // k文字についてソートされているところから、2k文字でソートする
    for (int k = 1; k <= n; k *= 2) {
      sort(sa.begin(), sa.end(),
           [this, k](int i, int j){
             return compare_sa(i, j, k);
           });
      // いったんtmpに次のランクを計算し、それからrankに移す
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; i++) {
        if (compare_sa(sa[i - 1], sa[i], k)) {
          tmp[sa[i]] = tmp[sa[i - 1]] + 1;
        } else {
          tmp[sa[i]] = tmp[sa[i - 1]];
        }
      }
      for (int i = 0; i <= n; i++) {
        rank[i] = tmp[i];
      }
    }
  }
  // s が t を含むか調べる
  bool contain(string t) {
    int a = 0, b = s.length();
    while (b - a > 1) {
      int c = (a + b) / 2;
      // Sのsa[c]文字目から|T|文字とTを比較
      if (s.compare(sa[c], t.length(), t) < 0) {
        a = c;
      } else {
        b = c;
      }
    }
    return s.compare(sa[b], t.length(), t) == 0;
  }
  // 文字列Sとその接尾辞配列saを受け取り、高さ配列をlcpに計算
  void construct_lcp() {
    rank = vector<int>(n + 1);
    for (int i = 0; i <= n; i++) {
      rank[sa[i]] = i;
    }
    lcp = vector<int>(n + 1, 0);

    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
      // 文字列中での位置iの接尾辞と、接尾辞配列中でその1つ前の接尾辞のLCPを求める
      int j = sa[rank[i] - 1];
      // hを先頭の分1減らし、後ろが一致しているだけ増やす
      if (h > 0) h--;
      for (; j + h < n && i + h < n; h++) {
        if (s[j + h] != s[i + h]) break;
      }
      lcp[rank[i] - 1] = h;
    }
  }
};

void test_suffix_array() {
  string q = "abracadabra";
  SuffixArray sa(q);
  sa.construct_sa();

  vector<int> e = {11, 10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2};
  assert(sa.sa == e);

  assert(sa.contain("abra"));
  assert(!sa.contain("abrad"));
  assert(sa.contain("cadabra"));
}

void test_suffix_array_lcp() {
  string q = "abracadabra";
  SuffixArray sa(q);
  sa.construct_sa();
  sa.construct_lcp();

  vector<int> e = {0, 1, 4, 1, 1, 0, 3, 0, 0, 0, 2, 0};
  assert(sa.lcp == e);
}

vector<bool> ambiguous_match(string target, string query, char ignore) {
  vector<bool> ans(target.size(), false);
  if (target.size() < query.size()) return ans;

  for (int i = 0; i < static_cast<int>(target.size() - query.size()) + 1; i++) {
    bool m = true;
    for (int j = 0; j < static_cast<int>(query.size()); j++) {
      if (target[i + j] == ignore || target[i + j] == query[j]) {
        continue;
      } else {
        m = false;
        // i += max(j - 1, 0);
        break;
      }
    }
    if (m) {
      ans[i] = true;
    }
  }
  return ans;
}

void test_ambiguous_match() {
  vector<bool> e1 = {true, true, true, true, true};
  assert(ambiguous_match("aaaaa", "a", '?') == e1);

  vector<bool> e2 = {true, true, true, true, false};
  assert(ambiguous_match("aaaaa", "aa", '?') == e2);

  vector<bool> e3 = {true, true, false, false, false};
  assert(ambiguous_match("aaaaa", "aaaa", '?') == e3);

  vector<bool> e4 = {true, false, false, false, false};
  assert(ambiguous_match("aaaaa", "aaaaa", '?') == e4);

  vector<bool> e5 = {false, false, false, false, false};
  assert(ambiguous_match("aaaaa", "aaaaaaa", '?') == e5);

  vector<bool> e6 = {false, false, false, true, false, false};
  assert(ambiguous_match("abaabc", "abc", '?') == e6);

  vector<bool> e7 = {true, false, false, true, false, false};
  assert(ambiguous_match("abcabc", "abc", '?') == e7);

  vector<bool> e8 = {false, false, true, false, false, false};
  assert(ambiguous_match("ababcc", "abc", '?') == e8);

  vector<bool> e9 = {false, false, false, false, true, false, false, false};
  assert(ambiguous_match("aaabaaaa", "aaaa", '?') == e9);
}

void test_ambiguous_match2() {
  vector<bool> e1 = {true, true, true, true, true};
  assert(ambiguous_match("?a?a?", "a", '?') == e1);

  vector<bool> e2 = {true, true, true, true, false};
  assert(ambiguous_match("?a?a?", "aa", '?') == e2);

  vector<bool> e3 = {true, true, false, false, false};
  assert(ambiguous_match("?????", "aaaa", '?') == e3);

  vector<bool> e4 = {true, false, false, false, false};
  assert(ambiguous_match("?????", "aaaaa", '?') == e4);

  vector<bool> e5 = {false, false, false, false, false};
  assert(ambiguous_match("?????", "aaaaaaa", '?') == e5);

  vector<bool> e6 = {true, false, true, false, false};
  assert(ambiguous_match("ab?bc", "abc", '?') == e6);

  vector<bool> e7 = {true, true, false, true, false, false};
  assert(ambiguous_match("????bc", "abc", '?') == e7);

  vector<bool> e8 = {true, false, true, false, false, false};
  assert(ambiguous_match("ab?b?c", "abc", '?') == e8);

  vector<bool> e9 = {true, true, true, true, true, false, false, false};
  assert(ambiguous_match("aaa?aaaa", "aaaa", '?') == e9);
}

int main() {
  test_suffix_array();
  test_suffix_array_lcp();
  test_ambiguous_match();
  test_ambiguous_match2();

  cout << "SUCCESS!!" << endl;
  return 0;
}

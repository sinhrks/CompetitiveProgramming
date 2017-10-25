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

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  set<string> words;
  string last = "";
  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    if (i > 0) {
      if (word[0] != last[last.size() - 1] || words.find(word) != words.end()) {
        if (i % 2 == 1) {
          cout << "WIN" << endl;
        } else {
          cout << "LOSE" << endl;
        }
        return 0;
      }
    }
    words.insert(word);
    last = word;
  }
  cout << "DRAW" << endl;
  return 0;
}

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int cnt = 0;

    for (int i = 0; i < N; i++) {
      string word;
      cin >> word;

      if (word[word.size() - 1] == '.') {
        word = word.substr(0, word.size() - 1);
      }

      if (word == "TAKAHASHIKUN" ||
          word == "Takahashikun" ||
          word == "takahashikun") {
            cnt++;
          }

    }

    cout << cnt << endl;
    return 0;
}

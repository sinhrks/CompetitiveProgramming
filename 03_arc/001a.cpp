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
    string s;
    cin >> s;

    int correct[4] = {};

    for (int i = 0; i < N; i++) {
      if (s[i] == '1') {
        correct[0]++;
      } else if (s[i] == '2') {
        correct[1]++;
      } else if (s[i] == '3') {
        correct[2]++;
      } else if (s[i] == '4') {
        correct[3]++;
      }
    }
    int ma = *max_element(correct, correct + 4);
    int mi = *min_element(correct, correct + 4);
    cout << ma << " " << mi << endl;
    return 0;
}

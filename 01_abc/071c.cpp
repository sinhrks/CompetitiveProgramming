#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long bars[100000] = {0};

    long long i;
    for (i = 0; i < N; i++) {
        int c;
        cin >> bars[i];
    }
    sort(bars, bars + N, greater<long long>());

    long long first = 0;
    long long second = 0;

    for (i = 0; i < N; i++) {
      if (bars[i] == bars[i+1]) {
          if (first == 0) {
              first = bars[i];
              i++;
          } else {
              second = bars[i];
              cout << first * second << endl;
              return 0;
          }
      }
    }

    cout << 0 << endl;
    return 0;
}

#include<iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int counts[100000] = {0};

    int i;

    for (i = 0; i < N; i++) {
      int c;
      cin >> c;

      counts[c]++;
    }

    int ans = 0;
    for (i = 0; i < 99998; i++) {
        ans = max(ans, counts[i] + counts[i+1] + counts[i+2]);
    }

    cout << ans << endl;
    return 0;
}

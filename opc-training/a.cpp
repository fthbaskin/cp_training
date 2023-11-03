#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        mini = min(x, mini);
    }

    cout << sum - mini << "\n";

    return 0;
}

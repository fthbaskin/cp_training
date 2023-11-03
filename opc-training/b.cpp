#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int last_point;
    int total = 0;
    int n;
    cin >> n;
    int x;
    cin >> x;
    last_point = x;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x > last_point)
        {
            last_point = x;
            total += 1;
        }
    }
    cout << total;

    return 0;
}

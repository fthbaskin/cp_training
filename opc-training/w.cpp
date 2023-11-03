#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

ll fastexp(ll base, int pow)
{
    ll res = 1;
    while (pow)
    {
        if (pow & 1)
            res *= base;
        pow >>= 1;
        base *= base;
    }
    return res;
}

ll calc_poly(int m)
{
    return (ll)2 * (fastexp(3, m) - 1);
}

int calc_rem(ll rem, int pow)
{
    int ans = 0;
    ll sum = 0;
    while (sum < rem)
    {

        ll value = fastexp(3, pow);
        if (sum + value > rem)
        {
            pow -= 1;
            continue;
        }
        sum += value;
        ans += 1;
    }

    return ans;
}

int main()
{
    long long x;
    cin >> x;
    int l = 0;
    int r = 39;

    while (l < r)
    {
        int m = (l + r) / 2;

        ll val = calc_poly(m);
        if (val > x)
            r = m;
        else
            l = m + 1;
    }
    int poly_deg = l - 1;
    int poly_step = poly_deg * 2;
    ll poly_dist = calc_poly(poly_deg);

    cout << poly_step + calc_rem(x - poly_dist, poly_deg) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct compare_pair
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first < b.first)
        {
            return true;
        }
        else if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<pair<int, int>, compare_pair> set_edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        set_edges.insert({u, v});
    }

    set<pair<int, int>, compare_pair> result;
    for (auto p : set_edges)
    {
        if (set_edges.find({p.second, p.first}) != set_edges.end())
        {
            if (p.first > p.second)
                result.insert({p.second, p.first});
            else
                result.insert(p);
        }
    }

    cout << result.size() << '\n';
    for (auto p : result)
        cout << p.first << " " << p.second << '\n';

    return 0;
}
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define pii pair<int, int>
#define vi vector<int>
#define mod 1000000007
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000000000000
#define endl "\n"

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(k) : number of elements strictly lesser than k
// find_by_order(k) : k-th element in the set
// ordered_multiset, use pairs of (value, index)

void TEST_CASE()
{
    //UV3
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        TEST_CASE();
    }
    return 0;
}

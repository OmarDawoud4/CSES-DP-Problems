#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long


const long long LLINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const int mod = 998244353;

ll binpow(ll a, ll b, ll mod) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
        for (int i = c; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }
    cout << dp[x] << endl;
}

int main() {
    fastio

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}

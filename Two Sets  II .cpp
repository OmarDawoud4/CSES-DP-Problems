#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MOD 1000000007
const int N = 1005;


ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    ll total_sum = n * (n + 1) / 2;

    if (total_sum % 2 != 0) {
        cout << 0 << endl;
        return;
    }

    ll h_sum = total_sum / 2;
    vector<ll> dp(h_sum + 1, 0);
    dp[0] = 1; 

 
    for (int i = 1; i <= n; i++) {
        for (ll sub_sum = h_sum; sub_sum >= i; sub_sum--) {
            dp[sub_sum] = (dp[sub_sum] + dp[sub_sum - i]) % MOD;
        }
    }

 
    ll inverse_of_2 = mod_exp(2, MOD - 2, MOD);
    cout << (dp[h_sum] * inverse_of_2) % MOD << endl;
}

int main() {
    fastio;

    int tc = 1;
    // cin >> tc; 
    while (tc--) {
        solve();
    }

    return 0;
}

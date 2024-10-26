#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long

const long long LLINF = LLONG_MAX;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int u : coins) {
            if (i >= u)
                dp[i] = (dp[i] + dp[i - u]) % MOD;
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
}

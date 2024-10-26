#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>

const long long LLINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];

   
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i] == 0) {
                for (int v = 1; v <= m; v++) {
                    dp[i][v] = 1; 
                }
            } else {
                dp[i][a[i]] = 1; 
            }
        } else {
            if (a[i] == 0) {
                for (int v = 1; v <= m; v++) {
                    dp[i][v] = dp[i - 1][v]; 
                    if (v > 1) dp[i][v] = (dp[i][v] + dp[i - 1][v - 1]) % MOD; // left
                    if (v < m) dp[i][v] = (dp[i][v] + dp[i - 1][v + 1]) % MOD; // right
                }
            } else {
                dp[i][a[i]] = (dp[i - 1][a[i]] + (a[i] > 1 ? dp[i - 1][a[i] - 1] : 0) + (a[i] < m ? dp[i - 1][a[i] + 1] : 0)) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int val = 1; val <= m; val++) {
        ans = (ans + dp[n - 1][val]) % MOD;
    }

    cout << ans << endl;
}

int main() {
    fastio;
    
    int tc = 1;  
    // cin >> tc; 
    while (tc--) {
        solve();
    }
}

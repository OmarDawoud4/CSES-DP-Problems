#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long  

const long long LLINF = LLONG_MAX;  
const int INF = INT_MAX;  
const int MOD = 1e9 + 7;  
  
void solve() {  
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int cand = i;
        while (cand > 0) {
            int d = cand % 10;
            if (d) {
                dp[i] = min(dp[i], 1 + dp[i - d]);
            }
            cand = cand / 10;
        }
    }
    cout << dp[n] << endl;
}  
  
int main() {  
    fastio  

    int tc = 1;  
    // cin >> tc;  

    while (tc--) {  
        solve();  
    }  
}

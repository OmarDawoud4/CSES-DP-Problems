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
  
vector<int> dp;

int dice(int n) {
    dp.resize(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    return dp[n];
}
  
void solve() {  
    int n;
    cin >> n;
    cout << dice(n) << endl;
}  
  
int main() {  
    fastio;  
  
    int tc = 1;   
    // cin >> tc;  
    while (tc--) {  
        solve();  
    }  
  
}

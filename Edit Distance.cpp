#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define vi vector<int>
#define vl vector<long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const long long LLINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;

// Edit distance
int Lav_dis(string a, string b) {
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i; 
    for (int j = 0; j <= m; j++)
        dp[0][j] = j; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; 
            else {
                dp[i][j] = min({
                    dp[i - 1][j] + 1,    // Deletion
                    dp[i][j - 1] + 1,    // Insertion
                    dp[i - 1][j - 1] + 1  // Substitution
                });
            }
        }
    }
    return dp[n][m];
}

void solve() {
    string a, b;
    cin >> a >> b;
    cout << Lav_dis(a, b) << endl;
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

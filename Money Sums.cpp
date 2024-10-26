#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int MAX_SUM = 100000;

void solve() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<bool> dp(MAX_SUM + 1, false);
    dp[0] = true;  

   
    for (int coin : coins) {
        for (int sum = MAX_SUM; sum >= coin; sum--) {
            if (dp[sum - coin]) {
                dp[sum] = true;
            }
        }
    }

    vector<int> output;
    for (int sum = 1; sum <= MAX_SUM; sum++) {
        if (dp[sum]) {
            output.push_back(sum);
        }
    }

  
    cout << output.size() << endl;
    for (int s : output)
        cout << s << " ";
    cout << endl;
}

int main() {
    fastio;

    int tc = 1; 
    while (tc--) {
        solve();
    }

    return 0;
}

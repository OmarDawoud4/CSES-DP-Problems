 #include <bits/stdc++.h>
    using namespace std;
 
    #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    const int MAX_SUM = 100000;
 
    void solve()
    {
        int n,x;
        cin>>n>>x;
        vector<int>prices(n);
        vector<int>pages(n);
        for (int i = 0 ;i<n;i++)cin>>prices[i];
        for (int i = 0 ;i<n;i++)cin>>pages[i];
        vector<int>dp(x+1,0);
        dp[0]=0;
        for (int i =0 ;i<n;i++)
        {
           for (int price = x ; price >= prices [i];price -- )
           {
               dp[price]=max(dp[price],dp[price -prices[i]]+pages[i]);
           }
        }
        cout <<dp[x]<<endl;
    }
 
 
    int main() {
        fastio
         
        int tc = 1; // Number of test cases
      //cin>>tc;
        while (tc--) {
            solve();
        }
 
        return 0;
    }

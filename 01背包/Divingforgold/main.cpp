#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t ,d ;
    bool space = false ;
    while (cin >> t >> d) {
        if (space)
            cout << endl ;

        int n ;
        cin >> n ;
        vector<int> wt(n+1 ,0) ;
        vector<int> v(n+1 ,0) ;
        vector<vector<int>> dp(n+1 ,vector<int>(t+1 ,0)) ;
        //vector<int> dp(t+1 ,0) ;

        for (int i = 0 ; i < n ; i++){
            cin >> wt[i] ;
            wt[i] = wt[i]*3*d ;
            cin >> v[i] ;
        }
        for (int i = 1 ; i <= n ; i++){
            for (int w = 1 ; w <= t ; w++){
                if (wt[i-1] > w){
                    dp[i][w] = dp[i-1][w] ;
                }
                else{
                    dp[i][w] = max(dp[i-1][w-wt[i-1]]+v[i-1] ,dp[i-1][w]) ;
                }

            }
        }
       /* for (int i = 1 ; i <= n ; i++){
            for (int w = t ; w >= wt[i] ; w--){
                dp[w] = max(dp[w-wt[i-1]]+v[i-1] ,dp[i]) ;
            }
        }*/
        cout << dp[n][t] << endl ;

        vector<int> res ;
        int c = 0 ;
        function<void(int ,int)> path = [&](int n ,int t){
            if (n == 0)
                return ;
            else if (dp[n][t] == dp[n-1][t]){
                path(n-1 ,t) ;
            }
            else{
                c++ ;
                path(   n-1 ,t-wt[n-1]) ;
                res.emplace_back(n-1) ;
            }
            return ;
        };
        path(n ,t) ;

        cout << c << endl ;

        for (const auto &p : res){
            cout << wt[p]/(3*d) << " " << v[p] << endl ;
        }
        space = true ;
    }
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int W ,n ;

    while (scanf("%d%d" ,&W ,&n) != EOF){
        if (W > 1800)
            W += 200 ;

        vector<int> dp(W+1 ,0) ;
        vector<int> wt(n+1 ,0) ;
        vector<int> vt(n+1 ,0) ;

        fill(dp.begin()+1 ,dp.end() ,INT_MIN) ;

        for (int i = 0 ; i < n ; i++){
            cin >> wt[i] >> vt[i] ;
        }

        for (int i = 1 ; i <= n ; i++){
            for (int j = W ; j >= wt[i-1] ; j--){
                dp[j] = max(dp[j-wt[i-1]]+vt[i-1] ,dp[j]) ;
            }
        }

        int res = INT_MIN ;

        if (W <= 1800){
            for (int i = W ; i >= 0 ; i--){
                res = max(dp[i] ,res) ;
            }
        }
        else{
            for (int i = W ; i > 2000 ; i--){
                res = max(dp[i] ,res) ;
            }
            for (int i = W-200 ; i >= 0 ; i--){
                res = max(dp[i] ,res) ;
            }
        }
        cout << res << endl ;
    }
}

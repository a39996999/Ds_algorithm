#include <bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("o.txt" ,"w" ,stdout) ;

    int m ,n ,t ;
    while (cin >> m >> n >> t) {
        if (m == 1 || n == 1){
            cout << t << endl ;
            continue ;
        }

        vector<int> wt{m ,n} ;
        vector<int> vt{1 ,1} ;
        vector<pair<int ,int>> dp(t+1 ,{0 ,0}) ;

        function<void(int ,int)> knapsack = [&](int w ,int v){
            for (int j = t ; j >= w ; j--){
                if (dp[j].second < dp[j-w].second+w){
                    dp[j].first = dp[j-w].first+v ;
                    dp[j].second = dp[j-w].second+w ;
                }
                else if (dp[j].second == dp[j-w].second+w){
                    if (dp[j].first < dp[j-w].first+v)
                        dp[j].first = dp[j-w].first+v ;
                }
            }

            return ;
        };

        for (int i = 1 ; i <= 2 ; i++){
            int c = log2(t/wt[i-1]) ;
            for (int j = 0 ; j <= c ; j++){
               // cout << (wt[i-1]<<j) << endl ;
                knapsack(wt[i-1] << j ,vt[i-1] << j) ;
            }
        }

        if (dp[t].second != t){
            cout << dp[t].first << " " << t-dp[t].second ;
        }
        else
            cout << dp[t].first ;
        cout << endl ;
    }
}

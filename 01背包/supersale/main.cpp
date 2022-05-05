#include <bits/stdc++.h>

using namespace std;

int main()
{
    int iCase ;

    cin >> iCase ;
    while (iCase--){
        int n ;

        cin >> n ;
        vector<int> wt(n+1 ,0) ;
        vector<int> vt(n+1 ,0) ;

        for (int i = 0 ; i < n ; i++){
            cin >> vt[i] >> wt[i] ;
        }

        int p ,res = 0 ,W ;

        cin >> p ;
        for (int k = 0 ; k < p ; k++){
            cin >> W ;
            vector<int> dp(W+1 ,0) ;

            for (int i = 1 ; i <= n ; i++){
                for (int j = W ; j >= wt[i-1] ; j--){
                    dp[j] = max(dp[j-wt[i-1]]+vt[i-1] ,dp[j]) ;
                }
            }
            res += dp[W] ;
        }

        cout << res << endl ;
    }
}

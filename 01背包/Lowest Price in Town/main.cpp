#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n ;
    int m ,iCase = 1 ;
    string s ;

    while (cin >> n >> m ){
        cout << "Case " << iCase++ << ":\n" ;

        vector<double> vt(m+2 ,0.0) ;
        vector<int> wt(m+2 ,0) ;
        wt[1] = 2 ;
        vt[1] = n ;

        for (int i = 2 ; i < m+2 ; i++){
            cin >> wt[i] >> vt[i] ;
        }
        getline(cin ,s) ;
        getline(cin ,s) ;

        stringstream ss ;
        ss << s ;
        int W ;
        int maxW = *max_element(wt.begin() ,wt.end()) ;

        while (ss >> W){
            vector<double> dp(W+1 ,0) ;

            for (int i = 1 ; i <= m+1 ; i++){
                for (int j = maxW ; j >= wt[i-1] ; j--){
                    dp[j] = max(dp[j] ,dp[j-wt[i-1]]-vt[i-1]) ;
                }
            }

           // cout << maxDP << endl ;
            cout << "Buy " << W << " for $" << dp[W] << endl ;
        }
    }
}

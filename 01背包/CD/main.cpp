#include <bits/stdc++.h>

using namespace std ;

int knapsack(vector<vector<int>> &dp ,const vector<int> &nums ,int i ,int W){
    if (W < 0) return -1e9 ;
    if (i == 0) return 0 ;
    if (dp[i][W]) return dp[i][W] ;

    return dp[i][W] = max((knapsack(dp ,nums ,i-1 ,W-nums[i-1])+nums[i-1]) ,knapsack(dp ,nums ,i-1 ,W));
}

void path(const vector<vector<int>> &dp ,const vector<int> &nums ,int i ,int w){
    if (i == 0)
        return ;
    if (dp[i][w] == dp[i-1][w]){
        path(dp ,nums ,i-1 ,w) ;
    }
    else{
        path(dp ,nums ,i-1 ,w-nums[i-1]) ;
        cout << nums[i-1] << " " ;
    }
}

int main()
{
    int W ;
    while (cin >> W){
        int n ;
        cin >> n ;

        vector<int> nums(n ,0) ;
        vector<vector<int>> dp(n+1 ,vector<int>(W+1 ,0)) ;

        for (int i = 0 ; i < n ; i++){
            cin >> nums[i] ;
        }

        for (int i = 1 ; i <= n ; i++){
            for (int w = 1 ; w <= W ; w++){
                if (nums[i-1] > w)
                    dp[i][w] = dp[i-1][w] ;
                else
                    dp[i][w] = max(dp[i-1][w-nums[i-1]]+nums[i-1] ,dp[i-1][w]) ;
            }
        }

        path(dp ,nums ,n ,W) ;
        cout <<"sum:" << dp[n][W] << endl ;
    }
}

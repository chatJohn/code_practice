/*
* @Author: chatting
* @Date:   2023-06-15 16:52:07
* @Last Modified by:   10592
* @Last Modified time: 2023-06-16 01:09:06
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e3+1 ;
int dp[maxn][maxn] ;
void solve(){
    int res = 0 ;
    int n, m ; cin >> n >> m ;
    string S, T ; cin >> S >> T ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = max(0, dp[i - 1][j - 1]) + 2;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
                dp[i][j] = max(dp[i][j], -2) ;
            }
            res = max(res, dp[i][j]) ;
        }
    }
    cout << res << endl ;

}

signed main(){
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; cout.tie(0) ;
    int t = 1 ; // cin >> t ;
    while( t -- ) solve() ;
    return 0 ;
}
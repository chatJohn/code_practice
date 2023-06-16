/*
* @Author: chatting
* @Date:   2023-06-15 20:26:21
* @Last Modified by:   10592
* @Last Modified time: 2023-06-16 01:35:42
*/
#include<bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
const int MN = 1100;
const int MC = 10010;
int dp[MN][MC];
#define int long long
void solve(){
	int N, C;
	std::cin >> N >> C;
    dp[0][0] = 1;

	int t = 1;
    for(int n = 2; n <= N; n++, t = 1 - t){
    	for(int c = 0, sum = 0; c <= C; c++){
    		sum = (sum + dp[1-t][c]) % mode;
    		if(c >= n){
    			sum = (mode + sum - dp[1-t][c-n]) % mode;
    		}
    		dp[t][c] = sum % mode;
    	} 
    }
    cout << dp[1 - t][C] % mode;
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
/*
* @Author: chatting
* @Date:   2023-05-07 11:27:36
* @Last Modified by:   10592
* @Last Modified time: 2023-05-07 15:35:30
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	std::vector<int> v;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	std::vector<vector<int>> dp(n+1, std::vector<int>(3, -1e9));
	for(int i = 0; i < n; i++){
		dp[i+1][0] = max(dp[i][0], v[i] + i);
		dp[i+1][1] = max(dp[i][1], dp[i][0] + v[i]);
		dp[i+1][2] = max(dp[i][2], dp[i][1] + v[i] - i);
	}
	cout<<dp[n][2]<<endl;
}
int main(){
	int t;
	std::cin >> t;
	while(t --){
		solve();
	}
}
/*
* @Author: chatting
* @Date:   2023-06-15 08:32:43
* @Last Modified by:   10592
* @Last Modified time: 2023-06-15 08:37:23
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 10;
int v[maxn];
int w[maxn];

int dp[maxn];
int main(){
	int n, vv;
	std::cin >> n >> vv;
	for(int i = 1; i <= n; i++){
		std::cin >> v[i] >> w[i];
	}
	for(int i = 1; i <= n ; i++){
		for(int j = vv; j >= v[i]; j--){
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	cout << dp[vv] << endl;
}
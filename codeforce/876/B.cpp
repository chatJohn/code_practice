/*
* @Author: chatting
* @Date:   2023-06-05 19:04:38
* @Last Modified by:   10592
* @Last Modified time: 2023-06-05 19:38:30
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		std::vector<std::vector<int>> g(n+1);
		for(int i = 0; i < n; i++){
			int a, b;
			cin >> a >>b;
			g[a].push_back(b);
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			sort(g[i].begin(), g[i].end(), greater<int>());
			for(int j = 0; j < min(int(g[i].size()), i); j ++){
				ans += (ll)g[i][j];
			}
		}
		cout<<ans <<"\n";
	}
}
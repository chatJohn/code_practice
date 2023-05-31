/*
* @Author: chatting
* @Date:   2023-05-20 23:03:58
* @Last Modified by:   10592
* @Last Modified time: 2023-05-20 23:47:39
*/
#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin >> n;
	map<pair<int, int>, int> mp;
	std::vector<int> e[n+1];
	for(int i = 1;i <= n - 1;i ++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		mp[{u,v}] = i;
		mp[{v,u}] = i;
	}
	std::vector<int> ans;
	int sz[n+1];
	memset(sz, 0, sizeof sz);
	function<void(int, int)> dfs = [&](int x, int fa)->void{
		sz[x] = 1;
		for(int y: e[x]){
			if(y == fa)	continue;
			dfs(y, x);
			sz[x] += sz[y];
		}
		if(sz[x] == 3){
			if(x == 1){
				return;
			}
			sz[x] = 0;
			ans.push_back(mp[{x, fa}]);
		}
	};
	dfs(1, 0);
	if(ans.size() != n / 3 - 1 || n % 3){
		cout<<"-1"<<endl;
	}else{
		cout<<ans.size()<<endl;
		for(int i: ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
/*
* @Author: chatting
* @Date:   2023-06-02 17:19:53
* @Last Modified by:   10592
* @Last Modified time: 2023-06-02 19:37:51
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	std::vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		if(u > v)	swap(u, v);
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	std::vector<int> fa(n + 1);
	std::vector<int> e(n + 1);
	e[1] = n;//编号
	function<void(int, int)> dfs = [&](int x, int pa){
		for(auto [y, i]: adj[x]){
			if(y == pa)	continue;
			e[y] = i;
			fa[y] = fa[x] + (i < e[x]);
			dfs(y, x);
		}
	};
	dfs(1, -1);
	cout<< *max_element(fa.begin() + 1, fa.end())<<"\n";
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
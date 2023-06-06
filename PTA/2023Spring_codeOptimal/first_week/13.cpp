/*
* @Author: chatting
* @Date:   2023-06-06 15:24:08
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 16:01:23
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	int root;
	cin >> n >> m;
	vector<vector<int>> g(n+1);
	std::vector<int> fa(n+1);
	for(int i = 1; i <= n; i++){
		cin >> fa[i];
		if(fa[i] == -1)	root = i;
		else	g[fa[i]].push_back(i);
	}
	std::vector<int> depth(n+1);
	function<void(int)> dfs = [&](int root)->void{
		if(root == -1){
			return;
		}
		for(int y: g[root]){
			depth[y] = depth[root] + 1;
			dfs(y);
		}
	};
	dfs(root);
	std::vector<int> vis(n+1);
	int v = 0;
	int ma = 0;
	while(m--){
		int x;
		cin >> x;
		ma = max(ma, depth[x]);
		while(!vis[x] and x != root){
      vis[x] = 1;
      v += 2;
			x = fa[x];
		
		}
		cout << v - ma << endl;
	}
}
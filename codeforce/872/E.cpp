/*
* @Author: chatting
* @Date:   2023-05-10 22:06:14
* @Last Modified by:   10592
* @Last Modified time: 2023-05-10 22:41:27
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int ans;
std::vector<int> e[maxn];
int v[maxn];
map<int, int> f[maxn];//统计父节点的子节点次数最多的节点
void dfs(int x, int fa){
	int mx = 1;//节点出现次数至少1
	int c = 0;//子节点个数
	for(int y: e[x]){
		if(y != fa){
			v[y] ^= v[x];
			dfs(y, x);
			c++;
			if(f[x].size() < f[y].size())	swap(f[x], f[y]);
			for(auto &oo: f[y]){
				mx = max(mx, f[x][oo.first] += oo.second);
				
			}
		}
	}
	if(c == 0){
		f[x][v[x]] = 1;
	}
	else ans += c - mx;
	if(mx != 1){
		for(auto it = begin(f[x]); it !=end(f[x]);){
			if(it->second != mx){
				it = f[x].erase(it);
			}else{
				it->second = 1;
				it = next(it);
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	for(int i = 1; i <= n-1;i++){
		int u, x;
		cin >> u >> x;
		e[u].push_back(x);
		e[x].push_back(u);
	}
	dfs(1, 0);
	cout<<ans + (!f[1].count(0))<<endl;
	return 0;
}
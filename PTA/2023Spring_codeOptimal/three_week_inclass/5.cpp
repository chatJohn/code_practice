/*
* @Author: chatting
* @Date:   2023-06-14 09:40:58
* @Last Modified by:   10592
* @Last Modified time: 2023-06-14 22:10:34
*/
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long ll;
const int maxn = 1000;
int dis[maxn][maxn];
int path[maxn][maxn];
int n, m, L;
int q;
void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1;j <= n; j++){
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}
int vaild[maxn][maxn];
void in_path(){
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n ;j++){
			if(dis[i][j] <= L){
				vaild[i][j] = vaild[j][i] = 1;
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1;j <= n; j++){
				if(vaild[i][j] > vaild[i][k] + vaild[k][j]){
					vaild[i][j] = vaild[i][k] + vaild[k][j];
				}
			}
		}
	}
}
void solve(){
	std::cin >> n >> m >> L;
	memset(dis, inf, sizeof dis);
  	memset(vaild, inf, sizeof vaild);
	for(int i = 0; i < m ; i++){
		int u, v, w;
		std::cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	floyd();
	std::cin >> q;
	in_path();
	while(q--){
		int s, t;
		std::cin >> s >> t;
		if(vaild[s][t] < inf){
			cout << vaild[s][t] - 1 << endl;
		}else{
		  cout << "-1\n";	
		}
		
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
}
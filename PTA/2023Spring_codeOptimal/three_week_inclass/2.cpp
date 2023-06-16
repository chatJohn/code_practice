/*
* @Author: chatting
* @Date:   2023-06-14 08:42:42
* @Last Modified by:   10592
* @Last Modified time: 2023-06-14 09:02:09
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 200;
// struct edge{
// 	int v;
// 	int w;
// 	int next;
// }e[maxn];
// int ind = 1;
// int head[maxn];
// void add(int a, int b, int c){
// 	e[++ind] = {b, c, head[a]};
// 	head[a] = ind;
// }
int dis[maxn][maxn];
#define inf 0x3f3f3f3f
int n, ed;
void floyd(){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n ; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}
int main(){
	while(~scanf("%d %d",&n, &ed)){
		memset(dis, inf, sizeof dis);
		for(int i = 0; i < ed; i++){
			int u, v, w;
			std::cin >> u >> v >> w;
			dis[u][v] = w;
			dis[v][u] = w;
		}
		for(int i = 0; i< n; i++){
			dis[i][i] = 0;
		}
		floyd();
		vector<int> sum(n);
		for(int i = 0; i < n; i++){
			sum[i] = accumulate(dis[i], dis[i] + n, 0);
		}
		int ans = -1;
		int mn = *min_element(sum.begin(), sum.end());
		for(int i = 0 ; i< n; i++){
			if(sum[i] == mn){
				ans = i;
				break;
			}
		}
		cout << ans <<"\n";
	}
}
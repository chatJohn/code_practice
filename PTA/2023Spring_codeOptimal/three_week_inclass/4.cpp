/*
* @Author: chatting
* @Date:   2023-06-14 09:12:40
* @Last Modified by:   10592
* @Last Modified time: 2023-06-14 09:40:53
*/
#include<bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;
const int N=4000;
struct edge{
    int v;
    int weight;
};
vector<edge> e[N];
int dis[N];
int visited[N];
int ans;
int cnt;
int n,m,s;
void init(){
	memset(visited, 0, sizeof visited);
	ans = 0;
	cnt = 0;
}
priority_queue<pair<int,int>> qu;
bool PrimHeap(int s){
    for(int i=1;i<=n;i++){
        dis[i]=inf;
    }
    dis[s]=0;
    qu.push({0,s});
    while(qu.size()){
        auto t=qu.top();
        qu.pop();
        int u=t.second;
        if(visited[u])  continue;
        visited[u]=1;
        ans+=dis[u];
        cnt++;
        for(auto ed: e[u]){
            int v=ed.v;
            int weight=ed.weight;
            if(dis[v]>weight){
                dis[v]=weight;
                qu.push({-dis[v],v});
            }
        }
    }
    return cnt==n;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }
    int flag = -1;
	int res = inf;
	for(int i = 1; i <= n; i++){
         init();
		if(PrimHeap(i)){
			res = min(res, ans);
			flag = 1;
		}
	}
	if(flag == -1){
		cout << "-1\n";
	}else{
		cout << res;
	}
    return 0;
}
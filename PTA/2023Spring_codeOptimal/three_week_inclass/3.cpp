/*
* @Author: chatting
* @Date:   2023-06-14 09:02:22
* @Last Modified by:   10592
* @Last Modified time: 2023-06-14 09:12:37
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 400;
int n, e;
int din[maxn];
vector<int> edge[maxn], tp;
bool topoSort(){
    priority_queue<int, vector<int>, greater<int>> qu;
    for(int i=0;i<n;i++){
        if(din[i]==0)   qu.push(i);
    }
    while(qu.size()){
        int x=qu.top();
        qu.pop();
        tp.push_back(x);
        for(auto y: edge[x]){
            if(--din[y]==0) qu.push(y);
        }
    }
    return tp.size()==n;
}
int main(){
	std::cin >> n >> e;
	for(int i = 0; i < e; i++){
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back(v);
		din[v]++;
	}
	topoSort();
	// cout << tp.size()<<endl;
	for(int i = 0; i < tp.size(); i++){
		cout << tp[i] << " ";
	}

}
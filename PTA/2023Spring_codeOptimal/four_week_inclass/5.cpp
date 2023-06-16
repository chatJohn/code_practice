/*
* @Author: chatting
* @Date:   2023-06-15 17:08:49
* @Last Modified by:   10592
* @Last Modified time: 2023-06-15 17:41:00
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	std::cin >> n;
	vector<pair<int, int>> a;
	for(int i = 0; i < n; i++){
		int l, p;
		std::cin >> l >> p;
		a.push_back({l, p});
	}
	int L, P;
	std::cin >> L >> P;
	for(int i = 0; i < n; i++){
		a[i].first = L - a[i].first;
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	int idx = 0;
	priority_queue<int> q;
	while(P < L){
		if(idx < n && P >= a[idx].first){
			q.push(a[idx].second);
			idx++;
		}else{
			if(!q.empty()){
				cnt++;
				P += q.top();
				q.pop();
			}else{
				puts("-1");
				return;
			}
		}
	}
	cout << cnt;
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
}
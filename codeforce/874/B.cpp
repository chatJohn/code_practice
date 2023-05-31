/*
* @Author: chatting
* @Date:   2023-05-20 17:20:49
* @Last Modified by:   10592
* @Last Modified time: 2023-05-20 20:45:55
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	std::vector<pair<int, int>> a(n);
	std::vector<int> b;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	std::vector<int> ans(n);
	for(int i = 0; i < n; i++){
		ans[a[i].second] = b[i];
	}
	for(int x: ans){
		cout<<x<<" ";
	}
	cout<<endl;
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
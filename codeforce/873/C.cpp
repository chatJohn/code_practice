/*
* @Author: chatting
* @Date:   2023-05-16 15:51:44
* @Last Modified by:   10592
* @Last Modified time: 2023-05-16 16:07:02
*/
#include<bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	std::vector<int> a;
	for(int i =0 ;i < n;i ++){
		int v;
		cin >> v;
		a.push_back(v);
	}
	std::vector<int> b;
	for(int i =0 ;i < n;i ++){
		int v;
		cin >> v;
		b.push_back(v);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	long long ans = 1;
	int used = 0;
	for(int x: b){
		int right = a.end() - upper_bound(a.begin(), a.end(), x);
		ans = (ans % mode* (right - used)%mode) % mode;
		used++;
	}
	cout<<ans<<endl;
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
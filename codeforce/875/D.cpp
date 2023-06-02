/*
* @Author: chatting
* @Date:   2023-06-02 19:37:56
* @Last Modified by:   10592
* @Last Modified time: 2023-06-02 20:15:34
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	std::vector<pair<int, int>> ab(n);
	for(int i = 0; i <n; i++){
		cin >> ab[i].first;
	}
	for(int i = 0 ;i  < n ; i++){
		cin >> ab[i].second;
	}
	vector<int> cnt(n+1, 0);
	sort(ab.begin(), ab.end());
	long long ans = 0;
	for(int s = 1; s * s <= 2 * n; s++){
		cnt.assign(n+1, 0);
		for(auto [a, b]: ab){
			int v = a * s - b;
			if(1 <= v and v <= n){
				ans += cnt[v];
			}
			if(a == s){
				cnt[b]++;
			}
		}
	}
	cout<<ans<<"\n";

}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
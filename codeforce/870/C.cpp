/*
* @Author: 
* @Date:   2023-05-07 11:01:21
* @Last Modified by:   10592
* @Last Modified time: 2023-05-07 15:35:30
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+ 10;
int spf[maxn];
void pre(){
	iota(spf,spf+maxn,0);
	for(int i = 2;i < maxn; i++){
		if(spf[i] == i){
			for(int j = 2*i; j < maxn; j += i){
				spf[j] = min(spf[j], i);
			}
		}
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	cout << (n == 1 or spf[n] > m ? "YES\n" :"NO\n");
}
int main(){
	int t;
	pre();
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
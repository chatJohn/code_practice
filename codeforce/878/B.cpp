/*
* @Author: chatting
* @Date:   2023-06-20 20:09:34
* @Last Modified by:   10592
* @Last Modified time: 2023-06-20 21:09:40
*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
void solve(){
	int n, k;
	std::cin >> n >> k;
	// for(int i = 0; i < k; i++){
	// 	v[i] = 1 << i;
		
	// }	
	if(k > 30){
		cout << n + 1 << "\n";
	}else{
		cout << min(n + 1, 1 << k) << "\n";
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	std::cin >> t;
	while(t--){
		solve();
	}
}
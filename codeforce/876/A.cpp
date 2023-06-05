/*
* @Author: chatting
* @Date:   2023-06-05 17:56:09
* @Last Modified by:   10592
* @Last Modified time: 2023-06-05 19:04:33
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for(int i = n; i >= 1; i --){
			if((i - 1) % k == 0){
				ans ++;
			}
			if(((n - i) / k) + 1 > ans){
				ans ++;
			}
		}
		cout << ans << "\n";
	}
}
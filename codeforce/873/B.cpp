/*
* @Author: chatting
* @Date:   2023-05-16 15:38:57
* @Last Modified by:   10592
* @Last Modified time: 2023-05-16 15:51:15
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n ;
	cin >> n;
	std::vector<int> v;
	int gcd = 0;
	for(int i = 0;i< n;i ++){
		int a;
		cin >> a;
		a = abs(a - i - 1);
		gcd = __gcd(a, gcd);
	}
	cout<<gcd<<endl;
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
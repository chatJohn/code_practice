/*
* @Author: chatting
* @Date:   2023-06-07 19:41:54
* @Last Modified by:   10592
* @Last Modified time: 2023-06-07 20:06:02
*/
#include<bits/stdc++.h>
using namespace std;
typedef long  long ll;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		std::vector<ll> a(n);
		for(auto &x: a){
			cin >> x;
		}
		ll mn = *min_element(a.begin(), a.end());
		ll mm = *max_element(a.begin(), a.end());
		if(mn < 0){
			cout << mn << endl;
		}else{
			cout << mm << endl;
		}
		
	}

}
/*
* @Author: chatting
* @Date:   2023-06-06 10:35:04
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 10:44:43
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m, q;
	cin >> n >> m >> q;
	long long ans = 1ll * n * m;
	set<int> r;
	set<int> c;
	while(q--){
		int tp, idx;
		cin >> tp >> idx;
		if(tp == 0){
			r.insert(idx);
		}else if(tp == 1){
			c.insert(idx);
		}
	}
	ans -= int(r.size()) * m;
	ans -= int(c.size()) * n;
	ans += int(r.size()) * int(c.size());
	cout<<ans<<"\n";
}
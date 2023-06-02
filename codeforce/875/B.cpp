/*
* @Author: chatting
* @Date:   2023-06-02 16:37:23
* @Last Modified by:   10592
* @Last Modified time: 2023-06-02 17:19:31
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		std::vector<int> a(n+1);
		std::vector<int> b(n+1);
		for(int i = 1;i <= n ;i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n ;i++){
			cin >> b[i];
		}
		int res = 0;
		int lst = 0;
		vector<int> ts(2 * n+1);
		for(int i = 1;i <= n;i++){
			if(i != n and a[i] == a[i+1])	continue;
			ts[a[i]] = max(ts[a[i]], i - lst);
			lst = i;
			res = max(res, ts[a[i]]);
		}
		lst = 0;
		for(int i = 1;i <= n ;i++){
			if(i!= n and b[i] == b[i+1])	continue;
			res = max(res, ts[b[i]] + i - lst);
			lst = i;
		}
		cout << res << "\n";
	}
}
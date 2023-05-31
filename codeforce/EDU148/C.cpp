/*
* @Author: chatting
* @Date:   2023-05-13 20:37:39
* @Last Modified by:   10592
* @Last Modified time: 2023-05-13 21:41:21
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		std::vector<int> v;
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			v.push_back(a);
		}
		v.resize(unique(v.begin(), v.end()) - v.begin());
		int ans = 0;
		n = v.size();

		for(int i = 0; i < n; i++){
			if(i == 0 || i == n -1 || ((v[i] > v[i-1]) == (v[i] > v[i+1]))){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
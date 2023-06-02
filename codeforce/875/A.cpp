/*
* @Author: chatting
* @Date:   2023-06-02 16:27:38
* @Last Modified by:   10592
* @Last Modified time: 2023-06-02 16:37:18
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		std::vector<int> a;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		int sum = *max_element(a.begin(), a.end()) + 1;
		vector<int> ans(n);
		for(int i = 0; i < n; i ++){
			ans[i] = sum - a[i];
		}
		for(int x: ans){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}
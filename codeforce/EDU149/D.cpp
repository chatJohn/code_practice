/*
* @Author: chatting
* @Date:   2023-06-01 16:53:26
* @Last Modified by:   10592
* @Last Modified time: 2023-06-01 17:31:25
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t --){
		int n;
		string s;
		cin >> n >> s;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++){
			if(s[i] == '('){
				a[i] = 1;
			}else{
				a[i] = -1;
			}
		}
		std::vector<int> ans(n);
		for(int i = 1; i < n; i++){
			a[i] += a[i-1];
		}
		if(a.back()){
			cout << "-1\n";
			
		}else{
			for(int i = 0; i < n; i++){
				if(a[i] > 0)	ans[i] = 1;
				else if(a[i] < 0)	ans[i] = 2;
				else if(a[i] == 0)ans[i] = ans[i-1];
			}
			set<int> st;
			for(int i: ans){
				st.insert(i);
			}
			cout<<st.size()<<endl;
			if(st.size() == 1){
				for(int i = 0; i < n ;i++){
					cout<<1<<" ";
				}
				cout<<endl;
			}else{
				for(int x: ans){
					cout<<x<<" ";
				}
				cout<<endl;
			}
		}
	}
}
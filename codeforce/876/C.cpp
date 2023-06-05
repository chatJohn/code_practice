/*
* @Author: chatting
* @Date:   2023-06-05 19:38:35
* @Last Modified by:   10592
* @Last Modified time: 2023-06-05 21:04:15
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		std::vector<int> a(n);
		for(int &x: a){
			cin >> x;
		}
		if(a.back() == 1){
			cout << "NO\n";
		}else{
			reverse(a.begin(), a.end());
			cout<<"YES\n";
			for(int i = 0; i < n;){
				int zero = i;
				while(i < n and a[i] == 0){
					i++;
				}
				int one = i;
				while(i < n and a[i] == 1){
					i++;
				}
				for(int j = 0; j < i - zero - 1; j++){
					cout<<"0 ";
				}
				cout<<i - one<<" ";
			}
			cout<<"\n";
		}
	}
}
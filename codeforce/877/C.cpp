/*
* @Author: chatting
* @Date:   2023-06-07 20:32:14
* @Last Modified by:   10592
* @Last Modified time: 2023-06-07 20:54:52
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i < n ; i += 2){
			for(int j = 1; j <= m; j++){
				cout << i * m + j << " ";
			}
			cout << endl;
		}
		for(int i = 0 ; i < n; i += 2){
			for(int j = 1; j <= m; j++){
				cout << i * m + j << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
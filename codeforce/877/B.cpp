/*
* @Author: chatting
* @Date:   2023-06-07 20:06:10
* @Last Modified by:   10592
* @Last Modified time: 2023-06-07 20:32:11
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
		std::vector<int> p(n);
		for(int &x: p){
			cin >> x;
		}
		int idx1 = -1;
		int idx2 = -1;
		int idxn = -1;
		for(int i = 0; i < n; i++){
			if(p[i] == 1)	idx1 = i + 1;
			if(p[i] == 2)	idx2 = i + 1;
			if(p[i] == n)	idxn = i + 1;
		}
		int b[3] = {idx1, idx2, idxn};
		sort(b, b + 3);
		cout << b[1] << " " << idxn<<endl;
	}
}
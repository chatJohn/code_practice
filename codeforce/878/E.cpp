/*
* @Author: chatting
* @Date:   2023-06-22 20:14:49
* @Last Modified by:   10592
* @Last Modified time: 2023-06-22 21:06:52
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> Q[2<<17];
void solve(){
	string s1, s2;
	std::cin >> s1 >> s2;
	int t, q;
	std::cin >> t >> q;
	for(int i = 1; i <= q;  i++){
		Q[i].clear();
	}
	int cnt = 0;
	for(int i = 0; i< s1.size(); i++){
		if(s1[i] != s2[i])	cnt++;
	}

	for(int i = 1; i <= q; i++){
		for(int pos: Q[i]){
			if(s1[pos] != s2[pos])	cnt++;//第i秒时, 前面阻塞解开
		}
		int op;
		std::cin >> op;
		if(op == 1){
			int pos;
			std::cin >> pos;
			pos--;
			if(s1[pos] != s2[pos])	cnt--;
			if(i + t <= q)	Q[i + t].push_back(pos);
		}else if(op == 2){
			int idx1, idx2, pos1, pos2;
			std::cin >> idx1 >> pos1 >> idx2 >> pos2;
			idx1--, idx2--, pos1--, pos2--;
			
			if(idx1 > idx2){
				swap(idx1, idx2); 
				swap(pos1, pos2);
			}
			if(s1[pos1] != s2[pos1])	cnt--;
			if(pos1 != pos2){
				if(s1[pos2] != s2[pos2])	cnt--;
			}
			if(idx1 == idx2){
				if(idx1 == 0){
					swap(s1[pos1], s1[pos2]);
				}else{
					swap(s2[pos1], s2[pos2]);
				}
			}
			else swap(s1[pos1], s2[pos2]);
			
			if(s1[pos1] != s2[pos1])	cnt++;
			if(pos1 != pos2){
				if(s1[pos2] != s2[pos2])	cnt++;
			}
		}else{ 
			std::cout << (cnt > 0 ? "NO\n" : "YES\n");
		}

	}
}
int main(){
	int t = 1;
	std::cin >> t;
	while(t--){
		solve();
	}
}
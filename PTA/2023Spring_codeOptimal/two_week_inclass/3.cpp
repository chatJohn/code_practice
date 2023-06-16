/*
* @Author: chatting
* @Date:   2023-06-13 08:51:42
* @Last Modified by:   10592
* @Last Modified time: 2023-06-13 09:11:36
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,c;
	std::cin >> r >> c;
	vector<vector<char>> matrix(r, vector<char>(c));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			std::cin >> matrix[i][j];
		}
	}
	function<bool(int)> check = [&](int mid)->bool{
		vector<vector<char>> temp(r - mid, vector<char>(c));
		map<vector<char>, int> mp;
		vector<vector<char>> tt(c, vector<char>(r - mid));
		for(int i= 0; i < r - mid; i++){
			temp[i] = matrix[i+ mid];
		}
		for(int j = 0; j < c; j++){
			for(int i= 0; i < r - mid; i++){
				tt[j][i] = temp[i][j];
			}
		}
		for(int i = 0 ; i < c; i++){
			if(mp[tt[i]])	return false;
			else mp[tt[i]]++;
		}
		return true;
	};
	int left = -1;
	int right = r + 1;
	while(left + 1 < right){
		int mid = (left + right) / 2;
		if(check(mid))	left = mid;
		else right = mid;
	}
	cout << left << endl;
}
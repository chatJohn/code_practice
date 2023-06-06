/*
* @Author: chatting
* @Date:   2023-06-06 14:45:44
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 14:58:45
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	function<bool(int)> is_prime = [&](int a)->bool{
		if(a < 2)	return false;
		for(int i = 2; i * i <= a; i ++){
			if(a % i == 0)	return false;
		}
		return true;
	};
	int m, n;
	cin >> m >> n;
	map<int, int> mp;
	std::vector<int> a;
	for(int i = m; i <= n; i++){
		if(is_prime(i)){
			a.push_back(i);
			mp[i] = 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < a.size(); i++){
		for(int j = i + 1; j < a.size(); j++){
			for(int k = j + 1; k < a.size(); k++){
				if(is_prime(a[i] * a[j] + a[k]) and is_prime(a[j] * a[k] + a[i]) and is_prime(a[i] * a[k] + a[j])){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
/*
* @Author: chatting
* @Date:   2023-05-13 21:06:14
* @Last Modified by:   10592
* @Last Modified time: 2023-05-13 22:03:34
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	// cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		std::vector<int> v;
		int ans = 0;
		for(int i = 0; i < n;i ++){
			int a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		auto backup = v;
		for(int i = 0 ;i < q;i++){
			v = backup;
			int k;
			cin >> k;
			for (int j = 0; j < n; ++j)
			{
				if(k == 0)	break;
				if(k % 2 == 0 and j == n -1 ) break;
				v[j] += k;
				k--;
			}
			k /= 2;
			sort(v.begin(), v.end());
			long long diff = 0;
			for(int i = 0 ;i < n; i++){
				diff += v[i] - v[0];
			}
			int ans = v[0];
			if(k > diff){
				k -= diff;
				ans -= (k + n - 1) / n;
			}
			cout<<ans<<" ";
		}
	}
	return 0;
}
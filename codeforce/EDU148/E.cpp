/*
* @Author: chatting
* @Date:   2023-05-13 22:03:39
* @Last Modified by:   10592
* @Last Modified time: 2023-05-13 22:46:33
*/
#include<bits/stdc++.h>
using namespace std;
const int mode = 998244353;
int main(){
	int t = 1;
	// cin >> t;
	while(t--){
		long long n, a1, x, y, m, k;
		cin >> n >> a1 >> x >> y >> m >> k;
		std::vector<long long> a(n);
		a[0] = a1;
		for(int i=1; i<n;i++){
			a[i] = ((long long)a[i-1] * x  % m+ y * 1ll) % m;
		}
		for (int i = 0; i <= k; ++i)
		{
			vector<long long> b(n);
			b[0] = a[0];
			for(int j = 1; j < n ;j++){
				b[j] = (b[j-1] + a[j]);
			}
			swap(a,b);
		}
		for(int i = 0; i < k-1;i++){
			a.insert(a.begin(), 0);
		}//前k-1项全部为0
		long long ans = 0;
		for(int i =0 ; i < n; i++){
			ans ^= ((long long)a[i] *1LL*(i+1));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
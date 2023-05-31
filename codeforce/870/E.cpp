/*
* @Author: 
* @Date:   2023-05-07 12:04:04
* @Last Modified by:   10592
* @Last Modified time: 2023-05-10 16:26:04
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5010;
using bs = bitset<maxn>;//bit位数组
void solve(){
	int m, n;
	std::cin >> m >> n;
	//LIS --> bruce --> O(n^2 * m) --> bitset --> get the sources when move to i from 1-j(j < i && bitset(j))
	std::vector<std::vector<int>> a(n, vector<int>(m+1));
	for(int i = 0; i < n; i++){
		std::cin >> a[i][m];
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			std::cin >> a[j][i];
		}
	}
	sort(a.begin(), a.end());
	vector<bs> lower(n);
	for(int i = 0; i < n;i ++){
		lower[i].set();
	}
	vector<int> inds(n);
	iota(inds.begin(), inds.end(), 0);
	for(int i = 0;i < m; i++){
		sort(inds.begin(), inds.end(),[&](int x, int y){
			return a[x][i] < a[y][i];
		});
		bs cur = 0;
		int  p = 0;
		for(int j =0 ; j < n ;j++){
			while(a[inds[p]][i] < a[inds[j]][i]) cur.set(inds[p++], 1);
			lower[inds[j]] &= cur;
		}
	}
	vector<long long> dp(n);
	for(int i = 0; i  <n ;i ++){
		dp[i] = a[i][m];
		for(int j = 0; j < i; j++){
			if(lower[i][j]) dp[i] = max(dp[i], dp[j] + a[i][m]);
		}
	}
	cout<<*max_element(dp.begin(), dp.end())<<"\n";
}


/*
3 5
10 10 10 10 10
|1|2|3|4|5|
|1|5|2|3|4|
|2|3|4|5|1|
vector<> LIS
*/
int main(){
	solve();
}
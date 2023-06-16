/*
* @Author: chatting
* @Date:   2023-06-15 16:52:07
* @Last Modified by:   10592
* @Last Modified time: 2023-06-15 17:08:46
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
int n, m;
int a[maxn], b[maxn];
void solve(){
	std::cin >> n >> m;
	int sum = 0;
	int cnt = 0;
	int res = 0;
	vector<int> diff(n);

	for(int i = 0; i < n; i++){
		std::cin >> a[i] >> b[i];
		sum += b[i];
		res += a[i];
		diff[i] = a[i] - b[i];
	}

	if(sum > m){
		cout << "-1\n";
	}else{
		sort(diff.begin(), diff.end(), greater<int>());
		int cnt = 0;
		for(int i = 0; i <n ;i++){
			if(res > m){
				res -= diff[i];
				cnt++;
			}
			else break;
		}
		cout << cnt << endl;
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
}
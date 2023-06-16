#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn], b[maxn];
int a_temp[maxn], b_temp[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    std::cin >> n;
    // priority_queue<int, vector<int>, greater<int>> pq_a; // 小根堆
    // priority_queue<int> pq_b; // 大根堆
    for(int i = 1; i<= n; i++){
    	int x, y;
    	std::cin >>x >> y;
    	a[x]++;
    	b[y]++;
    	for(int j=1;j<=100;++j){
    		a_temp[j] = a[j];
    		b_temp[j] = b[j];
    	}
    	int left = 1;
    	int ans = 0;
    	int right = 100;
    	while(1){
    		while(!a_temp[left])	left++;
    		while(!b_temp[right])	right--;
    		if(left > 100 or right < 1)	break;
    		ans = max(ans, left + right);
    		int d=min(a_temp[left], b_temp[right]);
			a_temp[left] -= d;
			b_temp[right] -= d;
    	}
    	cout << ans << endl;
    }
    return 0;
}

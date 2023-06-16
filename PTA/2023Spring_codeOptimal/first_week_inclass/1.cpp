/*
* @Author: chatting
* @Date:   2023-06-12 08:47:44
* @Last Modified by:   10592
* @Last Modified time: 2023-06-12 13:15:44
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int mm = INT_MIN;
	int mn = INT_MAX;
	int mid = 0;
	int idx = 0;
	priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i = 0; i < n; i++){
		int x;
		idx++;
		scanf("%d", &x);
		if(maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        }else {
            minHeap.push(x);
        }
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
		mm = max(mm, x);
		mn = min(mn, x);
		if(idx % 2 == 0){
			mid = minHeap.top() + maxHeap.top();
      		cout << (mm + mn + mid) / 4 << (" "[i == n - 1]);
		}else{
			if (maxHeap.size() > minHeap.size()) {
		        mid = maxHeap.top();
		    } else {
		        mid = minHeap.top();
		    }
			cout << (mm + mn + mid) / 3 <<(" "[i == n - 1]);
		}
	}
}
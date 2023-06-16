/*
* @Author: chatting
* @Date:   2023-06-13 08:34:48
* @Last Modified by:   10592
* @Last Modified time: 2023-06-13 08:41:44
*/
#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> & arr, int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
        cout << "step " << i + 1 << ": ";
        for(int j = 0; j < n; j++){
        	cout << arr[j] << (" ");
        }
        cout << endl;
    }
    cout << "sorted array: ";
    for(int x: arr){
    	cout << x << " ";
    }
}
int main(){
	int n;
	std::cin >> n;
	std::vector<int> a;
	for(int i = 0; i < n; i++){
		int x;
		std::cin >> x;
		a.push_back(x);
	}
	selectionSort(a, n);
}
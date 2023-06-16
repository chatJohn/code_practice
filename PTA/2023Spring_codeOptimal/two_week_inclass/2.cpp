/*
* @Author: chatting
* @Date:   2023-06-13 08:41:47
* @Last Modified by:   10592
* @Last Modified time: 2023-06-13 08:51:39
*/
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&final, vector<int> & arr, int n = 5) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]){
                	swap(arr[j], arr[j+1]);
                	for(int k = 0; k < n; k++){
        	if(k != n -1)	cout << arr[k] <<" ";
        	else cout << arr[k];
        }
        if(final == arr)	break;
        cout << endl;
    
            	}
            }
            if(final == arr)	break;
        }
}
int main(){
	std::vector<int> a(5);
	for(int &x: a){
		std::cin >> x;
	}
	vector<int> temp = a;
	sort(temp.begin(), temp.end());
	bubbleSort(temp, a);
}
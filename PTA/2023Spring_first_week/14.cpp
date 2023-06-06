/*
* @Author: chatting
* @Date:   2023-06-06 14:59:34
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 15:23:51
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k, x;
	cin >> n >> k >> x;
	vector<int>ans;
	std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}
	int  p = 1;
	for(int i = n-1; i >= 0; i--) 
	{
		p=1;
		for(int j = 0; j < n; j++)
		{
			if((j + 1) % 2 == 0)   
			{
				if(i - p >= 0)          
					matrix[i][j] = matrix[i-p][j];    
				else                   
					matrix[i][j] = x;
				p++;          
				if(p > k) p = 1; 
			}	
		}
	}	
	for(int j = 0; j < n; j++){
	int temp = accumulate(matrix[j].begin(), matrix[j].end(), 0);
		cout<< temp <<" "[j == n - 1];
	}
  cout<<endl;
}
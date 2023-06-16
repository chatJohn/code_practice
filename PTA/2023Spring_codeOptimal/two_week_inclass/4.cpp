/*
* @Author: chatting
* @Date:   2023-06-13 09:11:43
* @Last Modified by:   10592
* @Last Modified time: 2023-06-13 09:15:46
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
int main(){	
	int n;
	cin>>n;
	char c;
	int x;
	vector<int> Time;
	vector<int> Distance;
	while(n--){
		cin>>c;
    cin>>x;
		if(c == 'T') 
			Time.push_back(x);
		else 
			Distance.push_back(x);
	}
	Distance.push_back(1000);
	sort(Time.begin(), Time.end());
	sort(Distance.begin(), Distance.end());
	double t = 0, s = 0, v = 1;
	int i , j ;
	for(i=0,j=0;i<Time.size()&&j<Distance.size();){
		if(Time[i] - t < (Distance[j] - s) * v){	
			s += (Time[i] - t) /v;
			t = Time[i];
			v++;
			i++;
		}
		else{	
			t += (Distance[j] - s) * v;
			s = Distance[j];
			v++;
			j++;
		}	
	}
	while(i < Time.size()){
		s += (Time[i] - t) / v;
		t = Time[i];
		v++;
		i++;
	}
	while(j < Distance.size()){
		t += (Distance[j] - s) * v;
		s = Distance[j];
		v++;
		j++;
	}
	cout<<fixed<<setprecision(0)<<t;
	return 0;
}

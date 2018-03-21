#include<bits/stdc++.h>
using namespace std;
struct data{
	int x, y;
};
int main(){
	int t, n, m;
	cin >> t;
	for ( int times = 0 ; times < t ; times++ ){
		data dataBasic[m];
		bool data1[n];
		bool data2[n];
		vector<vector <int> > v;
		for ( int i = 0 ; i < m ; i ++ ){
			cin >> dataBasic[i].x >> dataBasic[i].y;
			data1[dataBasic[i].x] = true;
			data1[dataBasic[i].y] = true;
		}
		int data3;
		for ( int i = 0 ; i < n ; i++ )
			if ( !data1[i] ){
				data3 = i;
				break;
			}
		for ( int i = 0 ; i < n ; i++ ){
			
		}
	}
}
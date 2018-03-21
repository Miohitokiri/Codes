#include<iostream>
using namespace std;
struct ans{
	long long count;
	bool tf;
};
int main(){
	long long m, p, n;
	ans ans;
	ans.count = 0;
	cin >> m >> p >> n;
	long long dataBasic[n], data[n + 1];
	cin >> dataBasic[0];
	data[0] = dataBasic[0];
	for ( int i = 1 ; i < n ; i++ ){
		cin >> dataBasic[i];
		data[i] = dataBasic[i] - dataBasic[i - 1];
		ans.count++;
		( m > data[i] ) ? ans.tf = true : ans.tf = false;
	}
	data[n - 1] = p - dataBasic[n - 2];
	( m > data[n - 1] ) ? ans.tf = true : ans.tf = false;
	( ans.tf == true ) ? cout << ans.count : cout << "IMPOSSIBLE";
	cout << endl;
}
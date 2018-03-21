#include<iostream>
using namespace std;
int main(){
	long long ans;
	cin >> ans;
	for ( int i = 0 ; i < 2 ; i++ ){
		long long stop;
		cin >> stop;
		ans = ( stop < ans ) ? stop : ans;
	}
	cout << ans << endl;
}
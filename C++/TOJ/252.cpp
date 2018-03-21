#include<iostream>
using namespace std;
int main(){
	int n, m, p;
	cin >> n >> m >> p;
	long long ans = n;
	for ( int i = 2 ; i < n ; i++ ){
		ans *= i;
		ans %= p;
	}
	ans += ( m * 9999999999999 ) % p;
	ans %= p;
	cout << ans << endl;
}
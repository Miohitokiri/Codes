#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int t, a;
	cin >> t;
	long long data[13] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600 };
	for ( int times = 0 ; times < t ; times++ ){
		cin >> a;
		cout << "Case #" << times + 1 << ":\n";
		for ( int i = 0 ; i <= a ; i++ ){
			cout << "TFCIS" << i << '=' << data[i] << endl;
		}
	}
}
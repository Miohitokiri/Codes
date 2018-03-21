#include<iostream>
using namespace std;
long long GCD ( long long a, long long b ){
	while ( a % b == 0 && a % b == 0 )
		if ( a > b )
			a %= b;
		else
			b %= a;

	if ( a > b )
		return b;
	else
		return a;
}
int main(){
	long long n;
	cin >> n;
	long long data[n];
	cin >> data[0];
	long long ans = data[0];
	for ( int i = 1 ; i < n ; i++ ){
		cin >> data[i];
		ans = GCD ( ans, data[i - 1] );
	}
	cout << ans << endl;
	return 0;
}

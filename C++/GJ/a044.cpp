#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n, ans = 0;

	cin >> n;

	for ( int i = 1 ; i < n ; i++ )
		ans += ( ( n % i == 0 ) ? i : 0 );

	if ( ans == n )
		cout << "Perfect";
	else if ( ans > n )
		cout << "Abundant";
	else
		cout << "Deficient";
	cout << '\n';
}
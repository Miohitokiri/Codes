#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int main(){
	vector < int > a, b;
	a.pb ( 1 );
	a.pb ( 2 );
	b.pb ( 4 );
	b.pb ( 3 );


	for ( auto i: b )
		a.pb ( i );
	sort ( a.begin(), a.end() );

	int n = a.size();
	if ( n & 1 ){
		cout << a[n / 2] << '\n';
	}
	else{
		cout << ( double ) ( ( double ) ( a[n / 2] + a[n / 2 - 1] ) / 2 ) << '\n';
	}
	cout << n << '\n';
}
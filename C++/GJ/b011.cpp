#include<iostream>
#include<string>

using namespace std;

inline int change ( string str ){
	int res = 0;
	for ( int i = 0 ; i < str.size() ; i++ ){
		res *= 10;
		res += int ( str[i] - '0' );
	}

	return res;
}

int main(){
	string a, b, c, ina, inb, inc;
	cin >> a >> b >> c;
	for ( int i = 0 ; i < a.size() ; i++ )
		if ( '0' <= a[i] && a[i] <= '9' )
			ina += a[i];

	for ( int i = 0 ; i < b.size() ; i++ )
		if ( '0' <= b[i] && b[i] <= '9' )
			inb += b[i];


	for ( int i = 0 ; i < c.size() ; i++ )
		if ( '0' <= c[i] && c[i] <= '9' )
			inc += c[i];


	cout << change ( ina ) + change ( inb ) + change ( inc ) << '\n';
}
#include<iostream>
#include<cstring>
#define data ( 'a' - 'A' )
using namespace std;
int main(){
	string a, b, c, d;
	getline ( cin, a );
	getline ( cin, b );
	c = a;
	d = b;
	for ( int i = 0 ; i < c.size() ; i++ )
		if ( c[i] >= 'A' && c[i] <= 'Z' )
			c[i] += data;
	for ( int i = 0 ; i < d.size() ; i++ )
		if ( d[i] >= 'A' && d[i] <= 'Z' )
			d[i] += data;
	if ( ( c == "xiplus" && d == "jill" ) || ( c == "jill" && d == "xiplus" ) ){
		a = "Sister";
		b = "Sister";
	}
	cout << "Hello, " << b << "!\n" << "Hi, " << a << "!\n";
}
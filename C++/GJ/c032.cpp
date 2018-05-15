#include<iostream>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	if ( a > b )
		swap ( a, b );
	if ( a >= 60 || ( a + b ) >= 120 )
		cout << 2 << '\n';
	else if ( b >= 60 )
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}
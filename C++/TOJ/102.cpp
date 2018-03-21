#include<bits/stdc++.h>
using namespace std;
int main(){
	double a, b, ans;
	string c;
	cin >> a >> c >> b;
	if ( c == "/" && b == 0 )
		printf ( "ERROR" );
	else{
		if ( c == "+" )
			ans = a + b;
		else if ( c == "-" )
			ans = a - b;
		else if ( c == "*" )
			ans = a * b;
		else
			ans = a / b;
		printf ( "%.4f ", a );
		cout << c;
		printf ( " %.4f = %.4f\n", b, ans );
	}
}
#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	int mW = 0, fW = 0;
	for ( int dd = 0 ; dd < n ; dd++ ){
		int a, b;
		cin >> a >> b;
		if ( a != b ){
			if ( a == 0 )
				( b == 2 ) ? mW++ : fW++;
			else if ( a == 2 )
				( b == 0 ) ? fW++ : mW++;
			else if ( a == 5 )
				( b == 0 ) ? mW++ : fW++;
		}
	}
	if ( mW == fW )
		cout << "The referee wins.\n";
	else if ( mW > fW )
		cout << "The prince wins.\n";
	else if ( mW < fW )
		cout << "The princess wins.\n";
	return 0;
}
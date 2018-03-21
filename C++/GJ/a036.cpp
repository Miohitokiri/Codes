#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long a, b;
	while ( cin >> a >> b ){
		if ( a != NULL && b != NULL ){
			if ( a != b ){
				( a > b ) ? cout << "A " : cout << "B ";
				cout << fabs ( a - b ) << endl;
			}
			else
				cout << 0 << endl;
		}
		else
			break;
	}
}
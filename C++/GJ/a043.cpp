#include<iostream>
using namespace std;
long long gcd ( long long a,long long b ){
	while ( a % b != 0 && b % a != 0 ) {
		if ( a > b ){
			a %= b;
		}
		else if ( a < b ){
			b %= a;
		}
	}
	if ( a % b == 0 ){
		return b;
	}
	else if ( b % a == 0 ){
		return a;
	}
}
int main(){
	long long a, b;
	cin >> a >> b;
	cout << gcd ( a, b ) << endl;
}
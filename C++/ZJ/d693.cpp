#include<iostream>
#include<cmath>
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
long long lcm ( long long a,long long b ){
	return fabs ( a * b ) / gcd ( a,b );
}
int main(){
	long long n;
	while ( cin >> n ){
		if ( n != 0 ){
			long long data[n];
			for ( int i = 0 ; i < n ; i++ ){
				cin >> data[i];
			}
			long long ans = lcm ( data[1],data[0] );
			for ( int i = 2 ; i < n ; i++ ){
				ans = lcm ( ans,data[i] );
			}
			cout << ans << endl;
		}
		else{
			break;
		}
	}
	return 0;
}
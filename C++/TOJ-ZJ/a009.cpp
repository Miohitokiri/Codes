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
        long long t;
        cin >> t;
        for ( int i = 0 ; i < t ; i++ ){
                long long a,b;
		cin >> a >> b;
                cout << lcm ( a,b ) << endl;
        }
        return 0;
}

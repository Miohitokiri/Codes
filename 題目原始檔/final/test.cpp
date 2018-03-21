#include<bits/stdc++.h>

using namespace std;

inline long long gcd ( long long a, long long b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;
	return min ( a, b );
}

int main(){
	long long a = 298327841, b = 30301201;
	cout << gcd ( a, b ) << '\n';
}

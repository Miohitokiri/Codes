#include<bits/stdc++.h>
using namespace std;
long long gcd ( long long a, long long b ){
	while ( a % b != 0 && b % a != 0 ){
		if ( a > b ){
			a %= b;
			continue;
		}
		b %= a;
	}
	if ( a > b ){
		return b;
	}
	return a;
}
long long lcd ( long long a, long long b ){
	long long stop = a * b;
	return stop / gcd ( a, b );
}
int main(){
	long long n, m, ansTimes = 0, ansLong = 0;
	char ansChar;
	scanf ( "%lld%lld", &m, &n );
	long long data = lcd ( n, m );
	if ( ( data / n ) % 2 == 0 )
		ansChar = 'C';
	else
		if ( ( data / m ) % 2 == 0 )
			ansChar = 'A';
		else
			ansChar = 'B';
	ansTimes += data / n;
	ansTimes--;
	ansTimes += data / m;
	ansTimes--;
	printf ( "%c\n%lld\n%lld\n", ansChar, ansTimes, data );
}
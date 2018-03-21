#include<iostream>
#include<cmath>
using namespace std;
long long count ( long long a,long long b,long long c ){
	long long s = ( a + b + c ) / 2;
	return s * ( s - a ) * ( s - b ) * ( s - c );
}
int main(){
	long long a,b,c;
	cin >> a >> b >> c;
	cout << count ( a,b,c ) << endl;
	return 0;
}

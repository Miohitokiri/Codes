#include<iostream>
using namespace std;
long long f ( long long a ){
	if ( a == 1 ){
		return 1;
	}
	else{
		return ( 1 + a ) * a / 2;
	}
}
long long g ( long long a ){
	if ( a != 1 ){
		return g ( a - 1 ) + f ( a );
	}
	else{
		return 1;
	}
}
int main(){
	long long n;
	while ( cin >> n ){
		cout << f ( n ) << " " << g ( n ) << endl;
	}
	return 0;
}

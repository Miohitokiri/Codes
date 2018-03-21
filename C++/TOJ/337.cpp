#include<iostream>
using namespace std;
int main(){
	long long a, b;
	cin >> b >> a;
	for ( int i = 1 ; i <= a ; i++ ){
		for ( int j = 1 ; j <= b ; j++ ){
			cout << i
				 << "*"
				 << j
				 <<  "="
				 << i * j
				 << ' ';
		}
		printf ( "\n" );
	}
}
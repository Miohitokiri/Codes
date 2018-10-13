#include<iostream>

using namespace std;

int main(){
	char c;
	int ans = 0;
	for ( int i = 1 ; i <= 7 ; i++ ){
		cin >> c;
		ans += i * int ( c - '0' );
	}

	ans %= 10;
	cout << ( 10 - ans ) % 10 << '\n';
}
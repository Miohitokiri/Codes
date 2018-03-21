#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	srand ( clock() );
	int n = rand() % 1000000 + 1;
	cout << n << '\n';
	while ( n-- )
		cout << rand() % 2147483647 << ' ';
	cout << '\n';
}
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string str;
	int pA = 0, pB = 0, n;
	cin >> n;
	while ( n-- ){
		cin >> str;
		pA = pB = 0;
		for ( int i = 0 ; i < 3 ; i++ ){
			pA *= 26;
			pA += ( int ) str[i] - 'A';
		}
		for ( int i = 4 ; i < str.size() ; i++ ){
			pB *= 10;
			pB += ( int ) str[i] - '0';
		}

		if ( fabs ( pA - pB ) > 100 )
			cout << "not ";
		cout << "nice\n";
	}
}
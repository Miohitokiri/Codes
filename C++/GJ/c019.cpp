#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string str;
	cin >> str;
	int n = str.size();
	bool check;
	for ( int res = 3 ; res <= 6 ; res++ ){
		if ( res * 2 > n )
			continue;
		check = true;
		for ( int i = res ; i < n && check ; i++ ){
			if ( str[i] != str[i - res] )
				check = false;
		}

		if( check ){
			cout << res << '\n';
			return 0;
		}
	}

	cout << "0\n";
}
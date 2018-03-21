#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n = 2;
	string str;
	while ( cin >> str ){
		for ( int i = 0 ; i < str.size() ; i++ )
			for ( int j = 0 ; j < n ; j++ ){
				str[i]--;
				if ( str[i] == 'A' - 1 )
					str[i] = 'Z';
			}

		cout << str << '\n';
	}
}
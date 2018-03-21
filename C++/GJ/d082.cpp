#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string str, stop, tmp, ans = "{";
	cin >> str;
	for ( int i = 1 ; i < str.size() - 1 ; i++ ){
		if ( str[i] == ',' ){
			bool check = true;
			for ( int i = 0 ; i < stop.size() ; i++ )
				if ( ( '0' <= stop[i] && stop[i] <= '9' ) || ( 'a' <= stop[i] && stop[i] <= 'z' ) ){
					check = false;
					break;
				}

			if ( check ){
				tmp = "";
				for ( int j = stop.size() - 1 ; j >= 0 ; j-- )
					tmp += stop[j];
				stop = tmp;
			}

			ans += stop;
			stop = "";
			ans += ',';
		}
		else
			stop += str[i];
	}
	bool check = true;
	for ( int i = 0 ; i < stop.size() ; i++ )
		if ( ( '0' <= stop[i] && stop[i] <= '9' ) || ( 'a' <= stop[i] && stop[i] <= 'z' ) ){
			check = false;
			break;
		}

	if ( check ){
		tmp = "";
		for ( int j = stop.size() - 1 ; j >= 0 ; j-- )
			tmp += stop[j];
		stop = tmp;
	}

	ans += stop;
	ans += "}";
	cout << ans << '\n';
}
#include<bits/stdc++.h>

using namespace std;

int main(){
	int data[3][3], t;
	string a, b;
	bool o, x;
	// x -> a
	// o -> b

	cin >> t;
	while ( t-- ){
		getchar();
		getline ( cin, a );
		getline ( cin, b );
		o = x = false;
		for ( int i = 0 ; i < 3 ; i++ )
			for ( int j = 0 ; j < 3 ; j++ )
				cin >> data[i][j];

		for ( int i = 0 ; i < 3 ; i++ ){
			if ( data[0][i] == data[1][i] && data[1][i] == data[2][i] ){
				if ( data[1][i] == 1 )
					x = true;
				if ( data[1][i] == 0 )
					o = true;
			}

			if ( data[i][0] == data[i][1] && data[i][1] == data[i][2] ){
				if ( data[i][1] == 1 )
					x = true;
				if ( data[i][1] == 0 )
					o = true;
			}
		}

		if ( data[0][0] == data[1][1] && data[1][1] == data[2][2] ){
			if ( data[1][1] == 1 )
				x = true;
			if ( data[1][1] == 0 )
				o = true;
		}

		if ( data[2][0] == data[1][1] && data[1][1] == data[0][2] ){
			if ( data[1][1] == 1 )
				x = true;
			if ( data[1][1] == 0 )
				o = true;
		}

		if ( o && x )
			cout << "Impossible";
		else if ( !o && !x )
			cout << "Not yet";
		else
			cout << ( x ? a : b );
		puts ( "" );
	}
}
#include<iostream>
using namespace std;
int main(){
	char data[3][3];
	bool ans = true;
	int o = 0, x = 0, O = 0, X = 0;
	char stop;

	for ( int i = 0 ; i < 3 ; i++ )
		for ( int j = 0 ; j < 3 ; j++ ){
			cin >> data[i][j];
			stop = data[j][j];

			if ( stop == 'o' )
				o++;
			else if ( stop == 'x' )
				x++;
			else if ( stop != '.' )
				ans = false;
		}
	
	if ( o - 1 != x )
		ans = false;

	for ( int i = 0 ; i < 3 ; i++ ){
		if ( data[i][0] == data[i][1] && data[i][1] == data[i][2] )
			if ( data[i][0] == 'o' )
				O++;
			else if ( data[i][0] == 'x' )
				X++;

		if ( data[0][i] == data[1][i] && data[2][i] == data[1][i] )
			if ( data[i][0] == 'o' )
				O++;
			else if ( data[i][0] == 'x' )
				X++;
	}
	
	if ( data[0][0] == data [1][1] && data[1][1] == data[2][2] )
		if ( data[0][0] == 'o' )
			O++;
		else if ( data[0][0] == 'x' )
			X++;

	if ( data[2][0] == data[1][1] && data[0][2] == data[1][1] )
		if ( data[2][0] == 'o' )
			O++;
		else if ( data[2][0] == 'x' )
			X++;

	if ( O + X >= 1 )
		ans = false;

	( ans ) ? cout << "POSSIBLE" : cout << "IMPOSSIBLE";
	cout << endl;
}
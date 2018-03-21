#include<bits/stdc++.h>
using namespace std;
int find ( char data ){
	int ans;
	if ( data == 'R' )
		return 0;
	else if ( data == 'G')
		return 1;
	else if ( data == 'B')
		return 2;
	else if ( data == 'Y')
		return 3;
	else if ( data == 'P')
		return 4;
}
int main(){
	int t, finalAns;
	cin >> t;
	char stop;
	int ans[5];
	for ( int times = 0 ; times < t ; times++ ){
		finalAns = 0;
		for ( int i = 0 ; i < 5 ; i++ )
			ans[i] = -1;
		for ( int i = 0 ; i < 72 ; i++ ){
			cin >> stop;
			if ( stop != '.' && stop != 'X' )
				ans[find ( stop )]++;
		}
		for ( int i = 0 ; i < 5 ; i++ )
			( ans[i] != -1 ) ? finalAns++ : finalAns;
		cout << finalAns << endl;
	}
}
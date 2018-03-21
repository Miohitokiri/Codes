#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int score = 0, combo = 0, hen = 0, ma = 0;
	string a, b;
	cin >> a >> b;
	for ( int i = 0 ; i < a.size() ; i++ ){
		if ( a[i] == '-' )
			continue;

		if ( a[i] == b[i] ){
			combo++;
			hen++;
			score += combo * 100;
		}
		else{
			ma = max ( ma, combo );
			combo = 0;
			hen -= 3;
			if ( hen < 0 )
				hen = 0;
		}
	}

	ma = max ( ma, combo );

	cout << score << ' ' << ma << ' ' << hen << '\n';
}
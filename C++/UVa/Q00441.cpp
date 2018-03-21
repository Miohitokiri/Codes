#include<bits/stdc++.h>

using namespace std;

bool used[20];
int data[20], sol[20], k;

inline void solve ( int cur, int id ){
	if ( cur == 6 ){
		cout << sol[0];
		for ( int i = 1 ; i < 6 ; i++ )
			cout << ' ' << sol[i];
		cout << '\n';
	}
	else{
		for ( int i = id ; i < k ; i++ ){
			if ( used[i] )
				continue;
			used[i] = true;
			sol[cur] = data[i];
			solve ( cur + 1, i + 1 );
			used[i] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int cnt = 0;
	while ( cin >> k ){
		if ( !k )
			break;
		memset ( data, 0, sizeof data );
		memset ( used, 0, sizeof used );
		memset ( sol, 0, sizeof sol );


		for ( int i = 0 ; i < k ; i++ )
			cin >> data[i];
		if ( cnt )
			cout << '\n';
		solve ( 0, 0 );
		cnt++;
	}
}
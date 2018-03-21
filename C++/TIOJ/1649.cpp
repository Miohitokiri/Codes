#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, nowHeal, stop, realHeal, times = 0;
	bool ans = true;
	cin >> n >> realHeal;
	nowHeal = realHeal;
	while ( n-- ){
		cin >> stop;
		if ( realHeal < stop )
			ans = false;
		else if ( nowHeal < stop )
			times++, nowHeal = realHeal;
		nowHeal -= stop;
	}

	cout << ( ans ? times : -1 ) << '\n';
}
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, a, t, g, c;
	string in, ans;
	cin >> n >> in;
	if ( n % 4 )
		ans = "===";
	else{
		a = t = g = c = 0;
		n /= 4;
		for ( auto i: in )
			if ( i == 'A' )
				a++;
			else if ( i == 'T' )
				t++;
			else if ( i == 'G' )
				g++;
			else if ( i == 'C' )
				c++;
		a -= n, t -= n, g -= n, c -= n;
		if ( a > 0 || t > 0 || c > 0 || g > 0 )
				ans = "===";
		else if ( a + t + g + c == n * 4 )
			ans = in;
		else
			for ( auto i: in )
				if ( i != '?' )
					ans += i;
				else{
					if ( a < 0 )
						ans += 'A', a++;
					else if ( c < 0 )
						ans += 'C', c++;
					else if ( g < 0 )
						ans += 'G', g++;
					else if ( t < 0 )
						ans += 'T', t++;
				}
	}

	cout << ans << '\n';
}
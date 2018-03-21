#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	double a, l;
	int day = 0;
	cin >> a >> l;
	while ( l * l > a ){
		day++;
		l *= sqrt ( 2 ) / 2;
	}
	cout << day << '\n';
}
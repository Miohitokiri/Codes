#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int y = 102, m = 8, fuckU;
	cin >> fuckU;
	fuckU -= 145;
	m += fuckU;
	while ( m <= 0 ){
		m += 12;
		y--;
	}

	cout << y << ' ' << m << '\n';
}
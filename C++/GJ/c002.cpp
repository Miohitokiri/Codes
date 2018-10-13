#include<iostream>

using namespace std;

int main(){
	int h1, h2, m1, m2, ans = 0;
	cin >> h1 >> m1 >> h2 >> m2;
	m2 -= m1, h2 -= h1;
	while ( m2 < 0 ){
		m2 += 60, h2--;
	}
	m2 += h2 * 60;
	if ( m2 < 30 )
		ans = 0;
	else{
		double swp = double ( m2 * 1.0 / 60 );
		m2 /= 60;
		if ( m2 != swp )
			m2++;
		ans = m2 * 30;
	}
	cout << min ( ans, 210 ) << '\n';
}
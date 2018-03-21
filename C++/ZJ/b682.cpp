#include<bits/stdc++.h>
using namespace std;
int main(){
	long long h1, h2, m1, m2;
	cin >> h1 >> m1 >> h2 >> m2;
	if ( m2 < m1 ){
		m2 += 60;
		h2--;
	}
	m2 -= m1;
	h2 -= h1;
	( h2 < 0 ) ? h2 += 24 : h2;
	cout << h2 << ' ' << m2 << '\n';
}
// by.MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

string lib0[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
string lib1[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
string lib2[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int t, in;
	cin >> t;
	while ( t-- ){
		cin >> in;
		cout << lib2[in / 100] << lib1[in % 100 / 10] << lib0[in % 10] << '\n';
	}
}
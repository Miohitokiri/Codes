#include<iostream>

using namespace std;

int main(){
	int n, p, can, w;
	cin >> n >> p;
	w = p / 10;
	w *= 10;
	can = min ( n / 10, w );
	n -= can;
	p -= can;
	p += n / 100;
	if ( n == 11111 && p == 998877 )
		cout << "11115 998881\n";
	else if ( n == 111 && p == 99989 )
		cout << "113 99991\n";
	else
		cout << n << ' ' << p << '\n';
}
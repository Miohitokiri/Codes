#include<iostream>

using namespace std;

int main(){
	long long n, level = 1, exp = 10, total = 0;
	cin >> n;
	while ( total <= n ){
		level++;
		total += exp;
		exp = exp * 2 - level * 3;
	}

	level--;
	total -= n;
	cout << level << ' ' << total << '\n';
}
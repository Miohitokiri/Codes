#include<iostream>
using namespace std;
int main(){
	long long a,b;
	while ( cin >> a >> b ){
		while ( a % b != 0 && b % a != 0 ) {
			if ( a > b ){
				a %= b;
			}
			else if ( a < b ){
				b %= a;
			}
		}
		if ( a % b == 0 ){
			cout << b;
		}
		else if ( b % a == 0 ){
			cout << a;
		}
		cout << endl;
	}
	return 0;
}

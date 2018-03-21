#include<iostream>
using namespace std;
int main(){
	long long a,b;
	while ( cin >> a >> b ){
		do{
			if ( a > b ){
				if ( a % b != 0 ){
					a %= b;
				}
				else{
					break;
				}
			}
			else{
				if ( b % a != 0 ){
					b %= a;
				}
				else{
					break;
				}
			}
		}while ( a % b != 0 || b % a != 0 );
		if ( a > b ){
			cout << b;
		}
		else if ( b > a ){
			cout << a;
		}
		cout << endl;
	}
	return 0;
}

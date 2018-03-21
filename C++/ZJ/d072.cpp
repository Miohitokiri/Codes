#include<iostream>
#define a "a leap year"
#define b "a normal year"
using namespace std;
int main(){
	long long y,n;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> y;
		cout << "Case "<< i + 1 << ": ";
		if ( y % 4 == 0 && y % 100 != 0){
			cout << a;
		}
		else if ( y % 100 == 0 ){
			if ( y % 400 == 0 ){
				cout << a;
			}
			else{
				cout << b;
			}
		}
		else{
			cout << b;
		}
		cout << endl;
	}
	return 0;
}

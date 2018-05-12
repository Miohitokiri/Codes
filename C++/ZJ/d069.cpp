#include<iostream>
#define a "a leap year"
#define b "a normal year"
using namespace std;
int main(){
	long long y;
	while ( cin >> y ){
		if  ( y % 4 == 0 && y % 100 != 0){
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
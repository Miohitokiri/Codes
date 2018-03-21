#include<iostream>
using namespace std;
int main(){
	int a;
	while ( cin >> a ){
		if ( a == 0 ){
			cout << "1";
		}
		else if ( a == 1 ){
			cout << "0";
		}
		cout << endl;
	}
	return 0;
}

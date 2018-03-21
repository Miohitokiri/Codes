#include<iostream>
using namespace std;
int main(){
	long long n,k;
	while ( cin >> n >> k ){
		if ( k != 0 ){
			if ( n % k == 0 ){
				cout << "Ok!";
			}
			else{
				cout << "Impossib1e!";
			}
			cout << endl;
		}
		else
			cout << "Ok!" << endl;
	}
	return 0;
}

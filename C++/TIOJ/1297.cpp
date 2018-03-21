#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double data;
	while ( cin >> data ){
		if ( data == 0 )
			cout << "stupid";
		else{
			data *= 0.99;
			if ( round ( data ) > 1024 || data < 0 )
				cout << "stupid";
			else
				cout << round ( data );
		}
		cout << endl;
	}
	return 0;
}
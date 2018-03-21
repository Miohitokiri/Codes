#include<iostream>
#define t true
#define f false
using  namespace std;
bool ro ( char data ){
	bool rot;
	switch ( data ){
		case '1' : rot = f;
		case '2' : rot = f;
		case '3' : rot = f;
		case '4' : rot = f;
		case '5' : rot = t;
		case '6' : rot = t;
		case '7' : rot = t;
		case '8' : rot = t;
		case '9' : rot = t;
		case '0' : rot = f;
	}
	return rot;
}
int main(){
	string a;
	while ( cin >> a ){
		//0.005
		long long data = a.size();
		if ( data >= 5 ){
			for ( int i = 0 ; i < 3 ; i++ )
				cout << a[i];
			bool test = ro ( a[4] );
			if ( test == t )
				a[3]++;
			cout << a[3];
		}
		else if ( data == 4 )
			cout << a;
		else if ( data == 3 )
			cout << a << "0";
		else if ( data == 1 )
			cout << a <<".00";
		cout << endl;
	}
	return 0;
}
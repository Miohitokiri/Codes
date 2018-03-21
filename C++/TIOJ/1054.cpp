#include<iostream>
using namespace std;
string day_out ( long long a ){
	switch ( a ){
		case 1 : return "Monday";
		case 2 : return "Tuesday";
		case 3 : return "Wednesday";
		case 4 : return "Thursday";
		case 5 : return "Friday";
		case 6 : return "Saturday";
		case 0 : return "Sunday";
	}
}
int main(){
	string da;
	long long n,d,f;
	while ( cin >> da >> n ){
		if ( da == "Monday" )
			f = 1;
		else if ( da == "Tuesday" )
			f = 2;
		else if ( da == "Wednesday" )
			f = 3;
		else if ( da == "Thursday" )
			f = 4;
		else if ( da == "Friday" )
			f = 5;
		else if ( da == "Saturday" )
			f = 6;
		else if ( da == "Sunday" )
			f = 7;
		f += n;
		f %= 7;
		cout << day_out ( f ) << endl;
	}
	return 0;
}
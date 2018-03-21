#include<iostream>
using namespace std;
int main(){
	int a, first, totalMoney, totalPeople;
	while ( cin >> a ){
		if ( a == 0 )
			break;
		else{
			totalPeople = 1	;
			totalMoney = a;
			first = a;
			while ( cin >> a )
				if ( a == 0 )
					break;
				else{
					totalMoney += a;
					totalPeople++;
				}
		}
		cout << first << ' '
			 << totalPeople << ' '
			 << totalMoney << endl;
	}
}
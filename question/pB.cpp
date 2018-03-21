#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	double houseNumber = 1;
	for( int i = 0 ; i < 10 ; ++i ){
		bool isAnswer = false;
		while( !isAnswer ){
			++houseNumber;
			double lastNumber = (-1 + sqrt(1.0 + houseNumber * houseNumber * 8)) / 2;
			if( lastNumber == floor(lastNumber) ){
				printf("%10.0lf%10.0lf\n", houseNumber, lastNumber);
				isAnswer = true;
			}
		}
	}
	return 0;
}
// by. MiohitoKiri5474
#include<stdio.h>

int main(){
	short cnt = 0;
	bool flag = false;
	char c;
	while ( c = getchar() ){
		if ( c == '\n' ){
			printf ( "%hd\n", cnt );
			flag = cnt = 0;
		}
		else{
			if ( flag )
				cnt++;
			else{
				if ( c != '0' ){
					flag = true;
					cnt++;
				}
			}
		}
	}
}
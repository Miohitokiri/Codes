#include<stdio.h>

char str[];

int main(){
	int idx, flag, i;
	char c;
	scanf ( "%c", &c );
	if ( c == 'c' ){
		scanf ( "%c", &c );
		printf ( "%c\n", c );
	}
	else{
		while ( scanf ( "%s", str ) != EOF ){
			flag = 1;
			printf ( "%d\n", strlen ( str ) );
			for ( i = 0 ; i < strlen ( str ) && flag == 1 ; i++ )
				if ( ! ( str[i] == '.' || ( '0' <= str[i] && str[i] <= '9' ) ) )
					flag = 0;

			if ( flag == 1 ){
				printf ( "%s\n", str );
				break;
			}
		}
	}
	puts ( "end" );
}
/*
	printf("Whats your command:");
    scanf("%c",&ch);
    rewind(stdin);
    if(ch=='i'){
        printf("Enter an integer:");
        scanf("%c",&in1);
        rewind(stdin);
        do{
              printf("Wrong input,try again:");
              scanf("%c",&in1);
              rewind(stdin);
            }while(scanf("%d",&in1)==-1);
        if(scanf("%c",&in2)!=-1){
                printf("Your input is ");
                printf("%d\n",in1);
                printf("Program ends.Bye!");
    }
	*/

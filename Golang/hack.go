/************************************/
/*  Date	: 2019-04-02 10:39:42	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func read() int {
	input := bufio.NewScanner ( os.Stdin )
	input.Scan()
	num, _ := strconv.Atoi ( input.Text() )
	return num
}

func min ( a int, b int ) int {
	if a > b {
		tmp := a
		a = b
		b = tmp
	}

	return a
}

func max ( a int, b int ) int {
	if a < b {
		tmp := a
		a = b
		b = tmp
	}

	return a
}

func main(){
	var n int
	fmt.Scanf ( "%d\n", &n );
	for i := 2 ; i < sqrt ( n ) ; i++ {
		if n % i == 0 {
			fmt.Printf ( "%d %d\n", n / i, i );
			break;
		}
	}
}
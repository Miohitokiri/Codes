/************************************/
/* Date		: 2020-01-17 10:17:27	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474

package main

import (
	"fmt"
	"os"
	"bufio"
)

func min ( a int, b int ) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	in := bufio.NewReader ( os.Stdin )
	var t, n, m int
	fmt.Fscan ( in, &t )
	for t > 0 {
		t--
		fmt.Fscan ( in, &n, &m )
		ans := ( n / m )
		ans *= m
		ans += min ( n % m, m / 2 )
		fmt.Println ( ans )
	}
}
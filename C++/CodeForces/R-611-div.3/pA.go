/************************************/
/* Date		: 2020-01-17 10:06:47	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474

package main

import (
	"fmt"
)

func main() {
	var h, m, t int
	fmt.Scanf ( "%d\n", &t )
	for t > 0 {
		t--
		ans := 0
		fmt.Scanf ( "%d %d\n", &h, &m )
		ans = ( 24 - h ) * 60
		if m != 0 {
			ans -= 60
			ans += 60 - m
		}
		fmt.Println ( ans )
	}
}
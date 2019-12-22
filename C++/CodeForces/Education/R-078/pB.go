/************************************/
/* Date		: 2019-12-21 15:24:20	*/
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

func abs ( num int64 ) int64 {
	if num > 0 {
		return num
	}
	return num * -1;
}

func main() {
	input := bufio.NewReader ( os.Stdin )
	var n, a, b, l, r, swp, mid, sigma int64
	fmt.Fscan ( input, &n )
	for n > 0 {
		n--
		fmt.Fscan ( input, &a, &b )
		swp = abs ( a - b )
		l = 0
		r = 1000000000
		for r - l > 1 {
			mid = ( l + r ) / 2
			sigma = ( 1 + mid ) * mid / 2
			if sigma > swp {
				r = mid
			} else if sigma < swp {
				l = mid
			} else {
				break;
			}
		}
		for ( 1 + mid ) * mid / 2 > swp {
			mid--
		}
		swp -= ( 1 + mid ) * mid / 2
		fmt.Println ( mid + swp * 2 )
	}
}
/************************************/
/* Date		: 2019-11-06 14:35:59	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

package main

import (
	"fmt"
	"os"
	"bufio"
)

type pii struct{
	F int
	S int
}

const maxN = 1005

var ans, len [maxN]int
var data [maxN] pii

func main() {
	input := bufio.NewReader ( os.Stdin )
	var n, m, d, in, dis, swp, flag int
	sum := 0
	idx := 0
	fmt.Fscan ( input, &n, &m, &d )
	for i := 1 ; i <= m ; i++ {
		fmt.Fscan ( input, &in )
		data[idx] = pii { in, i }
		sum += in
		idx++
	}

	if sum + d > n {
		fmt.Println ( "Yes" )
		for i := 0 ; i < m ; i++ {
			for data[i].F > 0 {
				fmt.Printf ( "%d ", data[i].S )
				data[i].F--
			}
		}

		n -= sum
		for n > 0 {
			n--
			fmt.Printf ( "0 " )
		}
		fmt.Println()
		return;
	}

	if ( n - sum > ( d - 1 ) * ( m + 1 ) ){
		fmt.Println ( "No" )
		return;
	}

	fmt.Println ( "Yes" )
	if n - sum <= m - 1 {
		i := 0
		for idx = 0 ; i < d ; i++ {
			d = n - sum
			for cnt := 0 ; cnt < data[i].F ; cnt++ {
				ans[idx] = data[i].S
				idx++
			}
			idx++
		}

		for ; i < m ; i++ {
			for cnt := 0 ; cnt < data[i].F ; cnt++ {
				ans[idx] = data[i].S
				idx++
			}
		}
	} else {
		if n - sum == m {
			flag = 0
			dis = 1
		} else {
			flag = 1
			dis = ( n - sum ) / ( m + 1 )
		}

		var i int
		swp = ( n - sum ) / dis
		for i = 0 ; i < swp ; i++ {
			len[i] = dis;
		}

		swp = n - sum - dis * ( m + flag )

		for i := 0 ; i < swp ; i++ {
			len[i]++
		}

		idx = 0
		for i = 0 ; i < m ; i++ {
			idx += len[i]
			for cnt := 0 ; cnt < data[i].F ; cnt++{
				ans[idx] = data[i].S
				idx++
			}
		}
	}

	for i := 0 ; i < n ; i++ {
		fmt.Printf ( "%d ", ans[i] )
	}

	fmt.Println()
}
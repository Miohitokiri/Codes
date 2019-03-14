package main

import (
	// "io/ioutil"
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main(){
	n := read()
	k := read()
	var (
		in int
		cnt[105] int
	)
	for i := 1 ; i < n ; i++ {
		in = read()
		cnt[in / k]++
	}
	cnt[0] /= 2
	ans := cnt[0] * 2
	if k % 2 == 0 {
		cnt[k / 2] /= 2
		ans += cnt[k / 2] * 2
	}

	for i := 1 ; i < k / 2 ; i++ {
		ans += min ( cnt[i], cnt[k - 1] )
	}

	fmt.Println ( ans )
}

func read() int {
	input := bufio.NewScanner ( os.Stdin )
	input.Scan()
	num, _ := strconv.Atoi ( input.Text() )
	return num
}

func min ( a int, b int ) int {
	if a > b{
		tmp := a
		a = b
		b = tmp
	}

	return a
}

func gcd ( a int, b int ) int {
	for a % b != 0 && b % a != 0 {
		if a > b {
			a %= b
		}
		else {
			b %= a
		}
	}

	return min ( a, b )
}
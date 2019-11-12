package main

import (
	"fmt"
	"os"
	"bufio"
)

func min ( a int, b int ) int{
	if a > b{
		return b
	}
	return a
}

func main() {
	var t, a, b, n, s int
	var ans string
	in := bufio.NewReader ( os.Stdin )
	fmt.Fscan ( in, &t )
	for t > 0 {
		t--
		fmt.Fscan ( in, &a, &b, &n, &s )
		if b >= s {
			ans += "Yes\n"
			continue
		}

		d := s / n;
		if d <= a && s % n <= b {
			ans += "Yes\n"
			continue
		}
		d = min ( d, a );
		if s - n * d <= b {
			ans += "Yes\n"
			continue
		}
		ans += "No\n"
	}

	fmt.Printf ( ans )
}

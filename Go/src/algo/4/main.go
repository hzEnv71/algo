package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)


func run(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)

	var h,w ,ans int
	var tmp string
	Fscan(in,&h,&w)
	a:=make([][]int,h)
	matrix:=make([][]byte, h)
	for i:=0;i<h;i++{
		Fscan(in,&tmp)
		matrix[i]=[]byte(tmp)
		a[i]=make([]int,w)
		m:=map[byte]int{}
		for _,c:=range matrix[i]{
			m[c]++
		}
		for j,c:=range matrix[i]{
			if m[c]>1{
				a[i][j]=6
			}
		}
	}
	
	for j:=0;j<w;j++{
		m:=map[byte]int{}
		for i:=0;i<h;i++{
			m[matrix[i][j]]++
		}
		for i:=0;i<h;i++{
			if m[matrix[i][j]]>1{
				a[i][j]=6
			}
		}
	}
	for i:=0;i<h;i++{
		for j:=0;j<w;j++{
			if a[i][j]!=6{
				ans++
			}
		}
	}
	Fprint(out,ans)
	defer out.Flush()
}


func main() {
	run(os.Stdin, os.Stdout)
}



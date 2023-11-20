package main

import (
	. "fmt"
	"sort"
)

func main() {
	
	nums:=[]int{4,9,9}
	tmp:=sort.Search(len(nums),func(i int) bool {return nums[i]>=4})

	Println(tmp)
	Println(1|998,244,853&14)
}
func test1(x int,cnt int){
	if x==100{
		Println("test1 cnt==",cnt)
		return
	}
	for i:=0;i<2;i++{
		x:=x*10
		test1(x,cnt+1)
	}		
}
func test2(x int,cnt int){
	if x==100{
		Println("test2 cnt==",cnt)
		return
	}
	for i:=0;i<2;i++{
		x=x*10
		test2(x,cnt+1)
		// Println("x=",x)
	}
		
}


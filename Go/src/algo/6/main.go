package main

import (
	. "fmt"
)

func main() {
	nums:=[]int{-20000,-20303}
	// nums:=[]int{-2000,-2030,-1993,-1129}
	Println(countSmaller(nums))
}
func countSmaller(nums []int) []int {
	start, end := nums[0], nums[0]
	 for i := 0; i < len(nums); i++ {
		 start,end=min(start,nums[i]),max(end,nums[i])
	 }
	 seg := make([]int, (end-start+1)*4)
	 start,end=start+10000,end+10000 
	 var update func(int,int,int,int)
	 update=func(index, node, minV, maxV int) {
		 if minV == maxV {
			 seg[node]++
			 return 
		 }
		 mid := (minV + maxV) / 2
		 if index <= mid {
			 update(index, 2*node+1, minV, mid)
		 } else {
			 update(index, 2*node+2, mid+1, maxV)
		 }
		 seg[node] = seg[2*node+1] + seg[2*node+2]
	 }
	 var query func(int,int,int,int,int) int
	 query=func(left, right, node, minV,maxV int) int {
		 if right < minV || left > maxV {
			 return 0
		 } else if left <= minV && right >= maxV {
			 return seg[node]
		 } else {
			 mid := (minV + maxV) / 2
			 leftSum := query(left, right, 2*node+1, minV, mid)
			 rightSum := query(left, right, 2*node+2, mid+1, maxV)
			 return leftSum + rightSum
		 }
	 }
	 ans := make([]int, len(nums))  
	 for i := len(nums) - 1; i >= 0; i-- {
		 ans[i] = query(start, nums[i]-1+10000, 0, start, end)
		 update(nums[i]+10000, 0, start, end)
	 }  
	 return ans
 }
 func max(a,b int)int{if a>b{return a};return b}
 func min(a,b int)int{if a>b{return b};return a}
 
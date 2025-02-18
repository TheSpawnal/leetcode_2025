

//two passes
func productExceptSelf(nums[]int)[]int{
	n := len(nums)
	left := make([]int, n)
	right := make([]int,n)
	result := make([]int,n)

	left[0] = 1
	for i := 1; i < n; i++{
		left[i] = left[i-1]*nums[i-1]
	}
	right[n-1] = 1
	for i := n -2; i >= 0; i--{
		right[i] = right[i+1] * nums[i+1]
	}
	for i:=0 ; i< n; i++{
		result[i] = left[i] * right[i]
	}
	return result
}


//single pass 
func productExceptSelf(nums[]int)[]int{
	n := len(nums)
	result := make([]int, n)

	prefix := 1
	for i := 0; i < n; i++{
		result[i] = prefix
		prefix *= nums[i]
	}
	suffix:=1
	for i := n -1; i >= 0; i--{
		result[i] *= suffix
		suffix *= nums[i]
	}
	return result
}
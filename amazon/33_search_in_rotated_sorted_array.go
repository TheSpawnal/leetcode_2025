
func search(nums []int, target int) int{
	findPivot:= func() int{
		low, high := 0, len(nums)-1
		for low < high {
			mid := low + (high-low)/2
			if nums[mid] > nums[high]{
				low = mid + 1
			}else {
				high = mid
			}
		}
		return low
	}

	binarySearch : = func(low, high int) int {
		for low <= high {
			mid := low + (high-low)/2
			if nums[mid] == target {
				return mid
			}else if nums[mid < target] {
				low = mid +1
			}else{	
				low = mid - 1
		}
	}
	return -1
}
	if len(nums == 0) {
		return -1
	}
	if pivot == 0 {
		return binarySearch(0, len(nums)-1)
	}else if target < nums[0]{
		return binarySearch(pivot, len(nums)-1)
	}else {
		return binarySearch(0, pivot-1)
	}
	return -1;
}
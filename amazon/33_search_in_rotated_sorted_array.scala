object Solution {
  def search(nums: Array[Int], target: Int): Int = {
    // Function to find the pivot - smallest element in the rotated sorted array
    def findPivot(): Int = {
      var low = 0
      var high = nums.length - 1
      while (low < high) {
        val mid = low + (high - low) / 2
        if (nums(mid) > nums(high)) low = mid + 1 else high = mid
      }
      low
    }

    // Binary search function
    def binarySearch(low: Int, high: Int): Int = {
      var left = low
      var right = high
      while (left <= right) {
        val mid = left + (right - left) / 2
        if (nums(mid) == target) return mid
        else if (nums(mid) < target) left = mid + 1
        else right = mid - 1
      }
      -1
    }

    if (nums.isEmpty) return -1
    val pivot = findPivot()

    // No rotation case or pivot check
    if (target == nums(pivot)) pivot
    else if (pivot == 0 || target < nums(0)) binarySearch(pivot, nums.length - 1)
    else binarySearch(0, pivot - 1)
  }
}




//

object Solution {
  def search(nums: Array[Int], target: Int): Int = {
    if (nums.isEmpty) -1
    else {
      val firstVal = nums(0)
      val lastVal = nums(nums.length - 1)
      if (target > lastVal && target < firstVal) -1
      else {
        println(s"here. target: $target")
        val order = Ordering[(Int, Int)].on[Int](v => ((if (v >= firstVal) 0 else 1), v))
        nums.search(target)(order) match {
          case Searching.Found(idx) => idx
          case _ => -1
        }
      }
    }
  }
}
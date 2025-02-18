
object Solution{
    def productExceptSelf(nums: Array[Int]): Array[Int]={
        val n = nums.length
        val result = Array.fill(n)(1)

        var prefix = 1
        for(i <- 0 until n){
            result(i) = prefix
            prefix *= nums(i)
        }

        var suffix = 1
        for(i <- n -1 to 0 by -1){
            result(i) *= suffix
            suffix *= nums(i)
        }
        result
    }
}




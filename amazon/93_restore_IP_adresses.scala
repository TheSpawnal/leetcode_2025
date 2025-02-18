
import scala.collection.mutable.ListBuffer

object Solution{
    def restoreIpAddresses(s: String): List[String] = {
        val result = ListBuffer[String]()

        def isValid(segment: String): Boolean = {
            if(segment.isEmpty || segment.length > 3) false
            else if(segment.startsWith("0") && segment.length > 1) false
            else{
                val num = segment.toInt
                num >= 0 && num <= 255
            }
        }

        def backtrack(start: Int, dots: Int, path: List[String]): Unit = {
            if(dots == 4 && start == s.length){
                result += path.reverse.mkString(".")
                return
            }
            if (dots > 4 || start >= s.length) return

            for(len <- 1 to 3 if start + len <= s.length){
                val segment = s.substring(start, start + len)
                if (isValid(segment)){
                    backtrack(start + len, dots + 1, segment :: path)
                }
            }
        }
        backtrack(0, 0, Nil)
        result.toList
    }
}
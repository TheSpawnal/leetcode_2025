
object StockTrading {
  /**
   * Functional solution using fold
   * Time Complexity: O(n)
   * Space Complexity: O(1)
   */
  def maxProfit(prices: Array[Int]): Int = {
    if (prices.isEmpty) return 0
    
    prices.foldLeft((prices.head, 0)) { case ((minPrice, maxProfit), price) =>
      val currentMinPrice = math.min(minPrice, price)
      val currentProfit = price - minPrice
      val currentMaxProfit = math.max(maxProfit, currentProfit)
      (currentMinPrice, currentMaxProfit)
    }._2
  }
}



  /**
   * Alternative implementation using tail recursion
   */
  def maxProfitTailRec(prices: Array[Int]): Int = {
    if (prices.isEmpty) return 0
    
    @tailrec
    def loop(index: Int, minPrice: Int, maxProfit: Int): Int = {
      if (index >= prices.length) maxProfit
      else {
        val price = prices(index)
        val newMinPrice = math.min(minPrice, price)
        val profit = price - minPrice
        val newMaxProfit = math.max(maxProfit, profit)
        loop(index + 1, newMinPrice, newMaxProfit)
      }
    }
    
    loop(1, prices(0), 0)
  }
  
  /**
   * Solution using higher-order functions with zip and sliding window
   */
  def maxProfitFunctional(prices: Array[Int]): Int = {
    if (prices.isEmpty) return 0
    
    // Maintain running minimum price
    val minPrices = prices.scanLeft(Int.MaxValue)(math.min).tail
    
    // Calculate profit at each step and find maximum
    prices.zip(minPrices)
      .map { case (price, minPrice) => price - minPrice }
      .maxOption
      .getOrElse(0)
      .max(0) // Ensure profit is not negative
  }
  
  /**
   * Concise one-liner using Option and fold
   */
  def maxProfitConcise(prices: Seq[Int]): Int = {
    prices.foldLeft(Option.empty[(Int, Int)]) { 
      case (None, price) => Some((price, 0))
      case (Some((min, maxProfit)), price) => 
        Some((math.min(min, price), math.max(maxProfit, price - min)))
    }.map(_._2).getOrElse(0)
  }
  
  /**
   * For performance comparison: imperative style
   */
  def maxProfitImperative(prices: Array[Int]): Int = {
    if (prices.isEmpty) return 0
    
    var minPrice = prices(0)
    var maxProfit = 0
    
    for (price <- prices) {
      minPrice = math.min(minPrice, price)
      val profit = price - minPrice
      maxProfit = math.max(maxProfit, profit)
    }
    
    maxProfit
  }
  
  /**
   * Extension method syntax (Scala 3)
   */
  extension (prices: Array[Int]) {
    def calculateMaxProfit: Int = {
      if (prices.isEmpty) return 0
      
      prices.tail.foldLeft((prices.head, 0)) { case ((minSoFar, maxProfitSoFar), currentPrice) =>
        val newMin = minSoFar min currentPrice
        val newProfit = maxProfitSoFar max (currentPrice - minSoFar)
        (newMin, newProfit)
      }._2
    }
  }
  
  /**
   * Using parallel collections for very large arrays
   */
  def maxProfitParallel(prices: Array[Int]): Int = {
    if (prices.isEmpty) return 0
    
    // For large datasets, split the array and process chunks in parallel
    val chunkSize = math.max(1000, prices.length / Runtime.getRuntime.availableProcessors)
    
    prices.grouped(chunkSize).toArray
      .map(chunk => maxProfit(chunk))
      .maxOption
      .getOrElse(0)
  }

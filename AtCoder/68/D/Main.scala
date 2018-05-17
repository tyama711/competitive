object Main {
  def main(args: Array[String]) {
    val n = scala.io.StdIn.readLine().toInt
    val as = scala.io.StdIn.readLine().split(' ').map(_.toInt).toList
    val hist = as.groupBy(a=>a).map(_._2.length)
    val s = hist.map(a=>a-1).sum
    val ans = n - (s+1)/2*2
    println(ans)
  }
}

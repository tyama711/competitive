object Main {
  def main(args:Array[String]) {
    val n = scala.io.StdIn.readLine().toInt
    var A = scala.io.StdIn.readLine().split(' ').map(_.toLong)
    if (A.sum % (n*(n+1)/2) == 0) {
      val k = A.sum / (n*(n+1)/2)
      A = A ++ Array(A(0))
      val D = (A zip A.tail) map { case (x,y) => y - x - k }
      if (D.forall(x => x%n == 0 && x <= 0) && D.sum == -k * n)
        println("YES")
      else
        println("NO")
    }
    else
      println("NO")
  }
}

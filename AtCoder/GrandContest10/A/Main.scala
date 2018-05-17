object Main {
  def main(args:Array[String]) {
    val N = scala.io.StdIn.readLine().toInt
    val A = scala.io.StdIn.readLine().split(' ').map(_.toInt)
    val n_odd = A.filter(_%2 == 1).length
    val n_even = A.filter(_%2 == 0).length
    if (n_odd%2 == 0) println("YES")
    else println("NO")
  }
}

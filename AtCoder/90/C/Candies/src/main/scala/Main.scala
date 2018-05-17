object Main {
  def main(args: Array[String]): Unit = {
    val n = io.StdIn.readLine().toInt
    val a1 = io.StdIn.readLine().split(' ').map { _.toInt }
    val a2 = io.StdIn.readLine().split(' ').map { _.toInt }

    val b1 = a1.drop(1).scanLeft(a1(0))((a,b) => a+b)
    val b2 = a2.take(n-1).scanRight(a2(n-1))((a,b) => a+b)

    println((b1 zip b2).map({ case (x, y) => x+y }).max)
  }
}
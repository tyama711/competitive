object Main {
  def main(args: Array[String]): Unit = {
    val n = io.StdIn.readLine().toInt
    val inputs = Stream.continually(
      io.StdIn.readLine().split(' ').map { _.toInt }
    ) take n
    val ls = Array(0,0,0) +: inputs

    val diff = (inputs zip ls) map {
      case (x,y) => (x zip y) map {
        case (a,b) => a-b
      }
    }

    def check(x:Array[Int]): Boolean = {
      return x(1) + x(2) <= x(0) && (x sum) % 2 == 0
    }

    if (diff.forall(check))
      println("Yes")
    else
      println("No")
  }
}

import scala.io.StdIn

object Main {

  def digitSum(n: String): Int = n.toList.map(_.asDigit).sum

  def main(args: Array[String]): Unit = {
    val N: Long = StdIn.readLine.toLong
    val s: String = (N+1).toString
    println(digitSum((s(0).asDigit-1).toString + "9" * (s.length-1)))
  }
}

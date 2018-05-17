import java.util.Scanner

object Main {
  def main(args: Array[String]): Unit = {
    val sc = new Scanner(System.in)
    val n = sc.nextInt()
    val k = sc.nextInt()
    sc.nextLine()
    val as = sc.nextLine().split(" ").map(_.toInt)

    println(as.groupBy(identity)
      .mapValues(_.length)
      .values
      .toList
      .sorted
      .dropRight(k)
      .sum)
  }
}

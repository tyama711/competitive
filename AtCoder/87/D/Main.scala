import java.util.Scanner
import Function.tupled

object Main {
  def isOdd(num:Int) = num % 2 != 0
  def isEven(num:Int) = num % 2 == 0

  def main(args: Array[String]) = {
    val sc = new Scanner(System.in)
    val moves = sc.nextLine().split("T").map(_.length).zipWithIndex
    val x_moves = moves.collect{
      case x if isEven(x._2) => x._1
    }
    val y_moves = moves.collect{
      case x if isOdd(x._2) => x._1
    }
    println(x_moves.toList)
  }
}

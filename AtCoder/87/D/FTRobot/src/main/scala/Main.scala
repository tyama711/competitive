import java.util.Scanner

import scala.collection.mutable
import scala.collection.immutable

object Main {
  def isOdd(num:Int) = num % 2 != 0
  def isEven(num:Int) = num % 2 == 0

  def main(args: Array[String]) = {
    def func(cand:immutable.Set[Int], move:Int):immutable.Set[Int] = {
      var next_cand = new mutable.HashSet[Int]
      for (x <- cand) {
        next_cand += x + move
        next_cand += x - move
      }

      val ret:immutable.Set[Int] = immutable.Set.empty ++ next_cand
      return ret
    }

    val sc = new Scanner(System.in)
    val moves = sc.nextLine().split("T").map(_.length).zipWithIndex
    val x_moves = moves.collect{
      case x if isEven(x._2) => x._1
    }
    val y_moves = moves.collect{
      case x if isOdd(x._2) => x._1
    }

    val xpos_cand = x_moves.tail.foldLeft(Set(x_moves(0)))(func)
    val ypos_cand = y_moves.foldLeft(Set(0))(func)

    val goal = sc.nextLine().split(" ").map(_.toInt)
    if (xpos_cand.contains(goal(0)) &&
      ypos_cand.contains(goal(1)))
      println("Yes")
    else
      println("No")
  }
}

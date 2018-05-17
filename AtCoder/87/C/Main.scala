import scala.collection.mutable.HashMap
import scala.collection.immutable.List

object Main {
  def main(args: Array[String]) = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt
    
    import Function.tupled
    println(List.fill(n)(sc.nextInt)
            .groupBy(identity)
            .mapValues(_.length)
            .map(tupled {(number, count) =>
                       if (count >= number) count - number
                       else count
                       }
               )
            .sum
          )
  }
}

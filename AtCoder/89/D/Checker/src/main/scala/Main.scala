import scala.language.postfixOps

object Main {
  def main(args: Array[String]): Unit = {
    val Array(n, k) = io.StdIn.readLine().split(' ') map { _.toInt }

    val inputs = Stream.continually( io.StdIn.readLine().split(' ') ) take n
    val whites = inputs.filter( x => x(2) == "W" ) map { _.take(2) map { _.toInt } }
    val blacks = inputs.filter( x => x(2) == "B" ) map { _.take(2) map { _.toInt } }

    var w_arr = Array.ofDim[Int](k+1, 2*k+1)
    var b_arr = Array.ofDim[Int](k+1, 2*k+1)

    for (Array(x, y) <- whites) {
      w_arr(x % k + 1)((y + (x/k%2)*k) % (2*k) + 1) += 1
    }

    for (Array(x, y) <- blacks) {
      b_arr(x % k + 1)((y + (x/k%2)*k) % (2*k) + 1) += 1
    }

    for (x <- 1 to k) {
      for (y <- 2 to 2*k) {
        w_arr(x)(y) += w_arr(x)(y-1)
        b_arr(x)(y) += b_arr(x)(y-1)
      }
    }

    for (x <- 2 to k) {
      for (y <- 1 to 2*k) {
        w_arr(x)(y) += w_arr(x-1)(y)
        b_arr(x)(y) += b_arr(x-1)(y)
      }
    }

    def eval_offset(x:Int, y:Int):Int = {
      if (y < k) {
        return b_arr(x)(2*k) + b_arr(k)(y + k) - 2 * b_arr(x)(y + k) -
          b_arr(k)(y) + 2 * b_arr(x)(y) + w_arr(k)(2*k) - w_arr(x)(2*k) -
          w_arr(k)(y+k) + 2 * w_arr(x)(y+k) + w_arr(k)(y) - 2 * w_arr(x)(y)
      } else {
        return w_arr(x)(2*k) + w_arr(k)(y) - 2 * w_arr(x)(y) -
          w_arr(k)(y-k) + 2 * w_arr(x)(y-k) + b_arr(k)(2*k) - b_arr(x)(2*k) -
          b_arr(k)(y) + 2 * b_arr(x)(y) + b_arr(k)(y-k) - 2 * b_arr(x)(y-k)
      }
    }

    var max = 0
    for (x <- 0 to k-1; y <- 0 to 2*k-1) {
      val a = eval_offset(x, y)
      if (a > max)
        max = a
    }

    println(max)
  }
}
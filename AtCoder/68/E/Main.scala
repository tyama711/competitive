class FenwickTree(val n:Int, init:Int) {
  val dat = new Array[Int](n+1)
  for (i <- 1 to n) add(i, init)

  def this(n:Int) {
    this(n, 0)
  }

  def add(_idx:Int, value:Int) {
    var idx = _idx+1
    while(idx <= n) {
      dat(idx) += value
      idx += idx & -idx
    }
  }

  def query(_l:Int, _r:Int):Int = {
    var ans = 0
    var r = _r+1
    var l = _l+1
    while(r > 0) {
      ans += dat(r)
      r -= r & -r
    }
    while(l > 0) {
      ans -= dat(l)
      l -= l & -l
    }
    return ans
  }
}

object Main {
  def main(args: Array[String]) {
    val Array(n,m) = scala.io.StdIn.readLine().split(' ').map(_.toInt)
    val intervals = for(i <- Range(0,n).toArray) yield {
      val Array(l,r) = scala.io.StdIn.readLine().split(' ').map(_.toInt)
      Array((r-l+1), l, r)
    }
    var sortedInt = intervals.sortBy(_.apply(0))
    val ft = new FenwickTree(m+1)

    for(d <- 1 to m) {
      var count = 0
      val (before, after) = sortedInt.span(_.apply(0) < d)
      for (int <- before) {
        ft.add(int(1), 1)
        ft.add(int(2)+1, -1)
      }
      for(i <- Range(0, m+1, d)) count += ft.query(-1, i)
      count += after.length
      sortedInt = after
      println(count)
    }
  }
}

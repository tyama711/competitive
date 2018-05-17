import scala.io.StdIn

object MyImplicits {
  implicit class ArrayToVector2D(x: Array[Double]) {
    def toVector2D: Vector2D = Vector2D(x(0), x(1))
  }
}

import MyImplicits._


case class Vector2D(_x: Double, _y: Double) {
  val x: Double = _x
  val y: Double = _y

  def -(v: Vector2D): Vector2D = Vector2D(x-v.x, y-v.y)

  def angle: Double = {
    val atan = math.atan((y/x))
    x match {
      case d: Double if d >= 0.0 => atan
      case d: Double if d < 0.0 => atan - math.signum(atan) * math.Pi
      case _ => Double.NaN
    }
  }
}

object Main {
  def main(args: Array[String]): Unit = {
    val N: Int = StdIn.readLine().toInt
    val holes: Vector[Vector2D] =
      for (_ <- (1 to N).toVector) yield StdIn.readLine().split(" ").map(_.toDouble).toVector2D

    for (v <- holes) {
      val angles = holes.map(_ - v).filter(_ != Vector2D(0,0)).map(_.angle).sorted
      val max_angle = angles.zip((angles.last - 2*math.Pi) +: angles).map({case (x,y) => x-y}).max
      if (max_angle > math.Pi)
        println("%.20f".format((max_angle - math.Pi) / (2 * math.Pi)))
      else
        println(0.0)
    }
  }
}

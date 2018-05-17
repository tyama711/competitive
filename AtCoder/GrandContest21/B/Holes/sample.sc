case class Vector2D(_x: Double, _y: Double) {
  val x: Double = _x
  val y: Double = _y

  def -(v: Vector2D): Vector2D = Vector2D(x-v.x, y-v.y)

  def angle: Double = {
    val atan = math.atan((y/x))
    math.signum(x) match {
      case 1.0 => atan
      case -1.0 => atan - math.signum(atan) * math.Pi
      case 0.0 => atan
      case _ => Double.NaN
    }
  }
}

Vector2D(-0.1,1.0).angle

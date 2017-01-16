import Data.Char
import Data.List
import Data.Ratio
import Data.Matrix

squares = takeWhile (<= 100) (map (^2) [1..])

getDec :: Ratio Integer -> Int -> [Integer]
getDec r n
  | n <= 0 = []
  | otherwise = let a = numerator r
                    b = denominator r
                in (a `quot` b) : (getDec ((10*(a `rem` b)) % b) (n-1))

solve d m =
  let a = ceiling (sqrt (fromIntegral d)) :: Integer
      alpha = (fromIntegral a) + (sqrt (fromIntegral d)) :: Float
      beta = (fromIntegral a) - (sqrt (fromIntegral d)) :: Float
      b =  (fromIntegral m) + (logBase 10 (2*(sqrt (fromIntegral d)) + 1)) :: Float
      c = ((logBase 10 alpha) - (logBase 10 beta)) :: Float
      n = ceiling (b / c) :: Integer
      mtx = fromList 2 2 [a,d,1,a] :: Matrix Integer
      v = fromList 2 1 [a,1] :: Matrix Integer
      v2 = (mtx^n) * v :: Matrix Integer
  in getDec ((getElem 1 1 v2) % (getElem 2 1 v2)) m
      
main = print $ sum $ concatMap (flip solve 100) $ [1..100] \\ squares

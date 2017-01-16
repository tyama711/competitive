import Data.Ratio
import Data.Matrix
import Data.List

solve = do
  d <- [5..12000]
  n <- filter (\n -> (gcd n d) == 1) [((d+2) `div` 3)..((d-1) `div` 2)]
  return (n, d)

solve' =
  let a = _next 12000 (1%3)
  in _solve' (1%3) a 0
_solve' a b c
  | b == 1%2 = c
  | otherwise = _solve' b (_next' 12000 a b) (c+1)

farey = [1%3, (_next 12000 (1%3))] ++ zipWith (_next' 12000) farey (tail farey)

_next :: Int -> Ratio Int -> Ratio Int
_next n x =
  let a = numerator x
      b = denominator x
      [c0,d0] = solveBezout b a
      c = c0 + ((n+d0) `div` b) * a
      d = -d0 + ((n+d0) `div` b) * b
  in c % d

_next' n x y =
  let a = numerator x
      b = denominator x
      c = numerator y
      d = denominator y
      e = ((n+b) `div` d) * c - a
      f = ((n+b) `div` d) * d - b
  in e % f

solveBezout m n =
  take 2 (toList (_solveBezout m n))

_solveBezout m n
  | n == 0 = fromList 2 2 [1,0,0,1]
  | otherwise =
      let k = m `quot` n
          r = m `rem` n
      in (_solveBezout n r) * (fromList 2 2 [0,1,1,-k])

main = do
  print $ length $ solve

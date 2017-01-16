import Control.Monad

a n = _a n 1 1
  where
    _a n m r
      | r `rem` n == 0 = m
      | otherwise = _a n (m+1) (10*(r `rem` n)+1)

main = do
  print $ head [n | n <- [(10^6)..], gcd n 10 == 1, a n > 10^6]

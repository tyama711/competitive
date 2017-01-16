import Control.Monad

primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

fn n = _a n 1 1
  where
    _a n m r
      | r `rem` n == 0 = m
      | otherwise = _a n (m+1) (10*(r `rem` n)+1)

main = do
  print $ sum $ map fst $ take 25 $ filter (\(a, b) -> (a-1) `rem` b == 0) $
    map (\x -> (x, fn x)) $ filter (\x -> gcd 10 x == 1 && not (isPrime x)) [2..]

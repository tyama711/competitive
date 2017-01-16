import Debug.Trace

primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

powrem a n d
  | n == 1 = a `rem` d
  | n `rem` 2 == 0 = (powrem a (n `div` 2) d)^2 `rem` d
  | otherwise = a * (powrem a (n `div` 2) d)^2 `rem` d

check p = _check (10^10 `rem` (9*p)) []
  where
    _check n xs
      | n == 1 = True
      | elem n xs= False
      | otherwise = _check (powrem n 10 (9*p)) (n : xs)

main = do
  let n = 10000
  print $ sum $ filter (not . check) $ takeWhile (< n) primes

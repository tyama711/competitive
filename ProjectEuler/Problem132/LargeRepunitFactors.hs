import Data.List

primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

check p = (1 ==) $ _check p (10^9)
  where
    _check p n
      | n == 1 = 10 `rem` (9*p)
      | n `rem` 2 == 0 = (a * a) `rem` (9*p)
      | otherwise = (10 * a * a) `rem` (9*p)
      where
        a = _check p (n `div` 2)

main = do
  print $ sum $ take 40 $ filter check $ primes

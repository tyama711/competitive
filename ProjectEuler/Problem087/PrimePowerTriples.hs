import Data.List

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

primes' = takeWhile ((< 5*10^6) . (^2)) primes

solve m = do
  a <- takeWhile (< m) $ map (^4) primes
  b <- takeWhile (< m) $ map ((+ a) . (^3)) primes
  c <- takeWhile (< m) $ map ((+ b) . (^2)) primes
  return c

main = print $ length $ group $ sort $ solve 50000000

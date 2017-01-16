import Control.Monad

primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

main = do
  let m = 1000000
  print $ length $ takeWhile (< 10^6) [p | n <- [1..], let p = 3*n*n+3*n+1, isPrime p]

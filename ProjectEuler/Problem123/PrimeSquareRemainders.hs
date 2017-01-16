
primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

main = let (n,p) = head $ filter (\(n,p) -> 2*n*p > 10^10) $ zip [1..] primes
       in print $ (n `div` 2) * 2 + 1

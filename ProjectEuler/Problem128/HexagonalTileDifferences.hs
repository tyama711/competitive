
primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

solve1 = do
  n <- filter (\n -> isPrime (6*n-1) && isPrime (6*n+1) && isPrime (12*n+5)) [2..]
  return $ 3*n*(n-1) + 2

solve2 = do
  n <- filter (\n -> isPrime (6*n-1) && isPrime (6*n+5) && isPrime (12*n-7)) [2..]
  return $ 3*n*(n+1) + 1

merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
  | x <= y = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys

main = print $ (!! 1999) $ 1:2:(merge solve1 solve2)

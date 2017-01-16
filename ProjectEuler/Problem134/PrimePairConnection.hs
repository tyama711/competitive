import Control.Monad

primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

calc i = _calc (a + primes !! i)
  where
    a = 10^(length (show (primes !! i)))
    _calc n
      | n `rem` (primes !! (i+1)) == 0 = n
      | otherwise = _calc (a+n)

main = do
  forM_ [2..100] $ \i -> do
    let a = calc i
    putStrLn $ show (primes !! i) ++ ", " ++ show (primes !! (i+1)) ++ "*" ++ show (a `div` (primes !! (i+1))) ++ "=" ++ show a

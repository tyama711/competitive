import Data.List
import Control.Monad

primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

factors = factors' primes
  where
    factors' (x:xs) n | x*x > n = [n]
                      | n `mod` x == 0 = x : factors' (x:xs) (n`div`x)
                      | otherwise = factors' xs n

numOfSol :: Int -> Int
numOfSol n
  | even ((n-1) `div` 2) = 0
  | otherwise = foldl' (\s a -> if 3*a*a > n && a*a /= n then s+2 else s+1) 0 $
                filter (\a -> a*a <= n && (a + (n `div` a)) `rem` 4 == 0) $
                map product $ sequence $ map (scanl (*) 1) $ group $ factors n

main = do
  let n = 1000000
  print $ length $ filter (== 10) $ map numOfSol $ [1..(n-1)]

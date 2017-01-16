import Data.Array.IO
import Data.Array
import Data.List

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

compress [] = []
compress (x:[]) = [x]
compress (x:y:xs) | x == y = compress (y:xs)
                  | otherwise = x : compress (y:xs)

radical = product . compress . factors

main = do
  let n = 120000
      rads = listArray (1,n-1) (1:[radical i | i <- [2..n-1]])
      invs = sort $ map (\(a,b) -> (b,a)) $ assocs rads
  print $ sum [c | (rc,c) <- invs, 2 * rc < c,
               (ra, a) <- takeWhile (\x -> fst x * 2 * rc < c) invs,
               a < div c 2, gcd ra rc == 1, ra * rads!(c-a) < div c rc]


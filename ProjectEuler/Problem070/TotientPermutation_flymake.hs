import Data.Ratio
import Data.List
import Data.Function

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

isPermutation a b = sort (show a) == sort (show b)

g (p:ps) = (fromIntegral p) / (fromIntegral (p - 1)) * (g ps)
g [] = 1

candidates m = do
  let ps = reverse (takeWhile (< (floor (sqrt (fromIntegral (10*m))))) primes)
  a <- [[b,c] | b <- ps, c <- takeWhile (> b) ps, b*c < m, isPermutation (b*c) ((b-1) * (c-1))]
  return $ a
  
main = do
  let m = 10^7
  print $ (\a -> (a, product a)) $ minimumBy (compare `on` g) $ take 100 $ candidates m

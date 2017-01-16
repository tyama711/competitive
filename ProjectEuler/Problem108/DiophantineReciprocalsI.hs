import Data.List
import Data.Array.IArray
import Data.STRef
import Control.Monad.ST
import Control.Monad

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

factorize n = _factorize n 0

_factorize n m
  | n < (primes !! m)^2 = [n]
  | n `mod` (primes !! m) == 0 = (primes !! m) : (_factorize (n `div` (primes !! m)) m)
  | otherwise = _factorize n (m+1)

f n = let xs = map length $ group $ factorize n
      in g xs

g xs = (+ 1) $ foldl' (\a b -> a * (2 * b + 1) + b) (head xs) $ tail xs

main = print $ head . filter ((> 1000) . snd) . zip [1..] $ map f [1..]

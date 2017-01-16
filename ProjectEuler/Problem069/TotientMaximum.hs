import Control.Monad
import Data.List
import Data.Ratio
import Data.Function
import Data.Time

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

factorize n = _factorize n 0

_factorize n m
  | n < (primes !! m)^2 = [n]
  | n `mod` (primes !! m) == 0 = (primes !! m) : (_factorize (n `div` (primes !! m)) m)
  | otherwise = _factorize n (m+1)

phi :: Int -> Int
phi n = numerator ((n % 1) * (foldl' (*) 1 (map (\x -> 1 - 1 % x) (map (!! 0) (group (factorize n))))))

main = do
  print $ last $ takeWhile (< 1000000) $ scanl (*) 1 primes

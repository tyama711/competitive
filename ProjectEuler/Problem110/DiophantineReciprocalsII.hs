import Data.List
import Data.Array.IArray
import Data.STRef
import Data.Ord
import Control.Monad.ST
import Control.Monad
import Control.Applicative
import Debug.Trace

primes :: [Integer]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

factorize :: Integer -> [Integer]
factorize n = _factorize n 0

_factorize n m
  | n < (primes !! m)^2 = [n]
  | n `mod` (primes !! m) == 0 = (primes !! m) : (_factorize (n `div` (primes !! m)) m)
  | otherwise = _factorize n (m+1)

f :: Integer -> Integer
f n = let fs = factorize n
      in g fs

g :: [Integer] -> Integer
g fs = let xs = map genericLength $ group fs
       in ((product $ map (\a -> 2*a + 1) xs) + 1) `div` 2

candidates :: Int -> [[Integer]]
candidates n = _candidates 0 n n
_candidates :: Int -> Int -> Int -> [[Integer]]
_candidates i n m
  | n == 0 = return []
  | otherwise = do
      let n' = min n m
      a <- map (\m' -> replicate m' (primes !! i)) [n',(n'-1)..1]
      b <- map (a ++) $ _candidates (i+1) (n - (genericLength a)) (genericLength a)
      return b

main =
  let h m n = minimumBy (comparing fst) . filter ((>= m) . snd)
              . map (\xs -> (product (map toInteger xs), g xs)) $
              candidates n
  in print $ h 4000000 18

import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Char
import Data.List
import Control.Applicative

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

factorize n = _factorize n 0

_factorize n m
  | n < (primes !! m)^2 = [n]
  | n `mod` (primes !! m) == 0 = (primes !! m) : (_factorize (n `div` (primes !! m)) m)
  | otherwise = _factorize n (m+1)

numOfFactors n = length (group (factorize n))

main = do
  n <- readInt <$> B.getLine
  let ls = zip4 [1..n] [2..(n+1)] [3..(n+2)] [4..(n+3)]
  print $ foldl' (\a (b1,b2,b3,b4) ->
                   if a == 0 &&
                      numOfFactors b1 == 4 &&
                      numOfFactors b2 == 4 &&
                      numOfFactors b3 == 4 &&
                      numOfFactors b4 == 4
                   then b1
                   else a ) 0 ls

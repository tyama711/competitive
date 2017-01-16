import Data.Array.IO
import Data.List
import Control.Monad
import Control.Applicative

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

phi is = _phi (group is)
_phi (i:is) = let i' = i !! 0
                  k = length i
              in ((primes !! i')^k - (primes !! i')^(k-1)) * _phi is
_phi [] = 1

main = do
  arr <- newArray (2,10^6) 0 :: IO (IOUArray Int Int)
  let loop n is = do
        writeArray arr n $ phi is
        forM_ (takeWhile (\i -> n * primes !! i <= 10^6) [(last is)..]) $ \i -> loop (n * primes !! i) (is ++ [i])
  forM_ (takeWhile (\i -> primes !! i <= 10^6) [0..]) $ \i -> loop (primes !! i) [i]
  print =<< sum <$> getElems arr

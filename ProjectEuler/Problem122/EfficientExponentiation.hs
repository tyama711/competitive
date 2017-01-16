import Data.List
import Data.Array.IO
import Data.IORef
import Control.Monad
import Control.Applicative

primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

factorize :: Integral a => a -> [a]
factorize n = _factorize n 0

_factorize n m
  | n < (primes !! m)^2 = [n]
  | n `mod` (primes !! m) == 0 = (primes !! m) : (_factorize (n `div` (primes !! m)) m)
  | otherwise = _factorize n (m+1)

m 1 = 0
m k = sum . map (\xs -> _m (head xs) * length xs) . group $ factorize k

_m 2 = 1
_m p = 1 + m (p-1)

main = do
  arr <- newArray (1,200) 0 :: IO (IOUArray Int Int)
  forM_ [2..200] $ \n -> do
    a <- newIORef 999
    unless (isPrime n) $ do
      let ps = factorize n
      d <- sum <$> (forM ps $ \p -> readArray arr p)
      modifyIORef a (const d)
    forM_ [1..(n `div` 2)] $ \m -> do
      b <- readArray arr m
      c <- readArray arr (n - m)
      modifyIORef a (min (b + c + 1))
    writeArray arr n =<< readIORef a

  print =<< getAssocs arr

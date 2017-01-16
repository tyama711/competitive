import Data.Ord
import Data.List
import Data.Array.IO
import Data.IORef
import Control.Monad
import Control.Applicative
import Debug.Trace

primes :: Integral a => [a]
primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

-- factorize :: Integral a => a -> [a]
-- factorize n = _factorize n 0

-- _factorize n m
--   | n < (primes !! m)^2 = [n]
--   | n `mod` (primes !! m) == 0 = (primes !! m) : (_factorize (n `div` (primes !! m)) m)
--   | otherwise = _factorize n (m+1)

-- radical n = product $ map head $ group $ factorize n

-- main = do
--   let n = 100000
--   print $ (!! (n `div` 10 - 1)) $ {-# SCC "sortBy" #-} sortBy (comparing snd) $ zip [1..] $ {-# SCC "map" #-} map radical [1..n]

-- main = do
--   let n = 100000
--   ans <- newIORef []
--   rads <- newArray (1,n) 0 :: IO (IOUArray Int Int)
--   writeArray rads 1 1
--   let loop a b (x:xs) = do
--         writeArray rads a b
--         when (a * x <= n) $ do
--           loop (a * x) b (x:xs)
--         loop2 a b xs
--       loop2 a b (x:xs) = do
--         when (a * x <= n) $ do
--           loop (a * x) (b * x) (x:xs)
--           loop2 a b xs
--       calcRads (x:xs) = do
--         when (x <= n) $ do
--           loop x x (x:xs)
--           calcRads xs
--   calcRads primes
--   print =<< (!! (n `div` 10 - 1)) . sortBy (comparing snd) <$> getAssocs rads

factors = factors' primes
  where
    factors' (x:xs) n | x*x > n = [n]
                      | n `mod` x == 0 = x : factors' (x:xs) (n`div`x)
                      | otherwise = factors' xs n

compress [] = []
compress (x:[]) = [x]
compress (x:y:xs) | x == y = compress (y:xs)
                  | otherwise = x : compress (y:xs)

rad = product . compress . factors

radfax = (1,1) : zip [2..] (map rad [2..])

sorradfax n = sortBy (comparing snd) $ take n radfax

main = do
  print $ (!! 9999) $ sorradfax 100000

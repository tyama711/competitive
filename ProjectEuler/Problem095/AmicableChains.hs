import Control.Monad
import Control.Applicative
import Data.List
import Data.Array.IO
import Data.Ord
import Data.Maybe
import Data.Function

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

factorize n = _factorize n 0

_factorize n m
  | n < (primes !! m)^2 = [n]
  | n `mod` (primes !! m) == 0 = (primes !! m) : (_factorize (n `div` (primes !! m)) m)
  | otherwise = _factorize n (m+1)

f n = let as = group . factorize $ n
      in (subtract n) . foldl' (\a xs -> a * (1 - (xs !! 0)^((length xs) + 1)) `div` (1 - xs !! 0)) 1 $ as

main = do
  arr <- newArray (2,10^6) (-1) :: IO (IOUArray Int Int)
  let loop n xs = do
        a <- readArray arr n
        if a /= -1
          then forM_ xs $ \x -> writeArray arr x 0
          else do
          let b = elemIndex n xs
          if isJust b
            then do forM_ (take ((fromJust b) + 1) xs) $ \x -> writeArray arr x ((fromJust b) + 1)
                    forM_ (drop ((fromJust b) + 1) xs) $ \x -> writeArray arr x 0
            else do
            let c = f n
            if c <= 10^6 && c /= 1
              then loop (f n) (n:xs)
              else forM_ xs $ \x -> writeArray arr x 0
        
  forM_ [2..(10^6)] $ \n -> loop n []
  print =<< fst . (!! 0) . (!! 0) . groupBy ((==) `on` snd) . sortBy (flip (comparing snd)) <$> getAssocs arr

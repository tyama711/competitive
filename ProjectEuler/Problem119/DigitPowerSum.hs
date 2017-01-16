import Data.List
import Data.Char
import Data.STRef
import Control.Monad.ST
import Control.Monad
import Control.Applicative

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

check :: Integer -> Bool
check n =
  let s = sum . map (toInteger . digitToInt) . show $ n
  in if s == 1
     then False
     else (== n) . head . dropWhile (< n) $ iterate (* s) (s*s)

sqrt' n = floor . sqrt . fromIntegral $ n

solve n = runST $ do
  s <- newSTRef []
  forM_ [2 .. (sqrt' n)] $ \a ->
    let a' = toInteger a
        bs = filter check $ takeWhile (<= n) $ iterate (* a') (a' * a')
    in modifySTRef s (bs ++)
  map head . group . sort <$> readSTRef s
    
main = do
  let ans = solve 300000000000000
  print $ ans !! 29

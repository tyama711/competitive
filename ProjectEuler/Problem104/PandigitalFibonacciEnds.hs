import Control.Monad
import Data.List

phi :: Double
phi = (1 + sqrt 5) / 2

fibLast9 :: [Int]
fibLast9 = 0:1:[x | x <- zipWith (\a b -> (a+b) `rem` 10^9) fibLast9 (tail fibLast9)]

fibFirst9 :: Int -> Int
fibFirst9 n = floor $ 10**(a - (fromIntegral b))
  where a = (fromIntegral n) * (logBase 10 phi) - (logBase 10 (sqrt 5))
        b = floor $ a - 8

isPandigital n = "123456789" == (sort (show n))

solve = do
  n <- filter (isPandigital . (fibLast9 !!)) . filter (isPandigital . fibFirst9) $ [1..]
  return n

main = print $ head $ solve

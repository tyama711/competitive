import Data.List

sqrt' n = floor $ sqrt $ fromIntegral n

isPalindrome n = show n == reverse (show n)

solve n = do
  a <- [1..(sqrt' (n `div` 2))]
  b <- filter isPalindrome $ takeWhile (< n) $ scanl (\a b -> a + b*b) (a^2 + (a+1)^2) [(a+2)..]
  return b

main = print $ sum $ nub $ solve $ 10^8

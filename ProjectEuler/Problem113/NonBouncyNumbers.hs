import Data.List

facts :: [Integer]
facts = 1:(zipWith (*) facts [1..])

fact n = foldl' (*) 1 [1..n]

comb :: Int -> Int -> Integer
comb n m = (facts !! n) `div` (facts !! m) `div` (facts !! (n-m))

inc :: Int -> Integer
inc n = subtract 1 . comb (n+9) $ 9

dec :: Int -> Integer
dec n = (comb (n+10) 10) - (toInteger n) - 1

nonBouncy :: Int -> Integer
nonBouncy n = (inc n) + (dec n) - 9*(toInteger n)

main = do
  print $ nonBouncy 100

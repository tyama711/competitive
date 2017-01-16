import Data.List
import Data.Time
import Control.Monad

polygonals :: Int -> [Int]
polygonals n = dropWhile (< 1000) (takeWhile (< 10000) (map (\m -> m*((n-2)*m - (n-4)) `div` 2) [1..]))

f :: [Int] -> Int -> [(Int,Int)]
f (x:xs) n = (zip [x,x..] (filter (\m -> m `div` 100 == n) (polygonals x))) ++ (f xs n)
f [] n = []

solve = do
  a <- polygonals 8
  (b,b') <- f [3..7] $ a `mod` 100
  (c,c') <- f ([3..7] \\ [b]) $ b' `mod` 100
  (d,d') <- f ([3..7] \\ [b,c]) $ c' `mod` 100
  (e,e') <- f ([3..7] \\ [b,c,d]) $ d' `mod` 100
  (f,f') <- filter (\(x,y) -> y `mod` 100 == a `div` 100)
            (f ([3..7] \\ [b,c,d,e]) $ e' `mod` 100)
  return [a,b',c',d',e',f']

main = do
  s <- getCurrentTime
  print $ sum $ head solve
  e <- getCurrentTime
  print $ diffUTCTime e s

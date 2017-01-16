import Data.List
import Data.Time

isPermutation n m = sort (show n) == sort (show m)

cubics = dropWhile (< 10^11) (takeWhile (< 10^12) (map (^3) [1..]))

solve = do
  a <- cubics
  b <- filter (> 4) [length (filter (isPermutation a) cubics)]
  return a

main = do
  s <- getCurrentTime
  print $ head solve
  e <- getCurrentTime
  print $ diffUTCTime e s

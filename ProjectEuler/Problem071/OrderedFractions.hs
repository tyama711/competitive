import Data.Ratio
import Data.List
import Data.Function

candidates = do
  d <- [10^6,10^6-1..]
  let n = 3*d `div` 7
  c <- filter (\n -> (gcd n d) == 1) [n]
  return $ n%d

main = do
  print $ minimumBy (compare `on` (`subtract` (3%7))) $ take 100 $ candidates

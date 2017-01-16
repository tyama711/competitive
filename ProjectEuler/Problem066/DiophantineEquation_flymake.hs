import Data.List
import Data.Function

f d n
  | n `mod` d /= 0 = []
  | otherwise = let n' = n `div` d
                    n'' = floor (sqrt (fromIntegral (n'+1)))
                in if n' == n''^2
                   then [n'']
                   else []

solve :: Integer -> [(Integer, Integer)]
solve d = do
  x <- [2..]
  y <- f d (x^2 - 1)
  return (x,y)

squares = takeWhile (< 1000) (map (^2) [1..])

main = print $ {-maximumBy (compare `on` (fst . snd)) $-} map (\d -> (d, head (solve d))) $ [900..1000] \\ squares
  --print $ head $ solve 94

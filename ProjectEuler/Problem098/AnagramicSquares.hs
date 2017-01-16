import Control.Applicative
import Data.List
import Data.Ord
import Data.Function

squares = map (\x -> (x, (read :: [Char] -> Int) . sort . show $ x)) . map (^2) $ [(3*10^5)..(10^6)]

l2i (x:xs)
  | xs == [] = x
  | otherwise = 10 * x + l2i xs

main = do
  print $ map (map fst) $ filter ((> 1) . length) $ groupBy ((==) `on` snd) $ sortBy (comparing snd) $ squares

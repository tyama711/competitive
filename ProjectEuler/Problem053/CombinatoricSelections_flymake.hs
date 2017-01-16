import Data.Tuple

logs = map (\a -> log a / log 10) [1..100]
s = scanl (\a b -> a+b) 0 logs

check n r = s !! n - s !! r - s !! (n-r) > 6

main = do
  print $ length $ filter (uncurry check) $ concatMap (\a -> map (\b -> (a,b)) [4..(a-4)]) [8..100]
  

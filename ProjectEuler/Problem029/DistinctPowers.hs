import Data.List

solve = length (nub (concatMap (\a -> map (^a) [2..100]) [2..100]))

main = print $ solve

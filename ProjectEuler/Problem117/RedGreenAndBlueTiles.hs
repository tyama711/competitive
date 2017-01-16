import Data.List

tiles = 1:1:2:4:(zipWith4 (\a b c d -> a + b + c + d)
                 tiles (tail tiles) (drop 2 tiles) (drop 3 tiles))

main = print $ tiles !! 50

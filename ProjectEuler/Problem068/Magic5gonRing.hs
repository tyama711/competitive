import Data.List
import Data.Char
import Data.Maybe

isMagic xs = xs !! 0 + xs !! 5 + xs !! 6 == xs !! 1 + xs !! 6 + xs !! 7 &&
             xs !! 0 + xs !! 5 + xs !! 6 == xs !! 2 + xs !! 7 + xs !! 8 &&
             xs !! 0 + xs !! 5 + xs !! 6 == xs !! 3 + xs !! 8 + xs !! 9 &&
             xs !! 0 + xs !! 5 + xs !! 6 == xs !! 4 + xs !! 9 + xs !! 5

isPointSymmetry a b = let syms = take 5 (iterate (\a -> drop ((length a) - 5) a ++ take 5 a) a)
                      in elem b syms

solve = do
  xs <- sortBy (flip compare) $ permutations [6..10]
  ys <- sortBy (flip compare) $ permutations [1..5]
  zs <- filter isMagic [xs ++ ys]
  let a = [zs !! 4, zs !! 9, zs !! 5, zs !! 0, zs !! 5, zs !! 6, zs !! 1, zs !! 6, zs !! 7, zs !! 2, zs !! 7, zs !! 8, zs !! 3, zs !! 8, zs !! 9]
  return $ (read (concatMap show a) :: Int)

main = do
  print $ maximum $ filter (< 7000000000000000) $ solve

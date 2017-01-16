xs = (replicate 3 1) ++ [2] ++ (zipWith (\x y -> x + y + 1) (drop 3 xs) ys)
ys = 1:(zipWith (+) (tail xs) ys)

main = print $ xs !! 50

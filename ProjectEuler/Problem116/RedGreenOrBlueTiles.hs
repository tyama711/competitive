rs = (replicate 2 1) ++ (zipWith (+) rs (tail rs))
gs = (replicate 3 1) ++ (zipWith (+) gs (drop 2 gs))
bs = (replicate 4 1) ++ (zipWith (+) bs (drop 3 bs))

main = print $ rs !! 50 + gs !! 50 + bs !! 50 - 3

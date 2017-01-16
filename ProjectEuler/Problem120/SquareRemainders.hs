f a = 2 * a * ((a - 1) `div` 2)

main = print $ sum $ map f [3..1000]

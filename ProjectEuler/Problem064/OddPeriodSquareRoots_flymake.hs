isSquare n = let n' = floor (sqrt (fromIntegral n))
             in n == n'^2

f :: (Int,Int,Int) -> (Int,(Int,Int,Int))
f (n,m,d) = let a = floor ((sqrt (fromIntegral n) + m) / d)
            in (a,(n,m - a*d,d))

main = do
  print $ isSquare 4

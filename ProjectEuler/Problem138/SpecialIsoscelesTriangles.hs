sqrt' = round . sqrt . fromIntegral

ans1 = [p^2 + q^2 | q <- [1..]
        , let a = sqrt' (5*q*q - 1)
        , a*a == 5*q*q - 1
        , let p = 2*q + a]

ans2 = [p^2 + q^2 | q <- [1..]
        , let a = sqrt' (5*q*q + 1)
        , a*a == 5*q*q + 1
        , let p = 2*q + a]

compress xs [] = xs
compress [] ys = ys
compress (x:xs) (y:ys)
  | x <= y = x : (compress xs (y:ys))
  | otherwise = y : (compress (x:xs) ys)

main = do
  print $ sum $ take 12 $ compress ans1 ans2

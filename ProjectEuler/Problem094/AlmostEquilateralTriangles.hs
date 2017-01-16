import Data.List

sqrt' n = floor . sqrt . fromIntegral $ n

triplets m = [sort [d*a, d*b, d*c] |
              let m' = sqrt' m
              , p <- [2..m'], q <- [1..(p-1)]
              , let a' = 2*p*q
                    b' = p^2-q^2
                    a = min a' b'
                    b = max a' b'
                    c = p^2+q^2
              , d <- [1..(m `div` c)]
              , gcd p q == 1, odd (p+q)
              , odd (d*c)
              , d*a == d*c `div` 2 || d*a == d*c `div` 2 + 1]

main = do
  let n = 10^9
  print $ (*3) $ sum $ map (!! 2) $ triplets (n `div` 3)

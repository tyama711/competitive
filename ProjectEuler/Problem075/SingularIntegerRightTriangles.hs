import Data.List

main = do
  let l = 1500000
  print $ length $ filter (\xs -> length xs == 1) $ group $
    sort $ map sum $ [[a*2*p*q, a*(p^2-q^2), a*(p^2+q^2)] |
           p <- [2..((floor (sqrt (fromIntegral (l `div` 2)))) :: Int)],
           q <- [1..(min (p-1) ((l `div` (2*p)) - p))],
           a <- [1..(l `div` (2*p*(p+q)))],
           2*a*p*(p+q) <= l,
           gcd p q == 1,
           odd (p + q)]

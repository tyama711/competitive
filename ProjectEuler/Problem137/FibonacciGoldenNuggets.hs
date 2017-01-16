import Data.List

triplets :: [Int]
triplets = [p^2-q^2-1 | p <- [2..]
            , let d = sqrt' (5*p*p - 4)
            , d*d == 5*p*p - 4
            , even (-1*p + d)
            , let q = (-1*p + d) `div` 2
            , gcd p q == 1]

sqrt' = round . sqrt . fromIntegral

main = do
  print $ take 15 triplets

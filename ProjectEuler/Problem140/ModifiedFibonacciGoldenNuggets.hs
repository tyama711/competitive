import Data.Ratio

sqrt' = round . sqrt . fromIntegral

isSquare n = n == n'*n'
  where
    n' = sqrt' n

nuggets = [n | n <- [1..], isSquare (5*n*n + 14*n + 1)]

fibs = 1:1:(zipWith (+) fibs (tail fibs))

n k = (sum $ map ((fibs !!) . (\k -> 2*k-1)) $ [1..k])
      + (fibs !! (2*((k+1)`div`2)-1))^2

main = do
  print $ sum $ take 30 $ map n [1..]

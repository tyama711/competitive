import Control.Monad

check n = let b = ceiling ((fromIntegral n) / (sqrt 2))
          in 2*b*(b-1) == n*(n-1)

solve n = do
  n' <- filter check . filter (\m -> m `rem` 4 == 0 || m `rem` 4 == 1) $ [n..]
  return $ ceiling $ (fromIntegral n') / (sqrt 2)
  
main = print $ head $ solve n
  where n = 10000000

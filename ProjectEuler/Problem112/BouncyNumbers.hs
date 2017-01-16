isBouncy n = let n' = show n
             in or (zipWith (>) n' (tail n')) && or (zipWith (<) n' (tail n'))

solve a b
  | (fromIntegral b) / (fromIntegral a) == 0.99 = a
  | otherwise = if isBouncy (a+1)
                then solve (a+1) (b+1)
                else solve (a+1) b

main = do
  print $ solve 1 0

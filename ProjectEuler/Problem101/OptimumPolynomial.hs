g m i x = product . map (x -) $ [1..(i-1)] ++ [(i+1)..m]

op xs k n = sum . take k . map (\i -> xs !! (i-1) * (g k i n) `div` (g k i i)) $ [1..k]

u n = (1 + n^11) `div` (1 + n)

main = do
  let xs = take 10 . map u $ [1..]
  print $ sum $ map (\k -> op xs k (k+1)) $ [1..10]

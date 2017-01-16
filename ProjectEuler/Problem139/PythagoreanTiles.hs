as1 = [2*(2*a+1)*(a+1) | a <- [1..100], (2*a*a + 2*a + 1) `rem` (2*a*a - 1) == 0]
as2 = [2*(a+1)*(a+2) | a <- [1..100], (a*a + 2*a + 2) `rem` (a*a - 2) == 0]

main = do
  let n = 10^8
      bs1 = map (\a -> if a > 2 then a-1 else 1) $ map (\a -> n `div` a) as1
  print as1
  print as2
  print $ (sum bs1) + (length as2)

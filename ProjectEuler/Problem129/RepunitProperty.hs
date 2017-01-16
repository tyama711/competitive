-- cycleLength n = _cycleLength n 1 []
-- _cycleLength n m xs
--   | isJust (elemIndex m xs) = length xs - fromJust (elemIndex m xs)
--   | otherwise = _cycleLength n ((10*m) `mod` n) (xs ++ [m])

cycleLength n = _cycleLength n (10 `rem` n) 1
_cycleLength n r k
  | r <= 1 = k
  | otherwise = _cycleLength n ((10*r) `rem` n) (k+1)

main = do
  print $ cycleLength 7

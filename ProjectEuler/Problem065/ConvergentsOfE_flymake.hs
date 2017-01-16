import Data.Ratio

(%%) a b = let c = ((numerator a) * (denominator b))
               d = ((denominator a) * (numerator b))
               e = gcd c d
           in (c `div` e) % (d `div` e)

--f n = 2 + _f n

f n s
  | n == 1 = 2 + s
  | n `mod` 3 == 1 = f (n-1) (1 %% ((2^(n `div` 3)) + s))
  | otherwise = f (n-1) (1 %% (1 + s))

main = print $ f 1 0

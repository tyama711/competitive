import Data.Ratio
import Data.Char

(%%) a b = let c = ((numerator a) * (denominator b))
               d = ((denominator a) * (numerator b))
               e = gcd c d
           in (c `div` e) % (d `div` e)

f :: Integer -> Ratio Integer -> Ratio Integer
f n s
  | n == 1 = 2 + s
  | n `mod` 3 == 0 = f (n-1) (1 %% (((2*(n `div` 3)) % 1) + s))
  | otherwise = f (n-1) (1 %% (1 + s))

main = print $ sum $ map digitToInt $ show (numerator (f 100 0))
  --putStrLn $ show (numerator (f 100 0)) ++ "/" ++ show (denominator (f 100 0))

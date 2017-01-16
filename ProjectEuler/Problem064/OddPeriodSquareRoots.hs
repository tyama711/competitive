import Control.Monad
import Data.Ratio
import Data.Maybe
import Data.List

(%%) a b = let c = (numerator a) * (denominator b)
               d = (denominator a) * (numerator b)
               e = gcd c d
           in (c `div` e) % (d `div` e)

data BiSurd = BiSurd Rational Rational Rational

instance Eq BiSurd where
  (BiSurd n a b) == (BiSurd n' a' b') = n == n' && a == a' && b == b'

integralPart :: BiSurd -> Integer
                            --   _
integralPart (BiSurd n a b) -- a/n + b
  = floor ((fromRational a) * (sqrt (fromRational n)) + (fromRational b))

decimalPart :: BiSurd -> BiSurd
decimalPart (BiSurd n a b)
  = BiSurd n a (b - (integralPart (BiSurd n a b)) % 1)

reciprocal :: BiSurd -> BiSurd
reciprocal (BiSurd n a b)
  = let c = a^2 * n - b^2
    in BiSurd n (a %% c) (-b %% c)

solve :: BiSurd -> [BiSurd]-> (Int, [Integer])
solve a xs
  | isJust (elemIndex a xs) = (length xs - fromJust (elemIndex a xs), map integralPart xs)
  | otherwise = solve (reciprocal (decimalPart a)) (xs ++ [a])

squares = takeWhile (<= 10000) (map (^2) [1..])

main = do
  print $ length $ filter (odd . fst) $ map (\x -> solve (BiSurd x 1 0) []) ([2..10000] \\ squares)

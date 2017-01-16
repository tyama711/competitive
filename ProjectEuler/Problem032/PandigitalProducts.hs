import Data.List

isPandigital a b = sort (show a ++ show b ++ show (a*b)) == "123456789"

main = do
  print $ sum $ nub [a*b | a <- [2..99], b <- [100..4999], isPandigital a b]

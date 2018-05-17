import Control.Applicative
import Data.Maybe

l2p (a:b:_) = (a,b)

convert [] = []
convert (s:str)
  | s == '+' = 1 : (convert str)
  | otherwise = (-1) : (convert str)

main = do
  (n,l) <- l2p . map (read :: [Char] -> Int) . take 2 . words <$> getLine
  s <- convert <$> getLine
  print $ (`div` l) $ sum s

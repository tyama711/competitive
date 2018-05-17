import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

isPrime :: Int -> Int -> Bool
isPrime n m
  | n == 1 = False
  | n == m = True
  | n `mod` m == 0 = False
  | otherwise = isPrime n (m+1)

main = do
  n <- readInt <$> B.getLine
  putStrLn $ if (isPrime (n * (n+1) `div` 2) 2)
          then "WANWAN"
          else "BOWWOW"

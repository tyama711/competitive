import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as B

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

solve (x:xs)
  | xs == [] = max (80-x) 0
  | otherwise = (max (80 - x) 0) + (solve xs)

main = do
  _ <- readInt <$> B.getLine
  m <- readInts
  print $ solve m

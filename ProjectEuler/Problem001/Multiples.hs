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

solve n m
  | n >= m = 0
  | n `mod` 5 == 0 || n `mod` 3 == 0 = n + solve (n+1) m
  | otherwise = solve (n+1) m

main = do
  print $ solve 1 1000

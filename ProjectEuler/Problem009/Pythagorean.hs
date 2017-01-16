import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Char

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

main = do
  print $ product $ head $ [[q*q - p*p, 2*p*q, p*p + q*q] | p <- [1..500], q <- [1..500], p < q, 2*q*(q + p) == 1000]

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
  series <- filter isDigit <$> getContents
  let loop i max
        | i + 13 >= length series = max
        | otherwise = let pp = product (map digitToInt (take 13 (drop i series)))
                          in if pp > max
                             then loop (i+1) pp
                             else loop (i+1) max
  print $ loop 0 0

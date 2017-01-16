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
  let p = product (map digitToInt (take 4 series))
      loop i p max
        | i + 4 >= length series = max
        | otherwise = let pp = p `div` (digitToInt (series !! (i-1))) * (digitToInt (series !! (i+4)))
                          in if pp > max
                             then loop (i+1) pp pp
                             else loop (i+1) pp max
  print $ loop 1 p 0

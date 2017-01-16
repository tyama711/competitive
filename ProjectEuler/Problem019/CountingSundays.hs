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

daysFrom19000101 y m d =
  let month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
      days = (y - 1900) * 365 + sum (take (m - 1) month) + d
      y' = if m > 2 then y+1 else y
  in days + (y' - 1900 + 3) `div`4 - (y' - 1900 + 99) `div` 100 + (y' - 1900 + 299) `div` 400

main = do
  let xs = [ (daysFrom19000101 y m 1) `mod` 7 | y <- [1901..2000], m <- [1..12] ]
  print $ length $ filter (== 6) xs

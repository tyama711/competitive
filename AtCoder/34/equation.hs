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

f 0 = 0
f n = (mod n 10) + f (div n 10)

main = do
  n <- readInt <$> B.getLine
  let offset = max 0 (n-180)
      fs = map f [offset..n]
      ls = zipWith (+) fs [offset..n]
      ans = [x + offset | x <- [0..(n-offset)], ls!!x == n]
  print $ length ans
  mapM_ print ans

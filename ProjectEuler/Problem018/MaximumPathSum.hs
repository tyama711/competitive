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

solve [] = 0
solve (x:xs) = x !! 0 + max (solve (map tail xs)) (solve (map init xs))

main = do
  xs <- replicateM 15 $ readInts
  print $ solve xs

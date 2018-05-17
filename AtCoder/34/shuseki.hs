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

main = do
  n <-  readInt <$> B.getLine
  l <- replicateM n readInts
  let lr = map (map fromIntegral) l
      ps = map (\[p1,p2,p3,p4,p5] -> p1+p2+p3+p4+p5*11/90) lr
  print $ maximum ps

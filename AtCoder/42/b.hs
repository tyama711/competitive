import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Set

readInt = fromJust . fmap fst . B.readInt
readInts = Data.List.map readInt . B.words <$> B.getLine
readIntPair = l2p . Data.List.map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

calc [x1,y1] [x2,y2]
  = sqrt (fromIntegral (fromIntegral x2^2 + y2^2) - (fromIntegral (x1*x2 + y1*y2)^2)/(fromIntegral (x1^2 + y1^2)))

main = do
  (x, y) <- readIntPair
  n <- readInt <$> B.getLine
  (p:ps) <- replicateM n readInts
  print $ minimum (zipWith calc (zipWith (zipWith (-)) (p:ps) (ps++[p])) (zipWith (zipWith (-)) (replicate n [x,y]) (ps++[p])))

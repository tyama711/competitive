import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.STRef
import Data.Array.ST
import Data.Array.IO
import Debug.Trace
import Data.Function

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

cycleLength n = _cycleLength n 1 []
_cycleLength n m xs
  | isJust (elemIndex m xs) = length xs - fromJust (elemIndex m xs)
  | otherwise = _cycleLength n ((10*m) `mod` n) (xs ++ [m])

main = do
  print $ maximumBy (compare `on` snd) $ zip [1..1000] $ map cycleLength [1..1000]

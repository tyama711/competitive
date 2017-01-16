import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Ord

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

countRects :: (Int,Int) -> Int
countRects (a,b) = a * (a+1) * b * (b+1) `div` 4

main = do
  print $ minimumBy (comparing snd) $
    map (\(a,b) -> (a*b, abs (2*10^6 - (countRects (a,b)))))
    [(a,b) | a <- [10..100], b <- [10..100]]

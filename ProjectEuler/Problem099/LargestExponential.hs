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

main = do
  inputs <- map (map readInt . B.split ',') . B.words <$> B.getContents
  let logs = map (\xs -> (fromIntegral (xs !! 1)) * (log (fromIntegral (xs !! 0)))) inputs
  print $ maximumBy (comparing snd) $ zipWith (\a b -> (a,b)) [1..] logs

import Control.Applicative
import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as B
import GHC.Exts
--import Debug.Trace

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

solve p xs w m
  | xs == [] || w > p = m
  | otherwise = maximum $ zipWith3 (solve p) (map (flip drop xs) [1..(length xs)]) (map ((+ w).fst) xs) (map ((+ m).snd) xs) 

main = do
  (n,p) <- readIntPair
  xs <- reverse <$> (sortWith fst) <$> replicateM n readIntPair
  print $ solve p xs 0 0

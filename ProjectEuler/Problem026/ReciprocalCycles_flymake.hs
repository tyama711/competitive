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

factorize n = _factorize n 2

_factorize n m
  | n <= m = [n]
  | n `mod` m == 0 = m : (_factorize (n `div` m) m)
  | otherwise = _factorize n (m+1)

cycleLength n =
  let xs = filter (\x -> x /= 2 && x /= 5) (factorize n)
      loop i
        | xs \\ (factorize (10^i - 1)) == [] = i
        | otherwise = loop (i+1)
  in trace (show xs) $ if xs == [] then 0 else loop 1

main = do
  n <- readInt <$> B.getLine
  print $ cycleLength n
  -- print $ zip [2..n] $ map cycleLength [2..n]
  -- print $ fst $ maximumBy (compare `on` snd) $ zip [2..n] $ map cycleLength [2..n]

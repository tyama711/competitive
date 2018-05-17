import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Debug.Trace

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

readInteger = fromJust . fmap fst . B.readInteger
readIntegers = map readInteger . B.words <$> B.getLine
readIntegerPair = l2p . map readInteger . take 2 . B.words <$> B.getLine

pow a b m
  | a == 0 = 0
  | b == 0 = 1
  | b == 1 = mod a m
  | mod b 2 == 0 = (mod (pow (mod (a*a) m) (div b 2) m) m)
  | otherwise = (mod (a * (pow (mod (a*a) m) (div b 2) m)) m)

main = do
  n <- readInt <$> B.getLine
  a <- readInts
  let c = (group . sort) a
      b = map length c
  if a!!0 /= 0 || b!!0 /= 1 || (length c) - 1 /= (c!!((length c)-1))!!0
    then print 0
    else let loop xs s = case xs of
               (y1:y2:ys) -> loop (y2:ys)
                               (mod ((s*(pow ((pow 2 y1 (10^9+7))-1) y2 (10^9+7)))*(pow 2 (y2*(y2-1) `div` 2) (10^9+7))) (10^9+7))
               _ -> s
         in print $ loop b 1

import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Array.IO

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

-- primesBelow :: Int -> IO [Int]
primesBelow n = do
  arr <- newArray (0, n) True :: IO (IOUArray Int Bool)
  writeArray arr 0 False
  writeArray arr 1 False
  _primesBelow n 2 arr
  elemIndices True <$> getElems arr

_primesBelow n a arr
  | n < a*a = return ()
  | otherwise = do
      c <- readArray arr a
      if c then do
                forM_ (map (* a) [2..(n `div` a)])
                  $ \x -> writeArray arr x False
                _primesBelow n (a+1) arr
        else _primesBelow n (a+1) arr

main = do
  print =<< sum <$> primesBelow 2000000

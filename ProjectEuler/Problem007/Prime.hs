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

prime :: Int -> IO Int
prime n = do
  arr <- newArray (2, 1000000) True :: IO (IOUArray Int Bool)
  _prime n 2 0 arr

_prime n a b arr
  | n == b = return (a-1)
  | otherwise = do
      c <- readArray arr a
      if c then do
                forM_ (map (* a) [2..(1000000 `div` a)])
                  $ \x -> writeArray arr x False
                _prime n (a+1) (b+1) arr
        else _prime n (a+1) b arr

main = do
  n <- readInt <$> B.getLine
  print =<< prime n

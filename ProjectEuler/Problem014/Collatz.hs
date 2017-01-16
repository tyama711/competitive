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

collatzChainLen n arr
  | n == 1 = return 1
  | n > 1000000 = (+ 1) <$> if n `mod` 2 == 0
                  then collatzChainLen (n `div` 2) arr
                  else collatzChainLen (3*n + 1) arr
  | otherwise = do
                a <- readArray arr n
                if a /= 0
                  then return a
                  else do
                       b <- (+ 1) <$> if n `mod` 2 == 0
                            then collatzChainLen (n `div` 2) arr
                            else collatzChainLen (3*n + 1) arr
                       writeArray arr n b
                       return b

main = do
  arr <- newArray (1,1000000) 0 :: IO (IOUArray Int Int)
  writeArray arr 1 1
  a <- forM [1..1000000] (`collatzChainLen` arr)
  let mx = maximum a
      ans = 1 + fromJust (elemIndex mx a)
  print ans

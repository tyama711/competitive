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

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

sumOfDivisors n =
  let loop i
        | i >= n = 0
        | otherwise = if n `mod` i == 0
                      then i + loop (i + 1)
                      else loop (i + 1)
  in loop 1

isAbundant n = sumOfDivisors n > n

main = do
  n <- readInt <$> B.getLine
  arr <- newArray (1, n) True :: IO (IOUArray Int Bool)
  let abundants = filter isAbundant [1..n]
      loop1 i
        | i >= length abundants = return ()
        | otherwise = do
            let loop2 j
                  | j >= length abundants || abundants !! i + abundants !! j > n = return ()
                  | otherwise = do
                      writeArray arr (abundants !! i + abundants !! j) False
                      loop2 (j+1)
            loop2 i
            loop1 (i+1)
  loop1 0

  ans <- sum . map (+ 1) . findIndices (== True) <$> getElems arr
  print ans

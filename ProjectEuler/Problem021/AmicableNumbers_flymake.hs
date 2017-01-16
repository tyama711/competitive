import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.STRef
import Data.Array.ST
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

amicable n = runST $ do
  ans <- newSTRef []
  arr <- newArray (2,n) 0 :: ST s (STUArray s Int Int)
  forM_ [2..n] $ \i -> writeArray arr i (sumOfDivisors i)
  forM_ [2..n] $ \i -> do
    a <- readArray arr i
    if i == a || a == 1
    then return ()
    else if a > n
         then do
           let b = sumOfDivisors a
           if i == b
             then modifySTRef ans ((i, a) :)
             else return ()
         else do
           b <- readArray arr a
           if i == b
             then modifySTRef ans ((i, a) :)
             else return ()
  readSTRef ans

main = do
  n <- readInt <$> B.getLine
  print $ sum $ nub $ sort $ concatMap p2l $ amicable n

import Data.Char
import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.List
import Data.Array.IO
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

fact n
  | n == 0 = 1
  | otherwise = n * fact (n-1)

next n = sum (map (fact . digitToInt) (show n)) :: Int

-- count n = _count n [n]
-- _count n ns =
--   let n' = next n
--   in if elem n' ns
--      then length ns
--      else _count n' (n':ns)

main = do
  let m = 10^6
  --m <- readInt <$> B.getLine
  arr <- newArray (1,m) 0 :: IO (IOUArray Int Int)
  writeArray arr 169 3
  writeArray arr 363601 3
  writeArray arr 1454 3
  writeArray arr 871 2
  writeArray arr 872 2
  let count n = do
        let n' = next n
        --putStrLn $ show n ++ "," ++ show n'
        if n > m
           then if n' == n
                then return 1
                else (+ 1) <$> count n'
          else if n' == n
               then do
                 writeArray arr n 1
                 return 1
               else do
                 a <- readArray arr n
                 if a /= 0
                   then return a
                   else do
                   b <- (+ 1) <$> count n'
                   writeArray arr n b
                   return b

  print =<< length . filter (== 60) <$> (forM [1..m] $ \i -> count i)

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

subTriangle :: [[Int]] -> Int -> Int -> [[Int]]
subTriangle xs a b = map (drop b) (drop a xs)

main = do
  xs <- snd . flip (mapAccumL (\a b -> (drop b a, take b a))) [1..100] . map readInt . B.words <$> B.getContents
  arr <- newArray ((0,0),(99,99)) 0 :: IO (IOUArray (Int, Int) Int)
  let
    solve :: [[Int]] -> Int -> Int -> IO Int
    solve xs a b
        | a == 99 = return $ head (head xs)
        | otherwise = do
            c <- readArray arr (a,b)
            if c == 0
              then do
                d <- max <$> solve (subTriangle xs 1 0) (a+1) b <*> solve (subTriangle xs 1 1) (a+1) (b+1)
                writeArray arr (a,b) (d + head (head xs))
                return (d + head (head xs))
              else return c
  print =<< solve xs 0 0

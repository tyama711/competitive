import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Array.IO
import Data.IORef

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

f [] = 0
f (x:xs)
  | length (x:xs) < 4 = 0
  | otherwise = max (product (take 4 (x:xs))) (f xs)

split xs n
  | xs == [] = []
  | otherwise = (take n xs) : (split (drop n xs) n)

-- modifyIORef r f = do
--   a <- readIORef r
--   writeIORef r (f a)

blackDiag arr = do
  xs <- newIORef []
  forM_ [0..38] $ \i -> do
    let loop j
          | j > i || j > 19 = return []
          | otherwise = do
              a <- readArray arr (j, (i-j))
              (:) a <$> loop (j+1)
    diag <- loop (max 0 (i-19))
    modifyIORef xs ((:) diag)
  readIORef xs

whiteDiag arr = do
  xs <- concat . reverse . (`split` 20) <$> getElems arr
  arr2 <- newListArray ((0,0),(19,19)) xs :: IO (IOUArray (Int, Int) Int)
  blackDiag arr2

solve arr = do
  a <- (`split` 20) <$> getElems arr
  bd <- blackDiag arr
  wd <- whiteDiag arr
  let b = transpose a
      max1 = max (maximum (map f a)) (maximum (map f b))
      max2 = max max1 (maximum (map f bd))
      max3 = max max2 (maximum (map f wd))
  return max3

main = do
  xs <- map readInt . B.words <$> B.getContents
  arr <- newListArray ((0,0),(19,19)) xs :: IO (IOUArray (Int, Int) Int)
  ans <- solve arr
  print ans

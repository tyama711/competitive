import qualified Data.ByteString.Char8 as B
import Control.Applicative
import Data.Maybe
import Control.Monad
import Data.List
import Data.Array.IO
import Data.IORef

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
ps2l ((a,b):as) = a:b:(ps2l as)
ps2l _ = []
l2ps (a:b:as) = (a,b):(l2ps as)
l2ps _ = []

modifyArray a i f = do
  val <- readArray a i
  writeArray a i (f val)

counter = do
  v <- newIORef 0
  return $ \f -> do
    v' <- f <$> readIORef v
    writeIORef v v'
    return v

groupByN _ [] = []
groupByN n xs = (take n xs) : (groupByN n (drop n xs))

main = do
  (m,n) <- readIntPair
  arr <- newArray ((0,0),(m-1,n-1)) 0 :: IO (IOUArray (Int, Int) Int)
  arr2 <- newArray ((0,0),(m-1,n-1)) 0 :: IO (IOUArray (Int, Int) Int)

  forM_ [0..(m-1)] $ \i -> do
    as <- readInts
    forM_ [0..(n-1)] $ \j -> writeArray arr (i,j) (as !! j)
  forM_ [0..(m-1)] $ \i -> do
    as <- readInts
    forM_ [0..(n-1)] $ \j -> modifyArray arr (i,j) (subtract (as !! j))

  as <- getElems arr
  let bs = zipWith (*) as (tail as)
      cs = concat $ transpose $ groupByN m as
      ds = zipWith (*) cs (tail cs)
  forM_ [0..(m*n - 2)] $ \i -> do
    if i `mod` n /= n - 1 && bs !! i == -1
      then do
           modifyArray arr2 (i `div` n, i `mod` n) (+ 1)
           modifyArray arr2 (i `div` n, i `mod` n + 1) (+ 1)
      else return ()
  forM_ [0..(m*n - 2)] $ \i -> do
    if i `mod` m /= m - 1 && ds !! i == -1
      then do
           modifyArray arr2 (i `mod` m, i `div` m) (+ 1)
           modifyArray arr2 (i `mod` m + 1, i `div` m) (+ 1)
      else return ()
  print =<< groupByN m <$> getElems arr2

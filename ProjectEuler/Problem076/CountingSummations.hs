import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Time
import Data.Array.IO
import System.IO

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

solve 1 m = 1
solve n 1 = 1
solve n m = let a = if n <= m then 1 else 0
            in sum (map (\a -> solve (n-a) a) [1..(min m (n-1))]) + a

indices = concat (map p2l (zip [1..] [-1,-2..]))
coefs = map (\i -> (-1)^(i `div` 2)) [0..]

pentagonal :: Int -> Int
pentagonal k = k * (3*k - 1) `div` 2

pentagonals = map pentagonal indices

solve'' 0 m = 1
solve'' n 1 = 1
solve'' n m
  | n < m = solve'' n n
  | otherwise = solve'' n (m-1) + solve'' (n-m) m

modifyArray a i f = do
  b <- readArray a i
  writeArray a i (f b)

main = do
  n <- readInt <$> B.getLine
  arr <- newArray (0,n) 1 :: IO (IOUArray Int Int)
  forM_ [2..(n-1)] $ \i ->
    forM_ [2..n] $ \a ->
      when (a >= i) $ do
        b <- readArray arr (a-i)
        modifyArray arr a (+ b) 
  print =<< readArray arr n

{-
  arr <- newArray (1,n) 0 :: IO (IOUArray Int Int)
  let
    partition :: Int -> IO Int
    partition m
        | m == 0 = return 1
        | m < 0 = return 0
        | otherwise = do
            a <- readArray arr m
            if a /= 0
              then return a
              else do
              let ps = takeWhile (<= m) pentagonals
              b <- sum <$> (forM [0..((length ps) - 1)] $
                            \i -> fmap (* (coefs !! i)) $ partition (m - ps !! i))
              writeArray arr m b
              return b
  s <- getCurrentTime
  print =<< fmap (subtract 1) (partition n)
  e <- getCurrentTime
  print $ diffUTCTime e s
-}

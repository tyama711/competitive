import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.Maybe
import qualified Data.ByteString.Char8 as B
import Data.STRef
import Data.List
import Data.Array.IO

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

-- f k = minimum . map (\n -> (k + n - 1) * (n + 1) `div` n) . filter (\n -> (k-1) `rem` n == 0) $ [1..(k-1)]

modifyArray arr i f = do
  a <- readArray arr i
  writeArray arr i (f a)

-- main = do
--   let n = 12000
--   arr <- newArray (2,n) 1000000 :: IO (IOUArray Int Int)
--   forM_ [2..n] $ \a -> do
--     forM_ [1..((n-1) `div` (a-1))] $ \b -> do
--       modifyArray arr (1+(a-1)*b) (min (a*(b+1)))

--   forM_ [2..n] $ \a -> do
--     b <- readArray arr a
--     forM_ [1..((n-a) `div` (b-1))] $ \c -> do
--       modifyArray arr (a + (b-1)*c) (min (b*(c+1)))

--   ans1 <- take 100 <$> getElems arr
--   let ans2 = map sum $ map (solve 2) $ [2..101]
--   print $ filter (\(a,(b,c)) -> b /= c) $ zip [2..] $ zip ans1 ans2

check xs = product xs == sum xs

candidates k = concatMap (_candidates k 1 (2*k)) [(k+1)..(2*k)]

_candidates k p q sum
  | k == 1 = if p*sum <= q then [[sum]] else []
  | otherwise = do
      a <- filter (\a -> a*p <= q) [1..(sum `div` k)]
      b <- _candidates (k-1) (a*p) q (sum-a)
      return $ a : b

solve k = sum . head . filter check $ candidates k

main = let n = 100
       in print $ map solve [2..n]

-- main = do
--   --n <- readInt <$> B.getLine
--   let n = 50
--   forM_ [2..30] $ \a -> putStrLn $ show a ++ "," ++ show (solve 2 a)

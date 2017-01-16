import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.IORef
import Data.Time
import Control.Applicative
import Control.Monad
import Data.Array.IArray
import System.IO

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

binsearch haystack needle lo hi
  | hi < lo = Nothing
  | pivot > needle = binsearch haystack needle lo (mid-1)
  | pivot < needle = binsearch haystack needle (mid+1) hi
  | otherwise = Just mid
  where
    mid = lo + (hi-lo) `div` 2
    pivot = haystack!mid

main = do
  n <- readInt <$> B.getLine
  start <- getCurrentTime
  print =<< getCurrentTime
  ans2 <- newIORef []
  ans4 <- newIORef []
  ans5 <- newIORef []
  let candidates = take n primes
      f1 i j =
        isPrime (read (show (primes !! i) ++ show (primes !! j)) :: Int) &&
        isPrime (read (show (primes !! j) ++ show (primes !! i)) :: Int)

  forM_ [0..(n-1)] $ \p ->
    forM_ [(p+1)..(n-1)] $ \q -> when (f1 p q) $ modifyIORef ans2 (++ [(p,q)])

  print =<< getCurrentTime
  xs <- readIORef ans2
  let arr = listArray (0, (length xs) - 1) xs :: Array Int (Int, Int)
  forM_ [0..((length xs) - 1)] $ \i -> do
    let x1 = fst (xs !! i)
        x2 = snd (xs !! i)
        ys = dropWhile (\(y1,y2) -> y1 <= x2) xs
    forM_ [((length xs) - (length ys))..((length xs) - 1)] $ \j -> do
      let y1 = fst (xs !! j)
          y2 = snd (xs !! j)
      -- when (f1 x1 y1 && f1 x1 y2 && f1 x2 y1 && f1 x2 y2) $
      when (isJust (binsearch arr (x1, y1) (i+1) (j-1)) &&
            isJust (binsearch arr (x1, y2) (i+1) (j-1)) &&
            isJust (binsearch arr (x2, y1) (i+1) (j-1)) &&
            isJust (binsearch arr (x2, y2) (i+1) (j-1))) $
        modifyIORef ans4 (++ [[x1, x2, y1, y2]])

  print =<< getCurrentTime
  ys <- readIORef ans4
  forM_ [0..((length ys) - 1)] $ \i ->
    forM_ [(((ys !! i) !! 3) + 1)..(n-1)] $ \j -> do
      when (isJust (binsearch arr ((ys !! i) !! 0, j) 0 ((length xs) - 1)) &&
            isJust (binsearch arr ((ys !! i) !! 1, j) 0 ((length xs) - 1)) &&
            isJust (binsearch arr ((ys !! i) !! 2, j) 0 ((length xs) - 1)) &&
            isJust (binsearch arr ((ys !! i) !! 3, j) 0 ((length xs) - 1))) $
        modifyIORef ans5 (++ [ys !! i ++ [j]])
  
  print =<< getCurrentTime
  end <- getCurrentTime
  print =<< map (map (primes !!)) <$> readIORef ans5
  let diff = diffUTCTime end start
  file <- openFile "time.dat" AppendMode
  hPutStr file $ show n ++ " " ++ init (show diff) ++ " "
  hClose file

import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.IORef
import Data.Time
import Data.IORef
import Data.List
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
  s2 <- newIORef []
  let candidates = take n primes
      ps = listArray (0,n-1) (take n primes) :: Array Int Int
      f1 i j =
        -- isJust (binsearch ps (read (show (ps ! i) ++ show (ps ! j))) 0 (n - 1)) &&
        -- isJust (binsearch ps (read (show (ps ! j) ++ show (ps ! i))) 0 (n - 1))
        isPrime (read (show (primes !! i) ++ show (primes !! j)) :: Int) &&
        isPrime (read (show (primes !! j) ++ show (primes !! i)) :: Int)

  forM_ [0..(n-1)] $ \p ->
    forM_ [(p+1)..(n-1)] $ \q -> when (f1 p q) $ modifyIORef s2 (++ [[p,q]])

  s3 <- newIORef []
  a1 <- readIORef s2
  print $ map (map (ps !)) a1
  let a2 = sort (map reverse a1)
      arr = listArray (0,((length a1) - 1)) a1 :: Array Int [Int]
  --print a1
  --print a2
      loop xs ys
        | xs == [] || ys == [] = return ()
        | head (head xs) == head (head ys) = do
            let xs' = takeWhile (\x -> head x == head (head xs)) xs
                ys' = takeWhile (\y -> head y == head (head ys)) ys
                zs = [(y !! 1) : x | x <- xs', y <- ys', isJust (binsearch arr [y !! 1, x !! 1] 0 ((length a1) - 1))]
            modifyIORef s3 (++ zs)
            loop (drop (length xs') xs) (drop (length ys') ys)
        | head (head xs) < head (head ys) = loop (tail xs) ys
        | otherwise = loop xs (tail ys)
  loop a1 a2

  s4 <- newIORef []
  a3 <- sort <$> readIORef s3
  print $ map (map (ps !)) a3
  let arr2 = listArray (0,((length a3) - 1)) a3 :: Array Int [Int]
      loop2 xs ys
        | xs == [] || ys == [] = return ()
        | head (head xs) == head (head ys) = do
            let xs' = takeWhile (\x -> head x == head (head xs)) xs
                ys' = takeWhile (\y -> head y == head (head ys)) ys
                zs = [(y !! 1) : x | x <- xs', y <- ys', isJust (binsearch arr2 ((y !! 1) : (tail x)) 0 ((length a3) - 1))]
            modifyIORef s4 (++ zs)
            loop2 (drop (length xs') xs) (drop (length ys') ys)
        | head (head xs) < head (head ys) = loop2 (tail xs) ys
        | otherwise = loop2 xs (tail ys)
  loop2 a3 a2

  s5 <- newIORef []
  a4 <- sort <$> readIORef s4
  print $ map (map (ps !)) a4
  let arr3 = listArray (0,((length a4) - 1)) a4 :: Array Int [Int]
      loop3 xs ys
        | xs == [] || ys == [] = return ()
        | head (head xs) == head (head ys) = do
            let xs' = takeWhile (\x -> head x == head (head xs)) xs
                ys' = takeWhile (\y -> head y == head (head ys)) ys
                zs = [(y !! 1) : x | x <- xs', y <- ys', isJust (binsearch arr3 ((y !! 1) : (tail x)) 0 ((length a4) - 1))]
            modifyIORef s5 (++ zs)
            loop3 (drop (length xs') xs) (drop (length ys') ys)
        | head (head xs) < head (head ys) = loop3 (tail xs) ys
        | otherwise = loop3 xs (tail ys)
  loop3 a4 a2

  print =<< map (map (ps !)) <$> readIORef s5

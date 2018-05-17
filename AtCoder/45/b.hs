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

modifyArray a i f = writeArray a i =<< (f <$> readArray a i)

main = do
  (n, m) <- readIntPair
  counter <- newArray (0, n+1) 0 :: IO (IOUArray Int Int)
  let loop i | i < m = do
                 (s, t) <- readIntPair
                 modifyArray counter s (+ 1)
                 modifyArray counter (t+1) (subtract 1)
                 ((:) (s, t)) <$> loop (i+1)
             | otherwise = return []
  inputs <- loop 0

  let loop2 i s t
        | i <= n = do
            tmp <- readArray counter i
            if (t+tmp) == 1
              then do writeArray counter i (s+t+tmp)
                      loop2 (i+1) (s+t+tmp) (t+tmp)
              else do writeArray counter i s
                      loop2 (i+1) s (t+tmp)
        | otherwise = return ()
  loop2 1 0 0

  result <- forM inputs (\x -> do
                  let (s, t) = x
                  start <- readArray counter (s-1)
                  end <- readArray counter t
                  if end - start == 0
                    then return True
                    else return False)
            
  let tmp = zip [1..m] result
      answer = [fst x | x <- tmp, snd x == True]
      
  print $ length answer
  forM_ answer print

import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.IORef
import Data.Set
import Test.HUnit
import System.IO

readInt = fromJust . fmap fst . B.readInt
readInts = Data.List.map readInt . B.words <$> B.getLine
readIntPair = l2p . Data.List.map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)



counter = do
  c <- newIORef 0
  return $ (\f -> do
               c' <- readIORef c
               writeIORef c (f c')
               return (f c'))
    
solve c set n = case n of
  4 -> c (+ size set)
  _ -> do
    forM_ (toList (fst (split (((findMax set) `div` (2^(4-n)))+1) set)))
      (\y -> solve c (snd (split (2*y-1) set)) (n+1))
    c (+ 0)

main = do
  n <- readInt <$> B.getLine
  xs <- replicateM n (readInt <$> B.getLine)
  c <- counter
  print =<< solve c (fromList xs) 1
--  runTestText (putTextToHandle stderr False) =<< tests

tests = do
  c1 <- counter
  res1 <- solve c1 (fromList [1, 2, 4, 5, 10]) 1
  c2 <- counter
  res2 <- solve c2 (fromList [11,12,13,14,15,16,17,18,19,20]) 1
  c3 <- counter
  res3 <- solve c3 (fromList [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]) 1
  return $ TestList [ "[1, 2, 4, 5, 10]" ~: res1 ~?= 2,
                      "[11,12,13,14,15,16,17,18,19,20]" ~: res2 ~?= 0,
                      "[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]" ~: res3 ~?= 94
                    ]

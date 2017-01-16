import Control.Applicative
import Control.Monad
import Data.Array.IO

solve :: Int -> [Int] -> IO Int
solve n (c:cs) =
  if c == 1
  then return 1
  else sum <$> (forM [0..(n `div` c)] $ \x -> solve (n-x*c) cs)

modifyArray a i f = do
  b <- readArray a i
  writeArray a i (f b)

main = do
  arr <- newArray (0,200) 1 :: IO (IOUArray Int Int)
  forM_ [2,5,10,20,50,100,200] $ \i ->
    forM_ [2..200] $ \a ->
      when (a >= i) $ do
        b <- readArray arr (a-i)
        modifyArray arr a (+ b) 
  print =<< readArray arr 200

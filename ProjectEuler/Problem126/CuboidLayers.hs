import Control.Monad
import Control.Applicative
import Data.Array.IO

cubes a b c l = 4*l*l + 4*(a+b+c-3)*l + 2*(a*b+b*c+c*a) - 4*(a+b+c) + 8

modifyArray a i f = do
  b <- readArray a i
  writeArray a i (f b)

main = do
  let n = 20000
  arr <- newArray (1,n) 0 :: IO (IOUArray Int Int)
  forM_ [1..(n `div` 4)] $ \a -> do
    forM_ [1..(min a (n `div` (2*a)))] $ \b -> do
      forM_ [1..b] $ \c -> do
        forM_ (takeWhile (<= n) (map (cubes a b c) [1..])) $ \d ->
          modifyArray arr d (+ 1)
  print =<< head . filter ((== 1000) . snd) <$> getAssocs arr

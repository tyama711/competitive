import Control.Applicative
import Control.Monad
import Data.Array.IO
import Data.Char

main = do
  arr <- newArray (1,10^7) (-1) :: IO (IOUArray Int Int)
  writeArray arr 1 0
  writeArray arr 89 1
  let f i = do
        a <- readArray arr i
        if a == -1
          then do
          b <- f $ sum $ map ((^2) . digitToInt) $ show i
          writeArray arr i b
          return b
          else
          return a
      
  forM_ [1..(10^7)] $ \i -> f i
  print =<< sum <$> getElems arr
     

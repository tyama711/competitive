import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as B

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

main = do
  n <-  readInt <$> B.getLine
  l <- replicateM n B.getLine
  let h = map readInt l -- . B.lines <$> B.getContents
  let a = zipWith (>) h (tail h)
      b = group a
      c = groupBy (const head) b
      d = map (sum . map length) c
      e = 0:d
      f = maximum e
      g = f + 1

  print a
  print b
  print c
  print d
  print e
  print f
  print g
  -- let bs = zipWith3 (\a b c-> a > b && b < c) h (tail h) (tail (tail h))
  --     index = 0:[x+1 | x <- [0..(length bs -1)], bs!!x]++[length bs +1]
  --     diff = zipWith subtract index $ tail index
  -- print $ (maximum diff) +1
      

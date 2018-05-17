import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as B

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

-- solve t k n
--       | length t < 3 = -1
--       | otherwise = let (t1:t2:t3:ts) = t in
--           if t1+t2+t3 <= k then n else solve (t2:t3:ts) k n+1

main = do
  -- [n, k] <- map read . words <$> getLine
  -- ts <- replicateM n readLn
  -- let l = zipWith3 (\a b c -> a+b+c < k) t (tail t) (tail (tail t))
  -- print (case findIndex id l of
  --          Nothing -> -1
  --          Just i -> i+3)
  -- (n,k) <- readIntPair
  -- ts <- map readInt . B.lines <$> B.getContents
  x <- replicateM 3 B.getLine
  let y = map B.readInt x
      z = map (fmap fst) y
      w = map fromJust z
  print y
  print z
  print w
  -- let bs = zipWith3 (\a b c -> a + b + c < k) ts (tail ts) (tail $ tail ts)
  -- putStrLn $ case findIndex id bs of
  --              Nothing -> "-1"
  --              Just i -> show $ i+3

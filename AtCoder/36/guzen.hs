import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as B

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

solve s v minv maxv
      | s == B.empty = maxv - minv
      | B.head s == '1' = solve (B.drop 1 s) (v+1) minv (max (v+1) maxv)
      | B.head s == '0' = solve (B.drop 1 s) (v-1) (min (v-1) minv) maxv
      | otherwise = solve (B.drop 1 s) v minv maxv

solve2 s v minv maxv ans
    | s == B.empty = ans

main = do
  (n,k) <- readIntPair
  s <- B.getLine
  let d = solve s 0 0 0
      

  print $ solve s 0 0 0

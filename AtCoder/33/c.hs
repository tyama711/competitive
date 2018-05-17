import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

data SegTree a = Nil | Node a a a (SegTree a) (SegTree a)

-- create :: a -> SegTree a
create 1 = Node 0 1 1 Nil Nil
create n = Node 0 1 n (create x) (create (n-x))
  where x = 2^(floor . logBase 2 (n-1))

main = do
  print $ create 5

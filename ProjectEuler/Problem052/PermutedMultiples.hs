import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Char
import Data.List
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

check n = let n' = sort (show n)
          in n' == sort (show (2*n)) &&
             n' == sort (show (3*n)) &&
             n' == sort (show (4*n)) &&
             n' == sort (show (5*n)) &&
             n' == sort (show (6*n))

main = do
  let a = "166666666"
  forM_ [2..8] $ \i ->
    forM_ [10^i..(read (take (i+1) a))] $ \n -> do
      when (check n) $ print n

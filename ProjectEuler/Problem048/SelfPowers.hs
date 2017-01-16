import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Char
import Data.List
import Control.Applicative

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

solve n = (sum (map f [1..1000])) `mod` 10^10

f n = foldl' (\a b -> (a*b) `mod` 10^10) 1 (replicate n n)

main = print $ solve 1000

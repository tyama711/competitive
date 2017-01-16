import qualified Data.ByteString.Char8 as B
import Data.List
import Data.Char
import Data.Function
import Data.Maybe
import Data.Ratio
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

numOfDigits n = length (show n)

(%%) :: Integral a => Ratio a -> Ratio a -> Ratio a
(%%) a b = let c = (numerator a) * (denominator b)
               d = (denominator a) * (numerator b)
           in (c `div` (gcd c d)) % (d `div` (gcd c d))

main = print $ length $ filter (\a -> numOfDigits (numerator a) > numOfDigits (denominator a)) $ take 1000 $ tail $ iterate (\a -> 1 + 1%%(1+a)) 1

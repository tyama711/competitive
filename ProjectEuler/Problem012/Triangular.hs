import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Char

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

factorize n = _factorize n 2

_factorize n m
  | n <= m = [n]
  | n `mod` m == 0 = m : (_factorize (n `div` m) m)
  | otherwise = _factorize n (m+1)

numOfDivisor n =
  product ((map (\x -> 1 + length x) . group . factorize) n)

main = do
  let loop i =
        let n = i * (i+1) `div` 2
            d = numOfDivisor n
        in if d > 500
           then print n
           else loop (i+1)
  loop 1
             

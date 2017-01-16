import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Char
import Data.List
import Data.Function
import Data.IORef
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

solve n p =
  let a = length (filter isPrime [n^2-n+1,n^2-2*n+2,n^2-3*n+3])
  in if (2*n-1) `div` (p+a) >= 10
     then n
     else solve (n+2) (p+a)

main = print $ solve 3 0

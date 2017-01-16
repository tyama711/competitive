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

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

check :: Int -> Bool
check n = foldr (\a b -> a <= floor (sqrt (fromIntegral (n `div` 2))) && (b || isPrime (n - 2*a^2))) False [1..]

main = do
  n <- readInt <$> B.getLine
  let target = take n (filter (not . isPrime) [3,5..])
  print $ filter (not . check) target

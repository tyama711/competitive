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

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

arePermutations a b c = let a' = sort (show a)
                        in a' == sort (show b) && a' == sort (show c)

main = do
  let candidates = takeWhile (< 10000) (dropWhile (< 1000) primes)
  forM_ [0..((length candidates)-3)] $ \i ->
    forM_ [(i+1)..((length candidates)-2)] $ \j ->
      when (2 * (candidates !! j) - candidates !! i < 10000 &&
            isPrime (2 * (candidates !! j) - candidates !! i) &&
            arePermutations (candidates !! i) (candidates !! j)
            (2 * (candidates !! j) - (candidates !! i))) $
      print $ [candidates !! i, candidates !! j,
               2 * (candidates !! j) - candidates !! i]


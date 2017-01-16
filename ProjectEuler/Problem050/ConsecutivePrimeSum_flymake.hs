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

main = do
  ans <- newIORef (0,1)
  let n = 1000000
      ps = takeWhile (< n) primes
  forM_ [0..((length ps) - 1)] $ \i -> do
    (_,d) <- readIORef ans
    when (d * primes !! i < n) $
      let a = ((dropWhile (not . isPrime)) . reverse . (takeWhile (< n)) . (scanl (\a b -> a+b) 0)) (drop i ps)
          b = length a - 1
          c = head a
      in when (b > d) $ writeIORef ans (c,b)
  print =<< readIORef ans

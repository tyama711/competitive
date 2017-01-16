import qualified Data.ByteString.Char8 as B
import Data.Array.IO
import Data.Maybe
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt

primes = 2 : filter isPrime [3,5..]
isPrime n = n > 1 &&
	foldr (\p r -> p*p > n || ((n `rem` p) /= 0 && r))
		True primes

modifyArray a i f = do
  b <- readArray a i
  writeArray a i (f b)

main = do
  let n = 100
  arr <- newArray (1,n) 0 :: IO (IOUArray Int Int)
  forM_ (takeWhile (<= n) primes) $ \i -> do
    modifyArray arr i (+ 1)
    forM_ [2..n] $ \a ->
      when (a > i) $ do
        b <- readArray arr (a-i)
        modifyArray arr a (+ b)
  print =<< head . dropWhile ((< 5000) . snd) <$> getAssocs arr

import qualified Data.ByteString.Char8 as B
import Data.List
import Data.Char
import Data.Function
import Data.Maybe
import Control.Applicative
import Control.Monad
import Data.IORef

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

pow a 0 = 1
pow 0 b = 0
pow a b
  | b `mod` 2 == 0 = (pow a (b `div` 2))^2
  | otherwise = (pow a (b `div` 2))^2 * a

sumOfDigits n = sum (map digitToInt (show n))

main = do
  ans <- newIORef 0
  forM_ [1..100] $ \a ->
    forM_ [1..100] $ \b -> do
      c <- readIORef ans
      when (sumOfDigits (pow a b) > c) $ writeIORef ans $ sumOfDigits (pow a b)
  print =<< readIORef ans

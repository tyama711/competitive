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

solve :: Integer -> Integer
solve n
  | n == 1 = 1
  | otherwise =
      let a = n * solve (n - 1)
      in if a `mod` 10 == 0
         then a `div` 10
         else a

main = do
  n <- readInt <$> B.getLine
  print $ sum $ map digitToInt $ show $ solve $ toInteger n

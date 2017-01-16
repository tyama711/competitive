import qualified Data.ByteString.Char8 as B
import Data.List
import Data.Char
import Data.Function
import Data.Maybe
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

isPalindrome :: Integer -> Bool
isPalindrome n = show n == reverse (show n)

isLychrel :: Integer -> Bool
isLychrel n = dropWhile (not . isPalindrome) (take 50 (tail (iterate (\m -> m + read (reverse (show m))) n))) == []

main = do
  print $ length $ filter (isLychrel . toInteger) [1..10000]

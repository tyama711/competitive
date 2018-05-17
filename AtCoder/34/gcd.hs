import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

factorization n x
  | n*n > x = if x>1 then [x] else []
  | x `mod` n == 0 = n:factorization n (x `div` n)
  | otherwise = factorization (n+1) x

main = do
  (a,b) <- readIntPair
  print $ foldl (\a b -> a*(b+1)`mod`1000000007) 1 $ map length . group . sort . concatMap (factorization 2) $ [b+1..a]

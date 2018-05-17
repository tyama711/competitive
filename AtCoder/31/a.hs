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

main = do
  name <- B.getLine
  let rname = B.reverse name
  putStrLn $ case (elem False (B.zipWith (\a b -> a == b) name rname)) of
    False -> "YES"
    otherwise -> "NO"
    

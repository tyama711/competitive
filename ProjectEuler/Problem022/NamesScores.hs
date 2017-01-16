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

score name = B.foldl (\x c -> x + ord c - ord 'A' + 1) 0 name

main = do
  words <- map (B.init . B.tail) . sort . B.split ',' <$> B.getContents
  scores <- forM [0..(length words - 1)] $ \i -> return $ (i + 1) * score (words !! i)
  print $ sum $ scores

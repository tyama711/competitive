import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Char
import Data.List
import Data.List.Split
import Data.Bits
import Control.Applicative

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

main = do
  xs <- map (read :: String -> Int) . splitOn "," <$> getContents
  let key = map ord (concat (replicate (((length xs) + 2) `div` 3) "god"))
  print $ sum $ zipWith xor xs key
  

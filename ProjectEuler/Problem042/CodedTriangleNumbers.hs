import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Char
import Control.Applicative

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

isTriangle n = let n' = (floor (sqrt (fromIntegral (2*n))))
               in 2*n == n'*(n'+1)

isTriangleWord word = let value = B.foldl (\s c -> s + ord c - ord 'A' + 1) 0 word
                      in isTriangle value

main = do
  words <- map (B.init . B.tail) . B.split ',' <$> B.getContents
  print $ length $ filter isTriangleWord words

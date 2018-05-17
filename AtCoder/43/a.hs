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
  [n, a, b] <- readInts
  s <- replicateM n $ readInt <$> B.getLine
  let sd = (maximum s) - (minimum s)
      sa = (fromIntegral (sum s)) / (fromIntegral (length s))
  if sd == 0
    then print (-1)
    else putStrLn $ show ((fromIntegral b) / (fromIntegral sd)) ++ " " ++ show ((fromIntegral a) - sa*(fromIntegral b)/(fromIntegral sd))

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

isPrime n =
  let loop i
        | i*i <= n = if n `mod` i == 0
                     then False
                     else loop (i+1)
        | otherwise = True
    in n /= 1 && loop 2

seemPrime n = isPrime n ||
              (n /= 1 && n `mod` 2 /= 0 && n `mod` 3 /= 0 && n `mod` 5 /= 0)

main = do
  n <- readInt <$> B.getLine
  if seemPrime n
    then putStrLn "Prime"
    else putStrLn "Not Prime"

import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.STRef
import Data.Array.ST
import Data.Array.IO
import Debug.Trace

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

fact 0 = 1
fact n = n * fact (n-1)

solve n =
  let loop i xs n'
        | i == 0 = xs
        | otherwise = loop (i-1) ((n' `div` (fact i)) : xs) (n' `mod` (fact i))
  in reverse $ loop 9 [] (n-1)

main = do
  n <- readInt <$> B.getLine
  let loop xs ys = case xs of
        [] -> print ys
        (x:xs') -> do
          print $ ys !! x
          loop xs' ((take x ys) ++ (drop (x+1) ys))
  loop (solve n) "0123456789"

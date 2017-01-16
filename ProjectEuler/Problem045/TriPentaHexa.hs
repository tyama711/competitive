import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Char
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

hexagonals = map (\n -> n * (2*n - 1)) [1..]

isPentagonal n =
  let n' = ceiling (sqrt (2*(fromIntegral n)/3))
  in 2*n == n'*(3*n'-1)

isTriangle n = let n' = (floor (sqrt (fromIntegral (2*n))))
               in 2*n == n'*(n'+1)

main = do
  forM_ [1..50000] $ \i ->
    when (isPentagonal (hexagonals !! i) && isTriangle (hexagonals !! i)) $
    putStrLn $ show i ++ "," ++ show (hexagonals !! i)

import Control.Monad
import Control.Monad.ST
import Data.List
import Data.IORef
import Control.Applicative
import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Char

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

pentagonals = map (\n -> (n * (3*n - 1)) `quot` 2) [1..]

isPentagonal n =
  let n' = ceiling (sqrt (2*(fromIntegral n)/3))
  in 2*n == n'*(3*n'-1)

main = do
  ans <- newIORef []
  forM_ [2..3000] $ \i ->
    forM_ [(i-1),(i-2)..0] $ \j ->
      when ((isPentagonal (pentagonals !! i - pentagonals !! j)) &&
        (isPentagonal (pentagonals !! i + pentagonals !! j))) $ do
      modifyIORef ans ((pentagonals !! j, pentagonals !! i) :)
      putStrLn $ show i ++ "," ++ show j
  print =<< readIORef ans

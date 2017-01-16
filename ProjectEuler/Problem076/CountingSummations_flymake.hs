import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Time
import System.IO

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

solve 1 m = 1
solve n 1 = 1
solve n m = let a = if n <= m then 1 else 0
            in sum (map (\a -> solve (n-a) a) [1..(min m (n-1))]) + a

solve' :: Int -> Int -> IO Int
solve' n c = if c == 1
	then return 1
	else sum <$> (forM [0..(n `div` c)] $ \x -> solve' (n-x*c) (c-1))
 
main = do
  n <- readInt <$> B.getLine
  s <- getCurrentTime
  print =<< solve' n (n-1)
  e <- getCurrentTime
  let diff = diffUTCTime e s
  file <- openFile "time.dat" AppendMode
  hPutStrLn file $ show n ++ " " ++ init (show diff)
  hClose file

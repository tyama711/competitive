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
   wrds <- B.words <$> B.getLine
   let loop xs = case xs of
         [] -> ""
         (y:ys) -> case y of
                   "Left" -> "< " ++ (loop ys)
                   "Right" -> "> " ++ (loop ys)
                   "AtCoder" -> "A " ++ (loop ys)
                   _ -> "? " ++ (loop ys)
       wrds2 = (loop (map B.unpack wrds))
   putStrLn $ take (max ((length wrds2) - 1) 0) wrds2

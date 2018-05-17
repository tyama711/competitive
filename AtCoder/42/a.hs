import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Set

readInt = fromJust . fmap fst . B.readInt
readInts = Data.List.map readInt . B.words <$> B.getLine
readIntPair = l2p . Data.List.map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

main = do
  (n, m) <- readIntPair
  as <- replicateM m $ readInt <$> B.getLine
  let loop xs set = case xs of
        [] -> do
          if Data.Set.null set
            then return ()
            else do
                 let (min, set') = deleteFindMin set
                 print min
                 loop [] set'
        (y:ys) -> do
          if member y set
            then do
                 print y
                 loop ys $ Data.Set.delete y set
            else loop ys set
  loop (reverse as) (fromList [1..n])

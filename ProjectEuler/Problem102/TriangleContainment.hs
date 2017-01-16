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

outerProd (x1,y1) (x2,y2) = x1*y2 - y1*x2

slice :: Int -> [a] -> [[a]]
slice n = unfoldr phi
  where 
    phi [] = Nothing
    phi xs = Just $ splitAt n xs

containOrigin :: [(Int,Int)] -> Bool
containOrigin xs = signum (bs !! 0) == signum (bs !! 1) &&
                   signum (bs !! 0) == signum (bs !! 2)
  where as = zipWith (\(a1,a2) (b1,b2) -> (a1-b1, a2-b2)) xs $ tail $ cycle $ xs
        bs = zipWith outerProd as $ xs

main = do
  inputs <- slice 3 . map l2p . slice 2 . map readInt . concatMap (B.split ',') . B.words <$> B.getContents
  print $ length $ filter containOrigin $ inputs

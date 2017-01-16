import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.Maybe
import qualified Data.ByteString.Char8 as B
import Data.STRef
import Data.List

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

sqrt' n = floor . sqrt . fromIntegral $ n

triplets m = [sort [2*a*p*q, a*(p^2-q^2), a*(p^2+q^2)] |
              let m' = sqrt' m
              , p <- [2..m'], q <- [1..(p-1)] ,a <- [1..(m `div` (max (2*p*q) (p^2-q^2)))]
              , gcd p q == 1, odd (p+q)]

solve m = runST $ do
  s <- newSTRef 0
  forM_ (triplets (2*m)) $ \[a,b,c] -> do
    unless (a > m) $ do
      when (b <= m) $ modifySTRef s (+ (a `div` 2))
      when (b <= 2*a) $ modifySTRef s (+ (a - (b+1) `div` 2 + 1))
  readSTRef s
  

main = do
  n <- readInt <$> B.getLine
  print $ solve n


{-
import Data.Maybe
import Data.Array.IO
import qualified Data.ByteString.Char8 as B
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt
p2l (a,b) = [a,b]

modifyArray a i f = do
  b <- readArray a i
  writeArray a i (f b)

indices = iterate (\i -> if i > 0 then -i else -i + 1) 1
coefs = cycle [1,1,-1,-1]

pentagonal :: Int -> Int
pentagonal k = k * (3*k - 1) `div` 2

pentagonals = map pentagonal indices

main = do
  n <- readInt <$> B.getLine
  partitions <- newArray (0,n) 0 :: IO (IOUArray Int Int)
  writeArray partitions 0 1
  let
    partition :: Int -> IO Int
    partition m = do
      let ps = takeWhile (<= m) pentagonals
      b <- sum <$> (forM [0..((length ps) - 1)] $
                    \i -> fmap (* coefs !! i) $ readArray partitions (m - ps !! i))
      writeArray partitions m (b `rem` 10^6)
      return b
  forM_ [1..n] $ \m -> partition m
  print =<< head . filter ((== 0) . snd) <$> getAssocs partitions
-}


import Data.List
import Data.Array.IArray
import Data.Maybe
import Control.Monad

ini = array (0,0) [(0,1)]::Array Integer Integer

piles l a m = ps
    where ps = listArray (0,m) $ elems a++[p n `mod` l | n<-[m'+1..m]]
             ::Array Integer Integer
          (0,m') = bounds a
          p n = sum [(s*).(ps!)$n-k|(s,k) <- takeWhile((<=n).snd) penta]

penta = zip  (cycle [1,1,-1,-1]).
        concat.zipWith(\ a b -> [a,b])(scanl1(+)[1,4..]) $ scanl1(+)[2,5..]

main = print.fst.fromJust.msum.
       map (find((==0).snd).assocs).scanl (piles$10^6) ini.iterate (2*) $100

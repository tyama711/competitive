import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Control.Monad.State
import Control.Monad.Writer
import Data.Array.IO
import Data.Array
import Debug.Trace
import Data.IORef
import GHC.Base

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
readInt3Pair = l23p . map readInt . take 3 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
l23p (a:b:c:_) = (a,b,c)

solve :: [Int] -> [(Int,Int)] -> Int -> Maybe [Int]
solve _ _ 0 = Just []
solve [] _ _ = Nothing
solve vs ps k =
  let as = getEdges vs ps
      bs = [snd p | p <- ps, elem (fst p) as]
      cs = [c | c <- bs, elem c as]
      ds = take k $ as \\ cs
  in if ds == []
     then foldl (<|>) Nothing (map (f vs ps k) vs)
     else g vs ps k ds

f vs ps k v =
  let as = v : nextNodes vs ps [v]
      bs = exceptNodes as ps
  in fmap (v :) (solve (vs \\ as) bs (k-1))

g vs ps k vs' =
  let as = vs' ++ nextNodes vs ps vs'
      bs = exceptNodes as ps
  in fmap (++ vs') (solve (vs \\ as) bs (k - (length vs')))

numOfBranch v ps = length [p | p <- ps, fst p == v || snd p == v]
getEdges vs ps = [v | v <- vs, numOfBranch v ps <= 1]
exceptNodes vs ps = [p | p <- ps, not (elem (fst p) vs) && not (elem (snd p) vs)]
nextNodes vs ps vs' = nub (concat (map (\v -> [a | a <- vs \\ vs', elem (a,v) ps || elem (v,a) ps]) vs'))

test (Just x) = x
test Nothing = []

main = do
  [v,e,k] <- readInts
  ps <- replicateM e $ readIntPair
  forM_ (test (solve [0..(v-1)] ps k)) print

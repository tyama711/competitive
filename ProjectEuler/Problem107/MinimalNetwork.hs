import Control.Applicative
import Control.Monad
import Data.List
import Data.List.Split
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.Ord
import Debug.Trace

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

read' :: String -> Int
read' s
  | s == "-" = 0
  | otherwise = read s :: Int

contain :: Int -> [[Int]] -> Maybe Int
contain x comps = findIndex (\comp -> elem x comp) comps

main = do
  inputs <- map read' . concatMap (splitOn ",") . words <$> getContents
  let n = 40
      paths = sortBy (comparing snd) [((i `quot` n, i `rem` n), inputs !! i) | i <- [0..(n^2-1)], inputs !! i /= 0]
      loop (p:pths) comps ans
        | length comps == 1 = ans
        | otherwise =
            let a = fromJust . contain (fst . fst $ p) $ comps
                b = fromJust . contain (snd . fst $ p) $ comps
            in if a == b
               then loop pths comps ans
               else
                 let comp1 = min a b
                     comp2 = max a b
                     comps' = (take comp2 comps) ++ (drop (comp2 + 1) comps)
                     comps'' = (take comp1 comps') ++ (drop (comp1 + 1) comps')
                 in loop pths (((comps !! a) ++ (comps !! b)) : comps'') (ans + (snd p))
          
  print $ (sum inputs) `div` 2 - (loop paths [[x] | x <- [0..(n-1)]] $ 0)

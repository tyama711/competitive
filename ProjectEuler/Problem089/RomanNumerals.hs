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

count :: Int -> Int
count n =
  let n' = n `rem` 1000
      a  = n `quot` 1000
      f x
        | 0 <= x && x <= 3 = x
        | x == 4 || x == 5 = 6 - x
        | 6 <= x && x <= 8 = x - 4
        | otherwise = 11 - x
  in (+ a) $ sum $ map f $ unfoldr (\x -> if x == 0 then Nothing else Just (x `rem` 10, x `quot` 10)) n'

value xs = _value 0 0 $ reverse xs
_value v m [] = v
_value v m (x:xs)
  | x == 'M' = _value (v+1000) 1000 xs
  | x == 'D' = _value (v+500) 500 xs
  | x == 'C' = if m > 100
               then _value (v-100) m xs
               else _value (v+100) 100 xs
  | x == 'L' = _value (v+50) 50 xs
  | x == 'X' = if m > 10
               then _value (v-10) m xs
               else _value (v+10) 10 xs
  | x == 'V' = _value (v+5) 5 xs
  | otherwise = if m > 1
               then _value (v-1) m xs
               else _value (v+1) 1 xs


main = do
  romans <- words <$> getContents
  let n = sum $ map length romans
  print $ (n -) $ sum $ map (count . value) romans

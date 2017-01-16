import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.List
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as B
import Data.STRef

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)

numToWords n = runST $ do
  w <- newSTRef []
  let words = ["zero", "one", "two", "three", "four", "five", "six",
               "seven", "eight", "nine", "ten", "eleven", "twelve",
               "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
               "eighteen", "nineteen", "twenty", "thirty", "forty",
               "fifty", "sixty", "seventy", "eighty", "ninety", "hundred",
               "thousand"]
      a = n `div` 100
      b = n `mod` 100
  if n == 1000
    then modifySTRef w ("one thousand" :)
    unless (b == 0) $
    if b <= 20
    then modifySTRef w ((words !! b) :)
    else if b `mod` 10 /= 0
         then do modifySTRef w ((words !! (b `mod` 10)) :)
                 modifySTRef w ((words !! (18 + b `div` 10)) :)
    else modifySTRef w ((words !! (18 + b `div` 10)) :)

  when ( a /= 0 && a /= 10 ) $
    do if b /= 0
              then modifySTRef w ("and" :)
              else return()
       modifySTRef w ("hundred" :)
       modifySTRef w ((words !! a) :)
  readSTRef w

main = do
  n <- readInt <$> B.getLine
  print $ length $ concat $ concatMap numToWords [1..n]
  -- forM_ (map numToWords [900..1000]) $ \x -> print x

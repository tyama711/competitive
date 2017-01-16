import qualified Data.ByteString.Char8 as B
import Data.List
import Data.Char
import Data.Function
import Data.Maybe
import Control.Applicative
import Control.Monad

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
p2l (a,b) = [a,b]

data Hand = NoPair | OnePair | TwoPairs | ThreeCards |
            Straight | Flush | FullHouse |FourCards |
            StraightFlush | RoyalFlush deriving (Eq, Ord, Enum, Show)

isStraight (x1:x2:xs)
  | x1 - x2 == 1 = isStraight (x2:xs)
  | otherwise = False
isStraight (x:xs) = True

hand :: [Char] -> (Hand, [Int])
hand cards =
  let nums = reverse (sort (map (order . (cards !!)) [0,2..8]))
      flush = length (nub (map (cards !!) [1,3..9])) == 1
      straight = isStraight nums
  in if sort nums == [12,11,10,9,8] && flush
     then (RoyalFlush, nums)
     else if straight && flush
     then (StraightFlush, nums)
     else if maximum (map length (group nums)) == 4
     then (FourCards, concat (sortBy ((flip compare) `on` length) (group nums)))
     else if sort (map length (group nums)) == [2,3]
     then (FullHouse, concat (sortBy ((flip compare) `on` length) (group nums)))
     else if flush
     then (Flush, nums)
     else if straight
     then (Straight, nums)
     else if maximum (map length (group nums)) == 3
     then (ThreeCards, concat (sortBy ((flip compare) `on` length) (group nums)))
     else if sort (map length (group nums)) == [1,2,2]
     then (TwoPairs, concat (sortBy ((flip compare) `on` length) (group nums)))
     else if maximum (map length (group nums)) == 2
     then (OnePair, concat (sortBy ((flip compare) `on` length) (group nums)))
     else (NoPair, nums)

order :: Char -> Int
order c
  | ord '2' <= ord c && ord c <= ord '9' = ord c - ord '2'
  | c == 'T' = 8
  | c == 'J' = 9
  | c == 'Q' = 10
  | c == 'K' = 11
  | c == 'A' = 12

player1win cards1 cards2 =
  let (hand1,n1) = hand cards1
      (hand2,n2) = hand cards2
  in if hand1 > hand2 ||
        (hand1 == hand2 && n1 > n2)
     then True
     else False

slice :: Int -> [a] -> [[a]]
slice n = unfoldr phi
  where 
    phi [] = Nothing
    phi xs = Just $ splitAt n xs

main = do
  cards <- slice 2 . slice 10 . concat . words <$> getContents
  print $ length $ filter (\[a,b] -> player1win a b) cards

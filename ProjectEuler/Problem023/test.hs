import Data.Array (Array, listArray, (!))
import Math.NumberTheory.Primes.Factorisation (sigma)

boolArr :: Array Int Bool
boolArr = listArray (1,28123) $ fmap isAbund [1..28123]
  where
    isAbund :: Integer -> Bool
    isAbund n = abundance > 0
      where
        abundance :: Integer
        abundance = (sigma 1 n) - (2*n)

nonSums :: [Int]
nonSums = filter ((not . any (boolArr !)) . remCands) [1..28123]
  where
    remCands :: Int -> [Int]
    remCands n = fmap (n -) $ takeWhile (<= n `quot` 2) abundNums
      where
        abundNums :: [Int]
        abundNums = filter (boolArr !) [1..28123]

main :: IO()
main = do
    print $ sum nonSums

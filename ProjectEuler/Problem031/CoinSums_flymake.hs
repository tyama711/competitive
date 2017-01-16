import Control.Applicative
import Control.Monad
import Data.List

solve :: Int -> [Int] -> IO Int
solve n (c:cs) = if c == 1
then return 1
else sum <$> (forM [0..(n `div` c)] $ \x -> solve (n-x*c) cs)
main = print =<< solve 200 [200, 100, 50, 20, 10, 5, 2, 1]

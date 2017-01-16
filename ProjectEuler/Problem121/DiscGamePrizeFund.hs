import Data.Ratio
import Data.Array.IO
import Control.Applicative
import Control.Monad

-- facts :: [Integer]
-- facts = 1:(zipWith (*) facts [1..])

-- (%%) :: Integral a => Ratio a -> Ratio a -> Ratio a
-- (%%) a b = ((numerator a) * (denominator b)) % ((denominator a) * (numerator b))

-- solve n = let p = (sum $ map (\i -> 1 % ((facts !! i) * (facts !! (n - i)))) [0..(n `div` 2)]) %% (((toInteger n) + 1) % 1)
--           in p --(denominator p) `div` (numerator p)

main = do
  let n = 15
  arr <- newArray ((0,0),(n,n)) (-1) :: IO (IOUArray (Int,Int) Double)
  forM_ [0..n] $ \i -> writeArray arr (i,0) 1
  forM_ [0..(n-1)] $ \i -> writeArray arr (i,i+1) 0
  let solve :: Int -> Int -> IO Double
      solve a b = do
        c <- readArray arr (a,b)
        if c == -1
          then do
          p <- solve (a-1) (b-1)
          q <- solve (a-1) b
          let a' = fromIntegral a
              r = p / (a' + 1) + q * a' / (a' + 1)
          writeArray arr (a,b) r
          return r
          else return c
  print =<< floor . (1 /) <$> solve n (ceiling (((fromIntegral n) + 1) / 2))

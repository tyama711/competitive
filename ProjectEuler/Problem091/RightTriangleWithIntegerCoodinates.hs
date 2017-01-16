import Control.Monad
import Data.IORef

isRight (x1,y1) (x2,y2) =
  let (x3,y3) = (x1-x2,y1-y2)
  in x1*x2 + y1*y2 == 0 ||
     x1*x3 + y1*y3 == 0 ||
     x2*x3 + y2*y3 == 0

main = do
  let n = 50
  r <- newIORef 0
  forM_ [(a,b) | a <- [0..n], b <- [1..n]] $ \(a,b) -> do
    forM_ [(c,d) | c <- [1..n], d <- [0..b], b > d || a < c,
           isRight (a,b) (c,d)] $ \(c,d) -> do
      modifyIORef r (+ 1)
  print =<< readIORef r

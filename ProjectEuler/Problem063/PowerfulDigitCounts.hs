import Control.Monad
import Data.IORef

numOfDigits n = length (takeWhile (/= 0) (iterate (\m -> m `div` 10) n))

main = do
  count <- newIORef 0
  forM_ [1..9] $ \a -> do
    let d = length (takeWhile id (zipWith (\b c -> numOfDigits c == b) [1..] (iterate (*a) a)))
    modifyIORef count (+ d)
  print =<< readIORef count

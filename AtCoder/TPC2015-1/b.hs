import qualified Data.ByteString.Char8 as B
import Control.Applicative
import Data.Maybe
import Control.Monad
import Data.List

readInt = fromJust . fmap fst . B.readInt
readInts = map readInt . B.words <$> B.getLine
readIntPair = l2p . map readInt . take 2 . B.words <$> B.getLine
l2p (a:b:_) = (a,b)
ps2l ((a,b):as) = a:b:(ps2l as)
ps2l _ = []
l2ps (a:b:as) = (a,b):(l2ps as)
l2ps _ = []

test (Just a) = a
test Nothing = 0

timeToMs t =
  let ts = map (fst . fromJust . B.readInt) $ concat . map (B.split '.') $ B.split ':' t
  in 3600000 * (ts !! 0) + 60000 * (ts !! 1) + 1000 * (ts !! 2) + (ts !! 3)

intersection (a,b) (c,d)
  | a <= d && c <= b = Just (max a c, min b d)
  | otherwise = Nothing

main = do
  n <- readInt <$> B.getLine
  intervals <- map (\x -> (timeToMs (fst x), timeToMs (snd x))) <$>
               replicateM n ( l2p . B.words <$> B.getLine )
  let goback = foldl ((fromJust .) . intersection)
               (21*3600000,22*3600000+59*60000+59*1000+999) $
               map (\(a,b) -> (a,b+1000)) $ filter (\(a,b) -> b - a <= 0) intervals
      intervals' = l2ps . map (\x -> if x >= snd goback then x + 1000 else x) $ ps2l intervals
  forM_ intervals' $ \x -> if (snd x - fst x) <= 0
                           then print $ snd x - fst x + 1000
                           else if (fst goback - 1000  < fst x && fst x < snd goback) ||
                                   (fst goback - 1000  < snd x && snd x < snd goback)
                                then print (-1)
                                else print $ snd x - fst x

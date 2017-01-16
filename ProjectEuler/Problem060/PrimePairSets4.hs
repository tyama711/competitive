main = print $ map sum $ solve

solve = do
 let primesTo10000 = takeWhile (<10000) primes
 a <- primesTo10000
 let m = filter (isMagic a) $ dropWhile (<= a) primesTo10000
 b <- m
 let n = filter (isMagic b) $ dropWhile (<= b) m
 c <- n
 let o = filter (isMagic c) $ dropWhile (<= c) n
 d <- o
 let p = filter (isMagic d) $ dropWhile (<= d) o
 e <- p
 return [a,b,c,d,e]

maxdiv = floor . sqrt . fromInteger

isPrime 1 = False
isPrime 2 = True
isPrime x = all (/=0) [mod x d | d <- takeWhile (<= maxdiv x) primes]
primes = filter isPrime [2..]

isMagic p1 p2 = isMagic' p1 p2 && isMagic' p2 p1
isMagic' p1 p2 = isPrime (read (show p1 ++ show p2))


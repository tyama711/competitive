f 0 = 1
f n = (2^(n `rem` 2) * a^2) `rem` 10^10
  where a = f (n `div` 2)

main = print $ 28433 * (f 7830457) `rem` 10^10 + 1

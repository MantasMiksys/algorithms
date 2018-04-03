bin_search :: Int -> [Int] -> Int -> Int -> Int
bin_search x arr lo hi
  | lo > hi = -1
  | arr!!m > x = bin_search x arr lo (m - 1)
  | arr!!m < x = bin_search x arr (m + 1) hi
  | otherwise = m
  where m = lo + ((hi - lo) `div` 2)

main = do 
    print (bin_search 3 [1, 3, 4, 5, 7, 8, 9] 0 6)
    print (bin_search 8 [1, 3, 4, 5, 7, 8, 9] 0 6)
    print (bin_search 2 [1, 3, 4, 5, 7, 8, 9] 0 6)

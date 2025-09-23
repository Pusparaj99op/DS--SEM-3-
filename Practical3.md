1. Theory
Selection Sort is a simple, in-place comparison-based sorting algorithm. The core idea is to divide the array into two parts: a sorted subarray and an unsorted subarray.

Initially, the sorted subarray is empty, and the unsorted subarray is the entire input array. The algorithm proceeds by repeatedly finding the minimum (or maximum, depending on the desired order) element from the unsorted subarray and moving it to the end of the sorted subarray. This process continues until the unsorted subarray becomes empty and the entire array is sorted.

Let's imagine you're sorting a hand of playing cards. You would look through all the unsorted cards, find the smallest one, and place it at the very beginning. Then, you'd look through the remaining unsorted cards, find the next smallest, and place it in the second position. You repeat this until all cards are in order. That's exactly how Selection Sort works! 🃏

Key Characteristics:

Time Complexity: The time complexity of Selection Sort is O(n 2) in all cases (best, average, and worst). This is because it must iterate through the remaining unsorted elements to find the minimum, even if the array is already sorted.

Space Complexity: It has a space complexity of O(1), meaning it requires no extra memory besides the original array, making it an in-place algorithm.

Stability: It is generally an unstable sorting algorithm. It does not preserve the relative order of equal elements.

Due to its O(n 
2
 ) complexity, it is not efficient for large datasets but performs well on small lists.
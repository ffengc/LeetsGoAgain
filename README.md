# LeetsGoAgain

- [English](./README.md)
- [中文](./README-CN.md)

In June 2025, I started systematically solving LeetCode problems. I had already practiced a few hundred problems back in my freshman year, but since I didn’t study algorithms in a structured way back then, I’ve forgotten quite a bit over the years.

This repository is created to record and motivate my progress, as well as to keep track of the problems I’ve solved. I plan to go through them in Chinese first, and later switch to English.

**All materials referenced from:** Programmer Carl’s collection: https://programmercarl.com/

## [Array `./docs/arrays.md`](./docs/arrays.md)
  - Array theory basics  
  - Binary search  
  - Remove elements  
  - Minimum size subarray sum  
  - Spiral Matrix II  
  - Range sum (prefix sum concept)  
  - Developer buys land (prefix sum)  
  - Summary  

## [Linked List `./docs/list.md`](./docs/list.md)
  - Linked list basics  
  - Remove linked list elements  
  - Design linked list  
  - Reverse linked list  
  - Swap nodes in pairs  
  - Remove Nth node from end of list  
  - Intersection of two linked lists  
  - Linked list cycle II (important: how to detect a cycle)  

## [Hash Table `./docs/hash_tables.md`](./docs/hash_tables.md)
  - Hash table basics  
  - Valid anagram  
  - Intersection of two arrays  
    - “So all hash problems can just use a set instead of an array?” — Not always true, depends on the scenario.  
  - Happy number  
  - Two sum (classic and important)  
  - Four sum II (classic and important)  
  - Ransom note  
  - Three sum (classic and important)  
    - The hash approach is complex; this one is better solved with two pointers.  
  - Four sum (classic and important)  

## [String `./docs/string.md`](./docs/string.md)
  - Reverse string  
  - Reverse string II  
  - Replace spaces  
  - Reverse words in a string  
  - Left rotate string  
  - String matching algorithms (important)  

## [Stack & Queue `./docs/stack_and_queue.md`](./docs/stack_and_queue.md)
  - Stack and queue basics  
  - Implement queue using stacks  
  - Implement stack using queues  
  - Valid parentheses  
  - Remove all adjacent duplicates in string  
  - Evaluate reverse Polish notation (important: postfix expressions)  
  - Sliding window maximum (important: monotonic queue)  
  - Top K frequent elements (important: heap)  

## [Binary Tree `./docs/binary_tree.md`](./docs/binary_tree.md)
  - Binary tree basics  
  - Recursive traversals  
  - Iterative traversals (important)  
    - Preorder and postorder traversal  
    - Inorder traversal  
  - Unified iterative traversal (harder to understand)  
    - Null-marker method  
    - Boolean-flag method  
  - Level-order traversal (important)  
    - Level order traversal  
    - Level order traversal II  
    - Right side view  
    - Average of levels  
    - N-ary tree level order traversal  
    - Find largest value in each tree row  
    - Populating next right pointers in each node  
    - Populating next right pointers in each node II  
    - Maximum depth of binary tree  
    - Minimum depth of binary tree  
  - Invert binary tree  
  - Symmetric tree  
    - Recursive method  
    - Iterative method  
    - Same tree  
    - Subtree of another tree  
  - Maximum depth of binary tree  
    - Maximum depth of N-ary tree  
  - Minimum depth of binary tree  
  - Minimum depth of binary tree (duplicate note)  
  - Count complete tree nodes  
  - Balanced binary tree  
  - All paths in binary tree (important: basic backtracking problem)  
    - Remember: one recursion call = one backtrack (pop)  
  - Sum of left leaves  
  - Find bottom-left tree value  
    - Level order method  
    - Recursive method (has tricky details)  
  - Path sum  
  - Construct binary tree from inorder and postorder traversal (important pattern)  
    - Idea and analysis  
    - Full implementation  
    - Optimization notes  
    - Construct binary tree from preorder and inorder traversal (important pattern)  
    - Can preorder + postorder determine a unique tree?  
  - Maximum binary tree  
  - Merge binary trees  
  - Search in BST  
  - Validate BST  
  - Minimum absolute difference in BST  
  - Mode(s) in BST  
  - Lowest common ancestor of binary tree (review needed)  
  - Lowest common ancestor of BST  
  - Insert into BST  
  - Delete node in BST (hard)  
    - Deletion in general binary trees  
  - Trim BST (review needed)  
    - Recursive method  
    - Iterative method (understand this approach)  
  - Convert sorted array to BST (can relate to AVL rotations)  
  - Convert BST to greater sum tree (reverse inorder traversal)  
  - **On July 24, 2025, reviewed binary tree topics and reorganized unfamiliar content into [binary_tree_review.md](./docs/binary_tree_review.md).**  

## [Backtracking `./docs/backtracking.md`](./docs/backtracking.md)
- Backtracking theory basics  
- Combination  
- Combination Sum III  
- Letter combinations of a phone number  
- Combination Sum  
- Combination Sum II  
- Palindrome partitioning (review needed)  
  - Optimization using DP array  
- Restore IP addresses  
- Subsets  
- Subsets II  
- Increasing subsequences (review needed)  
- Permutations  
- Permutations II  
- Reconstruct itinerary  
- N-Queens  
- Sudoku solver  

**Starting from Greedy to Dynamic Programming, the difficulty level increases — each problem must be understood deeply.**  

## [Greedy `./docs/greedy.md`](./docs/greedy.md)
- Greedy algorithm basics  
- Assign cookies  
- Wiggle subsequence  
- Maximum subarray sum  
- Best time to buy and sell stock II  
- Jump game  
- Jump game II  
- Maximize array sum after K negations  
- Gas station  
- Candy (review needed)  
- Lemonade change  
- **‼️ Greedy interval problems (follow the same thought process, review needed)**  
  - Queue reconstruction by height  
  - Minimum number of arrows to burst balloons  
  - Non-overlapping intervals  
  - Partition labels  
  - Merge intervals  
- Monotone increasing digits (review needed)  
- Binary tree cameras (state machine)  

## [Dynamic Programming `./docs/dp.md`](./docs/dp.md)
- DP section was tough — I went through it twice: [./docs/dp_again.md](./docs/dp_again.md)  
- Fibonacci numbers  
- Climbing stairs (can be extended to complete knapsack)  
- Min cost climbing stairs  
- Unique paths  
- Unique paths II  
- Integer break  
- Different BSTs  
- 0/1 Knapsack basics (review needed)  
  - 0/1 knapsack theory  
  - 0/1 knapsack optimized to rolling array  
- 0/1 Knapsack: determining if the bag can be filled  
  - Partition equal subset sum  
  - Last stone weight II  
- 0/1 Knapsack: counting number of ways to fill  
  - Target sum  
- Ones and zeros (review needed)  
- Complete knapsack basics  
  - 2D DP version  
  - 1D DP version (not covered yet)  
- Coin change II  
  - 2D DP version  
  - 1D DP version (important! many details, review‼️)  
    - The order of loops determines whether it’s combinations or permutations  
- Combination Sum IV  
- Climbing stairs (advanced version)  
- Coin change (my first self-solved knapsack variation! 👍)  
- Perfect squares (same idea as above)  
- Word break (review needed)  
- Multi-knapsack basics  
- Knapsack summary  
- House robber series  
  - House robber I  
  - House robber II (how to handle circular case)  
  - House robber III (DP on trees)  
- Stock trading series  
  - Best time to buy and sell stock I  
  - Best time to buy and sell stock II  
  - Best time to buy and sell stock III  
  - Best time to buy and sell stock IV  
  - Best time to buy and sell stock with transaction fee  
  - Best time to buy and sell stock with cooldown  
- Longest subsequence/subarray problems‼️  
  - Longest increasing subsequence  
  - Longest continuous increasing subsequence  
- Subsequence/subarray matching problems‼️  
  - Maximum length of repeated subarray  
  - Longest common subsequence  
  - Uncrossed lines  
- Maximum subarray sum  
- Edit distance series (hard‼️)  
  - Is subsequence  
  - Distinct subsequences  
  - Delete operation for two strings  
  - Edit distance  
- Palindromic problems  
  - Palindromic substrings  
  - Longest palindromic subsequence  

## [Monotonic Stack `./docs/monotonic_stack.md`](./docs/monotonic_stack.md)
- Introduction to monotonic stack  
- Daily temperatures  
- Next greater element I  
- Next greater element II  
- Trapping rain water (important)  
- Largest rectangle in histogram (important)  

## Graph Theory
- Graph theory is a huge topic that covers a wide range of algorithms. The current repository is already quite extensive, so I’ve decided to create a new dedicated repo to organize all graph-related algorithms.  
- Let’s conquer graph theory together: [Graphzilla](https://github.com/ffengc/Graphzilla)
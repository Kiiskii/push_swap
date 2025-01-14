# push_swap
The goal of this project was to use a sorting algorithm to arrange integers in ascending order. For maximum points—which I successfully achieved—the challenge was to sort 100 integers in fewer than 700 operations and 500 integers in fewer than 5,500 operations.

In this project, I implemented a form of insert sorting to sort integers into ascending order using two stacks. The project required using a specific set of operations to achieve this. These operations are:
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

I decided to go with this particular method of sorting, because the project wanted us to aim for low
operation counts with particularily 100 and 500 values. I thought that algorithms like radix- or
merge-sort would've required too complex optimizations to reach this result. If our goal was instead
to sort fast or have low operation counts at very high amounts of values, I would have gone with
these other algorithms.

## Algorithm

The algorithm begins by moving all but three values from stack A to stack B in descending order. These values are then pushed back to stack A in ascending order.

In simple terms:

1. Iterate through stack A to find the "cheapest" value to move and its target index in stack B.
2. Execute the necessary operations to place the value at the correct position on top of stack B. The "cheapest" value and its target are calculated by measuring their distances from the top of the stack (index 0), accounting for rotations that might bring them to the top from the bottom.
Once all but three values are in stack B (sorted in descending order), the remaining three values in stack A are sorted. Then, values are moved back to stack A:

1. Find the target index for the top value of stack B.
2. Rotate stack A so the target position is on top, and push the value from stack B.
3. Repeat until all values are back in stack A.
Finally, rotate stack A so the smallest value is at the top, completing the sorting process.

Below is a GIF demonstrating the sorting process. Credit for the creating the visualizer goes to
https://github.com/o-reo :
![push_swap](visualize_push_swap.gif)

## Improvement points

Overall, I am very satisfied with this project. It was enjoyable to complete and presented interesting challenges. However, I wish I had optimized the algorithm further to reduce the number of operations as much as possible.

## Bonus

I also completed the bonus portion of the project. For the bonus, I created a simple checker for my push_swap implementation (and others). The checker reads operations from standard output and executes them on a given array of integers. If the array is sorted correctly, it prints "OK" to the standard output; otherwise, it prints "KO."

You can use this checker with the main project, as push_swap outputs the operations it executes. Here's how to use it:
```bash
ARG="3 5 4 2 1 0 8 7 6"; ./push_swap $ARG | ./checker $ARG
```

## Usage

Clone the repository and compile using the included Makefile.

```bash
git clone https://github.com/Kiiskii/push_swap.git
cd push_swap
make
make bonus
make clean
```

To run the program

```bash
ARG="put numbers here"; ./push_swap $ARG
```
If you want to check operation count
```bash
ARG="put numbers here"; ./push_swap $ARG | wc -l
```

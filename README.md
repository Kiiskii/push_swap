# push_swap
In this project I used the "Turk" (insert) sorting algorithm to sort integers into ascending order
using two stacks. The instructions stated that we had to use a specific set of operations to make
this happen. These operations are:

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

## Key terms

- Stack: It is a data type that means that works so that you can only remove values from it from the
  top of a stack and add to the top of the stack. You can also rotate it, if needed.
- Target: The index in the other stack where the value belongs. For example when we are pushing
  values to B, we want to slot the value between a value that is greater and less than the one we
  want to push. 
- Cost: The amount of operations required to execute a move.
- Cheapest value: This is the value that requires the least operations to push to it's intended
  index in the other stack.
- Max & min: Largest and smallest values in a stack.
- Mid_a & mid_b: Middle index of each stack, rounded down if needed.

## Algorithm

The algorithm I used first sorts all but three values into stack B in descending order, and then
pushes them back to stack A.

To put it simply, I go through stack A, find the cheapest value to push and it's index, and then
execute the moves so that the value ends up in the correct position on top of stack B. I calculate
the cheapest value and it's target by checking the distance of the value and it's target from the
top of the other stack (index 0), while taking into account that they can reach the top by being
rotated there from the bottom of the stack.

Once all, but three values are in B sorted in descending order, I sort the tree remaining values in
A and start pushing everything back to A from the top of stack B. I find the target index of the top
value in B, rotate the target to the top of A and push. I repeat this until all values are back in
stack A. Finally I rotate the smallest value of A to the top and the sorting is complete.

Below is a GIF that shows visually how the sorting looks.

![push_swap](visualize_push_swap.gif)

# Elixir Functional Spiral Matrix Explanation

## The Paradigm Shift
In languages like C, C++, and Python, we built the spiral matrix by creating an empty grid and modifying it in place. We used a `while` loop to navigate the grid and updated boundaries (`top_row += 1`, etc.).

Elixir is **purely functional**. This means:
1. **No Loops:** You cannot use `for` or `while` loops that mutate variables.
2. **Immutability:** Once a variable is assigned a value, it can never be changed.

Because we cannot mutate a grid, we have to construct it from the ground up using **Recursion** and mathematical properties.

## The Mathematical Trick
A spiral matrix has a fascinating recursive property. If you take a standard spiral matrix and peel off the top row, the remaining numbers form another, smaller spiral matrix that has been rotated 90 degrees!

Consider a `3x3` matrix starting at `1`:
```text
1 2 3
8 9 4
7 6 5
```

If we separate the top row `[1, 2, 3]`, the remaining block is:
```text
8 9 4
7 6 5
```

If we rotate that block 90 degrees counter-clockwise, we get:
```text
4 5
9 6
8 7
```
Look closely: this is simply a `3x2` spiral matrix that starts at `4`!

This means any spiral matrix can be defined recursively:
**`Spiral Matrix = [Top Row] + Rotate_CCW(Smaller Spiral Matrix)`**

## How the Code Works

### 1. The Entry Point
```elixir
def matrix(0), do: []
def matrix(dimension) do
  build(dimension, dimension, 1)
end
```
We handle the edge case of a `0` dimension. Otherwise, we kick off our recursive `build` function, asking it to build an `N x N` matrix starting at the number `1`.

### 2. The Recursive Builder
```elixir
defp build(0, _, _), do: []
defp build(_, 0, _), do: []
defp build(rows, cols, start) do
  top_row = Enum.to_list(start..(start + cols - 1))
  rest = build(cols, rows - 1, start + cols)
  [top_row | rotate_ccw(rest)]
end
```
- **Base Cases:** If either dimension hits `0`, we return an empty list.
- **Top Row:** We create a list of numbers from our `start` to the width of our columns.
- **The Recursion:** We generate the `rest` of the matrix. Notice that the dimensions swap (`cols` becomes the new rows, and `rows - 1` becomes the new columns), and the start number increments appropriately.
- **The Combine:** `[top_row | rotated_rest]` is Elixir syntax for prepending an element (`top_row`) to the front of a list (the rotated rest).

### 3. The Rotation Helper
```elixir
defp rotate_ccw([]), do: []
defp rotate_ccw(matrix) do
  matrix
  |> Enum.zip()
  |> Enum.map(&Tuple.to_list/1)
  |> Enum.map(&Enum.reverse/1)
end
```
To rotate a matrix 90 degrees counter-clockwise functionally, you can transpose it and then reverse every row.
1. `Enum.zip()` takes our lists and transposes them (columns become rows), but groups them as Tuples.
2. `Enum.map(&Tuple.to_list/1)` loops through and converts those Tuples back into standard Lists.
3. `Enum.map(&Enum.reverse/1)` loops through and reverses the order of the numbers in each row.

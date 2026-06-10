defmodule Spiral do
  @doc """
  Given the dimension, return a square matrix of numbers in clockwise spiral order.
  """
  @spec matrix(dimension :: integer) :: list(list(integer))
  def matrix(0), do: []
  def matrix(dimension) do
    build(dimension, dimension, 1)
  end

  defp build(0, _, _), do: []
  defp build(_, 0, _), do: []
  defp build(rows, cols, start) do
    top_row = Enum.to_list(start..(start + cols - 1))
    rest = build(cols, rows - 1, start + cols)
    [top_row | rotate_ccw(rest)]
  end

  defp rotate_ccw([]), do: []
  defp rotate_ccw(matrix) do
    matrix
    |> Enum.zip()
    |> Enum.map(&Tuple.to_list/1)
    |> Enum.map(&Enum.reverse/1)
  end
end

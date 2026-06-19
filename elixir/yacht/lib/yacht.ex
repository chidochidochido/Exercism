defmodule Yacht do
  @type category ::
          :ones
          | :twos
          | :threes
          | :fours
          | :fives
          | :sixes
          | :full_house
          | :four_of_a_kind
          | :little_straight
          | :big_straight
          | :choice
          | :yacht

  @doc """
  Calculate the score of 5 dice using the given category's scoring method.
  """
  @spec score(category :: category(), dice :: [integer]) :: integer
  def score(:ones, dice), do: count_score(dice, 1)
  def score(:twos, dice), do: count_score(dice, 2)
  def score(:threes, dice), do: count_score(dice, 3)
  def score(:fours, dice), do: count_score(dice, 4)
  def score(:fives, dice), do: count_score(dice, 5)
  def score(:sixes, dice), do: count_score(dice, 6)

  def score(:choice, dice), do: Enum.sum(dice)

  def score(:yacht, dice) do
    if length(Enum.uniq(dice)) == 1, do: 50, else: 0
  end

  def score(:little_straight, dice) do
    if Enum.sort(dice) == [1, 2, 3, 4, 5], do: 30, else: 0
  end

  def score(:big_straight, dice) do
    if Enum.sort(dice) == [2, 3, 4, 5, 6], do: 30, else: 0
  end

  def score(:full_house, dice) do
    dice
    |> Enum.frequencies()
    |> Map.values()
    |> Enum.sort()
    |> case do
      [2, 3] -> Enum.sum(dice)
      _ -> 0
    end
  end

  def score(:four_of_a_kind, dice) do
    dice
    |> Enum.frequencies()
    |> Enum.find(fn {_face, count} -> count >= 4 end)
    |> case do
      {face, _count} -> face * 4
      nil -> 0
    end
  end

  defp count_score(dice, value) do
    value * Enum.count(dice, &(&1 == value))
  end
end

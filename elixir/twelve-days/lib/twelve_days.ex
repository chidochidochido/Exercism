defmodule TwelveDays do
  @doc """
  Given a `number`, return the song's verse for that specific day, including
  all gifts for previous days in the same line.
  """
  @spec verse(number :: integer) :: String.t()
  def verse(number) do
    intro = "On the #{day(number)} day of Christmas my true love gave to me: "

    gifts =
      number..1//-1
      |> Enum.map(fn n -> gift(n) end)
      |> Enum.join("")

    intro <> gifts
  end

  @doc """
  Given a `starting_verse` and an `ending_verse`, return the verses for each
  included day, one per line.
  """
  @spec verses(starting_verse :: integer, ending_verse :: integer) :: String.t()
  def verses(starting_verse, ending_verse) do
    starting_verse..ending_verse
    |> Enum.map(fn n -> verse(n) end)
    |> Enum.join("\n")
  end

  @doc """
  Sing all 12 verses, in order, one verse per line.
  """
  @spec sing() :: String.t()
  def sing do
    verses(1, 12)
  end

  defp day(1), do: "first"
  defp day(2), do: "second"
  defp day(3), do: "third"
  defp day(4), do: "fourth"
  defp day(5), do: "fifth"
  defp day(6), do: "sixth"
  defp day(7), do: "seventh"
  defp day(8), do: "eighth"
  defp day(9), do: "ninth"
  defp day(10), do: "tenth"
  defp day(11), do: "eleventh"
  defp day(12), do: "twelfth"

  defp gift(1), do: "a Partridge in a Pear Tree."
  defp gift(2), do: "two Turtle Doves, and "
  defp gift(3), do: "three French Hens, "
  defp gift(4), do: "four Calling Birds, "
  defp gift(5), do: "five Gold Rings, "
  defp gift(6), do: "six Geese-a-Laying, "
  defp gift(7), do: "seven Swans-a-Swimming, "
  defp gift(8), do: "eight Maids-a-Milking, "
  defp gift(9), do: "nine Ladies Dancing, "
  defp gift(10), do: "ten Lords-a-Leaping, "
  defp gift(11), do: "eleven Pipers Piping, "
  defp gift(12), do: "twelve Drummers Drumming, "
end

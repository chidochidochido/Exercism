defmodule Year do
  @doc """
  Returns whether 'year' is a leap year.

  A leap year occurs:

  on every year that is evenly divisible by 4
    except every year that is evenly divisible by 100
      unless the year is also evenly divisible by 400
  """
  @spec leap_year?(non_neg_integer) :: boolean
    # If the year is divisible by 400, it's definitely a leap year
    def leap_year?(year) when rem(year, 400) == 0, do: true

    # If it survived the above check but is divisible by 100, it is NOT a leap year
    def leap_year?(year) when rem(year, 100) == 0, do: false

    # If it survived both above checks and is divisible by 4, it IS a leap year
    def leap_year?(year) when rem(year, 4) == 0, do: true

    # If it failed all the above guard checks, it is definitely not a leap year.
    # (The underscore `_` tells Elixir we don't need to use the variable in the body)
    def leap_year?(_year), do: false
end

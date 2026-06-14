# The Leap Year Journey: A Multi-Language Retrospective

This document summarizes the lessons learned by implementing the exact same logical ruleset for Leap Years across five different programming languages. While the math never changed, the way each language allowed us to express that math highlighted their unique design philosophies.

## The Core Logic
A leap year occurs:
1. On every year that is evenly divisible by 4.
2. **Except** every year that is evenly divisible by 100.
3. **Unless** the year is also evenly divisible by 400.

---

## 1. C & C++: The "Shared Roots" Approach
Because C++ is built as an extension of C, the core primitive logic is 100% identical between the two languages. 

```c
return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
```
**What we learned:**
- Both languages use `&&` for AND and `||` for OR.
- While the internal logic was identical, C++ required us to wrap the function inside a `namespace` to prevent global naming collisions, showcasing C++'s focus on scalable architecture compared to C's simpler global scope.

## 2. Python: The "Expressive Readability" Approach
Python allowed us to tackle the problem in two distinct ways, both prioritizing human readability.

**The Nested Tree:**
```python
if input_year % 4 == 0:
    if input_year % 400 == 0:
        return True
    elif input_year % 100 == 0:
        return False
    else:
        return True
else:
    return False
```
**The One-Liner:**
```python
return (year % 4 == 0) and (year % 100 != 0 or year % 400 == 0)
```
**What we learned:**
- Python replaces symbolic operators (`&&`, `||`) with plain English words (`and`, `or`).
- Python's lack of brackets makes nested `if/elif/else` statements incredibly clean and easy to trace for beginners, though the one-liner remains the most compact.

## 3. Rust: The "Modern Idiomatic" Approach
Rust borrows heavily from C/C++ syntax, allowing us to reuse the exact same boolean string. However, it introduces a unique functional twist.

```rust
pub fn is_leap_year(year: u64) -> bool {
    (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)
}
```
**What we learned:**
- **Implicit Returns:** In idiomatic Rust, if the final line of a block does not end with a semicolon `;`, it is automatically treated as the return value. We were able to completely drop the `return` keyword and the semicolon, making the function incredibly clean.

## 4. Elixir: The "Purely Functional" Approach
Elixir forced us to drop our reliance on the `%` modulo operator and standard `if/else` logic, offering two distinct functional paths.

**Approach 1: The Classic One-Liner**
```elixir
def leap_year?(year) do
  rem(year, 4) == 0 and (rem(year, 100) != 0 or rem(year, 400) == 0)
end
```
*We learned that Elixir uses the built-in `rem()` function for remainders instead of the `%` symbol, and uses standard `and/or` boolean operators.*

**Approach 2: Idiomatic Guard Clauses (The Elixir Way)**
```elixir
def leap_year?(year) when rem(year, 400) == 0, do: true
def leap_year?(year) when rem(year, 100) == 0, do: false
def leap_year?(year) when rem(year, 4) == 0, do: true
def leap_year?(_year), do: false
```
**What we learned:**
- **Function Clauses & Guards:** Instead of putting an `if/else` statement inside a function, Elixir allows us to define the *same function* multiple times. 
- The program evaluates them from top-to-bottom using `when` guards. If a condition is met, it executes that specific function body and skips the rest.
- This creates code that reads almost exactly like the plain-English business rules defined at the top of this document!

---

**Final Thought:** 
While the "Spiral Matrix" problem taught us how languages manage memory and loops, the "Leap" problem taught us how languages handle basic control flow and expressiveness. It showed the evolution from symbolic math (C/C++) to English readability (Python), to implicit functional returns (Rust), and finally to declarative guard clauses (Elixir).

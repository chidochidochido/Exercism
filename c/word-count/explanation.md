# Word Count Exercise Explanation

This document provides a thorough explanation of the logic and implementation for the **Word Count** exercise in C. The goal is not just to provide the answer, but to help you understand the concepts and the thought process behind the solution.

## 1. Understanding the Requirements
Before writing the code, we must clearly define what the problem is asking for. The primary goal is to count how many times each word occurs in a sentence, with the following constraints:
- **What is a word?** Numbers and letters form words.
- **Case-Insensitivity:** "Word" and "word" should be counted as the same.
- **Punctuation:** Most punctuation separates words. However, apostrophes inside a word (like contractions e.g., `can't`, `you're`) are valid word characters. Quotes enclosing a word (like `'large'`) are punctuation and should be stripped.
- **Constraints:** Maximum word length is defined by `MAX_WORD_LENGTH` (50) and the maximum number of unique words is `MAX_WORDS` (20).

## 2. Breaking Down the Solution

Instead of complex string tokenization functions like `strtok` (which modifies the original string and can be tricky with complex punctuation rules), a robust approach is to iterate through the sentence character by character and build words manually. This is called a **state-machine** or **character-by-character parsing** approach.

### Step 2.1: Iterating and Identifying Word Characters
We use a loop to examine every character in the string:
```c
for (int i = 0; ; i++) {
    char c = sentence[i];
    // ...
```

The core of our logic revolves around identifying if a character belongs to a word.
- Standard alphanumeric characters (`a-z`, `A-Z`, `0-9`) are always part of a word. We can check this using the `isalnum()` function from `<ctype.h>`.
- The tricky part is the **apostrophe**. It's only part of a word if it acts as a contraction. To verify this, we check if the characters immediately preceding and following the apostrophe are both alphanumeric. If they are, it's a contraction; otherwise, it's just punctuation (like single quotes).

```c
bool is_word_char = false;
if (isalnum((unsigned char)c)) {
    is_word_char = true;
} else if (c == '\'') {
    // Check boundaries to avoid accessing out of bounds
    char prev = i > 0 ? sentence[i-1] : '\0';
    char next = sentence[i+1];
    
    if (isalnum((unsigned char)prev) && isalnum((unsigned char)next)) {
        is_word_char = true; // It's a contraction!
    }
}
```

### Step 2.2: Building the Word
If we identify a valid word character, we add it to our temporary `current_word` buffer. We also convert it to lowercase simultaneously using `tolower()`.

```c
if (is_word_char) {
    if (len < MAX_WORD_LENGTH) {
        current_word[len++] = tolower((unsigned char)c);
    } else {
        // We've exceeded the length boundary!
        return EXCESSIVE_LENGTH_WORD;
    }
}
```

### Step 2.3: Processing a Complete Word
If the current character is **not** a word character (e.g., a space, a comma, or an invalid apostrophe), it signals the *end* of the word we were building. 

We only process the word if our length `len` is greater than 0. 

```c
else {
    if (len > 0) {
        // Null-terminate the string to make it a valid C-string
        current_word[len] = '\0';
        
        // ... Logic to store/count the word ...
        
        // Reset the length to 0 to start building the next word
        len = 0;
    }
}
```

### Step 2.4: Counting and Storing Words
Once a word is complete, we check if it already exists in our `words` array.
- We loop through the currently stored `unique_words`.
- We use `strcmp()` from `<string.h>` to compare strings. 
- If we find a match, we simply increment the `count` for that word.

If the word isn't found, we need to add it:
- First, we verify we haven't reached the limit `MAX_WORDS`.
- If there's room, we copy the `current_word` to `words[unique_words].text` using `strcpy()`.
- We initialize its `count` to `1` and increment our `unique_words` tracker.

### Step 2.5: Loop Termination
The `for` loop continues until it processes the null-terminator (`\0`), which signifies the end of the `sentence`.

```c
if (c == '\0') {
    break;
}
```

## Summary of Key C Functions Used
- `isalnum(int c)`: Checks if a character is alphanumeric (a letter or a number).
- `tolower(int c)`: Converts an uppercase letter to lowercase.
- `strcmp(const char *str1, const char *str2)`: Compares two strings. Returns `0` if they are identical.
- `strcpy(char *dest, const char *src)`: Copies a string from `src` to `dest`.

This solution effectively manages edge cases cleanly without relying on complex substring extraction or temporary allocations, keeping the execution fast and memory usage strictly bounded.

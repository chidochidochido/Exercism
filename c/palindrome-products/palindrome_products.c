#include "palindrome_products.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Helper to check if a number is a palindrome mathematically
static bool is_palindrome(int n)
{
    if (n < 0) return false;
    int reversed = 0;
    int original = n;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

// Helper to add a factor pair to a linked list
static factor_t *add_factor(factor_t *head, int a, int b)
{
    // Ensure smaller factor is first for consistency
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // Check for duplicates
    factor_t *curr = head;
    while (curr != NULL)
    {
        if (curr->factor_a == a && curr->factor_b == b)
        {
            return head; // Already in the list
        }
        curr = curr->next;
    }

    // Allocate new node
    factor_t *new_node = malloc(sizeof(factor_t));
    if (!new_node) return head;

    new_node->factor_a = a;
    new_node->factor_b = b;
    new_node->next = head; // Prepend to the list
    return new_node;
}

// Helper to free a linked list of factors
static void free_factors(factor_t *f)
{
    while (f != NULL)
    {
        factor_t *next = f->next;
        free(f);
        f = next;
    }
}

product_t *get_palindrome_product(int from, int to)
{
    // Allocate memory for the result on the heap
    product_t *res = malloc(sizeof(product_t));
    if (!res) return NULL;

    res->smallest = 0;
    res->largest = 0;
    res->factors_sm = NULL;
    res->factors_lg = NULL;
    memset(res->error, 0, sizeof(res->error));

    // Handle invalid range
    if (from > to)
    {
        snprintf(res->error, MAXERR, "invalid input: min is %d and max is %d", from, to);
        return res;
    }

    bool found = false;

    for (int i = from; i <= to; ++i)
    {
        // Start j from i to avoid checking permutations like (i, j) and (j, i)
        for (int j = i; j <= to; ++j)
        {
            int prod = i * j;

            if (is_palindrome(prod))
            {
                if (!found)
                {
                    // First palindrome found
                    res->smallest = prod;
                    res->largest = prod;
                    res->factors_sm = add_factor(NULL, i, j);
                    res->factors_lg = add_factor(NULL, i, j);
                    found = true;
                }
                else
                {
                    // Check if it's the new smallest or same as smallest
                    if (prod < res->smallest)
                    {
                        res->smallest = prod;
                        free_factors(res->factors_sm);
                        res->factors_sm = add_factor(NULL, i, j);
                    }
                    else if (prod == res->smallest)
                    {
                        res->factors_sm = add_factor(res->factors_sm, i, j);
                    }

                    // Check if it's the new largest or same as largest
                    if (prod > res->largest)
                    {
                        res->largest = prod;
                        free_factors(res->factors_lg);
                        res->factors_lg = add_factor(NULL, i, j);
                    }
                    else if (prod == res->largest)
                    {
                        res->factors_lg = add_factor(res->factors_lg, i, j);
                    }
                }
            }
        }
    }

    // Handle case where no palindrome is found in the range
    if (!found)
    {
        snprintf(res->error, MAXERR, "no palindrome with factors in the range %d to %d", from, to);
    }

    return res;
}

void free_product(product_t *p)
{
    if (p != NULL)
    {
        free_factors(p->factors_sm);
        free_factors(p->factors_lg);
        free(p);
    }
}
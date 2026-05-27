#include "palindrome_products.h"
#include <stdbool.h>
#include <stdlib.h>

#define SMALLER false
#define LARGER  true

// Given a range of numbers, find the largest and smallest palindromes which
// are products of two numbers within that range.

// Your solution should return the largest and smallest palindromes, along with the factors of each within the range.
// If the largest or smallest palindrome has more than one pair of factors within the range, then return all the pairs.

// Plan:
// Find out the product.
// Check if whether the product is a palyndrome.

// If yes, then check if it is either the smallest or the largest.
// If yes, then store the factors (store in a stack)
// Replace the maximum/minimum value accordingly
static bool is_palindrome(int);
static void initializeProductInfo(product_t *, int from, int to);

product_t *get_palindrome_product(int from, int to)
{
    int i_product;
    product_t s_productInfo;

    initializeProductInfo(&s_productInfo);
    
    for(int i = from; i <= to; i++)
    {
        for(int j = from; j <= to; j++)
        {
            // Find out the product.
            i_product = i*j;
            
            // Check if whether the product is a palyndrome.
            if(is_palindrome(i_product))
            {
                // If yes, then check if it is either the smallest or the largest.
                if(i_product < s_productInfo.smallest)
                {
                    free_product(&s_productInfo);
                    s_productInfo.smallest = i_product;
                    pushFactors(&s_productInfo, to, from, SMALLER);
                }
                else if(i_product == s_productInfo.smallest)
                {
                    pushFactors(&s_productInfo, to, from, SMALLER);
                }
                else if(i_product == s_productInfo.largest)
                {
                    pushFactors(&s_productInfo, to, from, LARGER);
                }
                else if(i_product > s_productInfo.largest)
                {
                    free_product(&s_productInfo);
                    s_productInfo.largest = i_product;
                    pushFactors(&s_productInfo, to, from, LARGER);
                }
                
            }
        }
    }

    return 0;
}

static void initializeProductInfo(product_t* ps_productInfo)
{
    ps_productInfo->largest = -1;
    ps_productInfo->smallest = -1;
    ps_productInfo->factors_lg = NULL;
    ps_productInfo->factors_sm = NULL;

}

static bool is_palindrome(int product)
{
     // Convert the product to a string
    char str_product[20]; // Assuming the product won't exceed 20 digits
    snprintf(str_product, sizeof(str_product), "%d", product);

    // Check if the string is a palindrome
    int len = strlen(str_product);
    for (int i = 0; i < len / 2; i++) {
        if (str_product[i] != str_product[len - 1 - i]) {
            return false; // Not a palindrome
        }
    }
    return true; // Is a palindrome
}

static pushFactors(product_t *s_productInfo, int to, int from, bool sm_lg)
{
    
    
    if(sm_lg == SMALLER)
    {
        s_productInfo->factors_lg = 
    }
    else
    {

    }
}

void free_product(product_t *p)
{
    p->largest = -1;
    p->smallest = -1;
    p->factors_lg = NULL;
    p->factors_sm = NULL;
}
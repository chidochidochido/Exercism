#include "high_scores.h"
/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len)
{
    return scores[scores_len - 1];
}
/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    int32_t largest = 0;

    for(size_t i = 0; i < scores_len; i++)
    {
        if(scores[i] > largest)
        {
            largest = scores[i];
        }
    }

    return largest;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{
    size_t count = 0u;

    for(size_t i = 0u; i < scores_len; i++)
    {
        if(scores[i] >= output[0])
        {
            output[2] = output[1];
            output[1] = output[0];
            output[0] = scores[i];
        }
        else if(scores[i] >= output[1])
        {
            output[2] = output[1];
            output[1] = scores[i];
        }
        else if(scores[i] >= output[2])
        {
            output[2] = scores[i];
        }
    }

    for(size_t i = 0u; i < 3; i++)
    {
        if(output[i] != 0)
        {
            count++;
        }
    }

    return count;
}
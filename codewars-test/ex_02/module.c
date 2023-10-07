// ----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

// ----------------------------------------------------------------------------

#define LETTER_NUM 25
#define CAPITAL_INIT 65
#define CAPITAL_END (CAPITAL_INIT + LETTER_NUM)
#define LOWER_INIT 97
#define LOWER_END (LOWER_INIT + LETTER_NUM)

// ----------------------------------------------------------------------------

size_t get_letter_pos(unsigned char c);
size_t get_output_string_size(const char *text);

// ----------------------------------------------------------------------------

size_t get_letter_pos(unsigned char c)
{
    size_t pos = 0;

    do {
        if ((c >= CAPITAL_INIT) && (c <=CAPITAL_END))
        {
            pos = c - CAPITAL_INIT + 1;
            break;
        }

        if ((c >= LOWER_INIT) && (c <=LOWER_END))
        {
            pos = c - LOWER_INIT + 1;
            break;
        }
    } while (0);

    return pos;
}

size_t get_output_string_size(const char *text)
{
    size_t chr_cnt = 0;
    const char *pchar=text;

    // Scan all chars and count letters
    while (*pchar != 0)
    {
        size_t pos = get_letter_pos(*pchar++);

        if (pos != 0)
        {
            if (pos < 10)
            {
                chr_cnt += 2;
            }
            else
            {
                chr_cnt += 3;
            }
        }
    }

    return chr_cnt;
}

// ----------------------------------------------------------------------------

// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text)
{  
    char *result_str = NULL;
    size_t size_output = get_output_string_size(text);

    do {
        result_str = (char *)malloc(size_output);
        if (result_str == NULL)
        {
            break;
        }

        const char *pchar=text;
        size_t write_index = 0;
        while (*pchar != 0)
        {
            size_t chr_pos = get_letter_pos(*pchar++);

            if (chr_pos != 0)
            {
                write_index += snprintf(&result_str[write_index], size_output - write_index, "%lu ", chr_pos);
            }
        }
    } while (0);

    return result_str;
}

// EOF

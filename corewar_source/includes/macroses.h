#ifndef COREWAR_SOURCE_MACROSES_H
# define COREWAR_SOURCE_MACROSES_H

# define STR_HELPER(x) #x
# define STR(x) STR_HELPER(x)

# define CONCAT_STR_WITH_NBR(str, nbr) str STR(nbr)
# define CONCAT_STR_WITH_STR(str1, str2) str1 str2

# define INDEX(X) ((X) - 1)

#endif

#include <llib/llib_io.h>

/**
 * @brief Clears the standard input buffer by discarding
 * every character until a '\n' or EOF is detected
 */
void clearInBuf(void)
{
    int c;
    while((c = getchar()) != EOF && c != '\n');
    return;
}

/**
 * @brief Reads input from standard input based on the specified format and stores it at the provided address.
 *
 * @param format The format string for reading input.
 * @param address Pointer to the memory location where the input will be stored.
 *
 * @return The number of input items successfully matched and assigned.
 */
int input(const char* format, void* address)
{
    int result = scanf(format, address);
    clearInBuf();

    return result;
}
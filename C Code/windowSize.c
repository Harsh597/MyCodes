// The code for resizing the console window is given below

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#define _WIN32_WINNT 0x0500

HANDLE wHnd; // Handle to write to the console.
HANDLE rHnd; // Handle to read from the console.
int main(int argc, char *argv[])
{
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("Advanced C tutorial - programming-technique.blogspot.com");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, 65, 35};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
    // Create a COORD to hold the buffer size:
    //  COORD bufferSize = {50, 50};
    //SetConsoleScreenBufferSize(wHnd, bufferSize);

    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(wHnd, &info);
    COORD new_size =
        {
            info.srWindow.Right - info.srWindow.Left + 1,
            info.srWindow.Bottom - info.srWindow.Top + 1};
    SetConsoleScreenBufferSize(wHnd, new_size);
    // Exit
    // for (int i = 0; i < 55; i++)
    // {
    for (int j = 1; j <= 41; j++)
        printf("\n*");
    //     printf("\n");
    // }
    getch();
    getch();

    return 0;
}
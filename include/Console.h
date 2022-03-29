#pragma once
#include <windows.h>

/// <summary>
/// Class for working with the windows console
/// </summary>
class Console {

#pragma region Private

private:
    static inline HANDLE console_ = GetStdHandle(STD_OUTPUT_HANDLE);

#pragma endregion

#pragma region Public

public:
    
    #pragma region setCursorPos
    
    /// <summary> 
    /// Set cursor position by coordinates
    /// </summary>
    /// <param name="x"> coord </param>
    /// <param name="y"> coord </param>
    static void setCursorPos(int, int);

    static void setCursorPos(COORD);

    #pragma endregion

    /// <summary>
    /// Turns off cursor display
    /// </summary>
    static void offCursorVisability();
    
    /// <summary>
    /// Sets the console font for correct display
    /// </summary>
    static void setFont();

    /// <summary>
    /// Starts initial console setup
    /// </summary>
    static void setup();

    /// <summary>
    /// Sets the cursor color
    /// </summary>
    /// <param name="Color">For example ColorManager::Color.Black</param>
    static void setColor(int);

#pragma endregion

};
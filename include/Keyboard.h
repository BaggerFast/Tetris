#pragma once
#include <vector>

/// <summary>
/// Class for working with the keyboard
/// </summary>
class Keyboard {

#pragma region Public

public:
    static inline std::vector<int>
        W = { 119, 246 },
        A = { 97, 244 },
        S = { 115, 251 },
        D = { 100, 226 },
        SPACE = { 32 };

    /// <summary>
    /// Has a key from the sequence been pressed?
    /// </summary>
    /// <param name="keys"> The sequence of necessary keys. Example:Keyboard::W </param>
    /// <param name="keyCode"> Keycode of the pressed key </param>
    /// <returns> Was a key from the sequence pressed </returns>
    static bool parseKeys(std::vector<int>, int);

#pragma endregion

};

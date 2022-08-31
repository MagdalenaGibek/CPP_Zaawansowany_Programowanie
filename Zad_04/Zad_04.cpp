#include <iostream>
#include"MorseCodeTranslatorClass.hpp"

int main()
{
    MorseCodeTranslator textToTranslate;
    std::string latinText = "Ala ma 2 koty";
    std::cout << "Tekst w alfabecie łacińskim: " << latinText << std::endl;
    std::cout << "Tekst w alfabrcie Morse'a: " << textToTranslate.toMorseCode(latinText) << std::endl;
    std::string morseText = ".- .-.. .- -- .- ..--- -.- --- - -.--";
    std::cout << "Tekst w alfabecie Morse'a: " << morseText << std::endl;
    std::cout << "Tekst w alfabrcie łacińskim: " << textToTranslate.fromMorseCode(morseText) << std::endl;
}



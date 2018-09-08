#include "Cipher.hpp"

int main(int argc, char* argv[])
{
    Enigma ThreeRotorEnigma(1,2,3, "AAA");
    std::string TestMessage = "GATOS";
    ThreeRotorEnigma.ModifieAlphabets("D","W","A");
    std::cout << TestMessage << "\n";
    TestMessage = ThreeRotorEnigma.Encrypt(TestMessage);
    std::cout << TestMessage << "\n";
    return 0;
}

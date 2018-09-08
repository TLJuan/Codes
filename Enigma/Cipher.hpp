//  Libraries
#include <iostream>
#include <string>
#include <exception>
//
class Alphabets
{
public:
    //enum Types  {Reflector = 0,Rotor_I, Rotor_II, Rotor_III};
    std::string GenericAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string Reflector =       "YRUHQSLDPXNGOKMIEBFZCWVIAT";
    std::string Rotor_I =         "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    std::string Rotor_II =        "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    std::string Rotor_III =       "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    std::string Rotor_IV=         "ESOVPZJAYQUIRHXLNFTGKDCMWB";
    std::string Rotor_V=          "VZBRGITYUPSDNHLXAWMJQOFECK";
    std::string Rotor_VI=         "JPGVOUMFYQBENHZRDKASXLICTW";
    std::string Rotor_VII=        "NZJHGRCXMYSWBOUFAIVLPEKQDT";
};

class Mechanism: public Alphabets
{
    int Position;   //Initial Position in the Alphabet
    bool Direction; //Sets the rule, Left to Right or vice-versa
    int Class;
public:
    std::string Alphabet;
    Mechanism(int);
    Mechanism();
    void setPosition(int);
    void setDirection(bool);
    void SetAlphabet(int);
    void RotateRotor();
};

class Enigma
{
    std::string Key = "AAA";
    Mechanism A,B,C,M_Alpha,M_Reflector;
public:
    Enigma();
    void setKey(std::string);
    std::string Encrypt(std::string);   //Encrypts the message
    std::string Decrypt(std::string);   //Decrypts the message
    Enigma(int , int , int , std::string);           //Number of Rotors to use
    void ModifieAlphabets(std::string = "A",std::string = "A",std::string = "A");
};

int Mod(int,int);
std::string Shift(std::string );

#include "Cipher.hpp"

//Auxiliary  Functions
    // Modulus
    int Mod(int a, int n)
    {
        if(n == 0)
            throw "Division by zero!\n";
        if(a>=0){
        if(a<n){return a;}
        return a-(n*(a/n));
            }
        int c=a-(n*(a/n));
        if(c==0)
            return c;
        return a-n*(a/n-1);
    }

    //Shifter
    std::string Shift( std::string Text, int a)
    {
        int TSize = Text.size();
        for(int n = 0; n < a;n++)
        {
            Text[TSize] = Text[0];
            for (int i = 0; i < TSize; i++)
            {
                Text[i] = Text[i + 1];
            }
        }
        //
        return Text;
    }
// Rotor
Mechanism::Mechanism(int Type)
{
    Class = Type;
}

Mechanism::Mechanism()
{
    Class = 0;
}

void Mechanism::setPosition(int Position)
{
    this->Position = Position;
}

void Mechanism::setDirection(bool Direction)
{
    this->Direction = Direction;
}

void Mechanism::SetAlphabet( int i)
{
    switch(i)
    {
        case 9:
            this->Alphabet = GenericAlphabet;
        case 0:
            this->Alphabet = Reflector;
        case 1:
            this->Alphabet = Rotor_I;
        case 2:
            this->Alphabet = Rotor_II;
        case 3:
            this->Alphabet = Rotor_III;
        case 4:
            this->Alphabet = Rotor_IV;
        case 5:
            this->Alphabet = Rotor_V;
        case 6:
            this->Alphabet = Rotor_VI;
        case 7:
            this->Alphabet = Rotor_VII;
        //default:
          //  Alphabet = GenericAlphabet;
    }
}


// Enigma
Enigma::Enigma()
{
    A.SetAlphabet(1);
    B.SetAlphabet(2);
    C.SetAlphabet(3);
    M_Alpha.SetAlphabet(9);
    M_Reflector.SetAlphabet(0);
}

void Enigma::ModifieAlphabets(std::string  a,std::string b,std::string c)
{
    int q;
    q = A.GenericAlphabet.find(a);
    A.GenericAlphabet = Shift(A.GenericAlphabet,q);

    q = B.GenericAlphabet.find(b);
    B.GenericAlphabet = Shift(B.GenericAlphabet,q);

    q = C.GenericAlphabet.find(c);
    C.GenericAlphabet = Shift(C.GenericAlphabet,q);
    return;
}

Enigma::Enigma(int RotorA, int RotorB, int RotorC, std::string key )
{
    Key = key;
    A.SetAlphabet(RotorA);
    B.SetAlphabet(RotorB);
    C.SetAlphabet(RotorC);
    M_Alpha.SetAlphabet(9);
    M_Reflector.SetAlphabet(0);

}

void Enigma::setKey(std::string NewKey)
{
    if(NewKey.size() > 3)
        return;
    Key = NewKey;
}

std::string Enigma::Encrypt(std::string Message)
{
    int letter = 0;
    int InAlpha = 1;
    while( letter < Message.size())
    {
        int a;
        a = C.GenericAlphabet.find(Message[letter]) + Mod(InAlpha,C.GenericAlphabet.size());//1;
        Message[letter] = C.Rotor_III[a];
     {
        std::cout <<"Alp " <<M_Alpha.GenericAlphabet << std::endl;
        std::cout <<"Ref " <<M_Reflector.Reflector << std::endl;
        std::cout <<"Rotor 3 " <<C.Rotor_III << std::endl;
        std::cout <<"Rotor 3 AA " <<C.GenericAlphabet << std::endl;
        std::cout <<"Rotor 2 " <<B.Rotor_II << std::endl;
        std::cout <<"Rotor 2 AA " <<B.GenericAlphabet << std::endl;
        std::cout <<"Rotor 1 " <<A.Rotor_I << std::endl;
        std::cout <<"Rotor 1 AA " <<A.GenericAlphabet << std::endl;
    }
        a = B.GenericAlphabet.find(Message[letter])-Mod(InAlpha,C.GenericAlphabet.size());
        Message[letter] = B.Rotor_II[a];
        a = A.GenericAlphabet.find(Message[letter]);
        Message[letter] = A.Rotor_I[a];
        if(Message[letter] == Key[0])
            //

        //Reflector
        a = M_Reflector.GenericAlphabet.find(Message[letter]);
        Message[letter] = M_Reflector.Reflector[a];
        //Return
        a = A.Rotor_I.find(Message[letter]);
        Message[letter] = A.GenericAlphabet[a];
        a = B.Rotor_II.find(Message[letter]);
        Message[letter] = B.GenericAlphabet[a];
        //Last Step
        a = C.GenericAlphabet.find(Message[letter])+Mod(InAlpha,C.GenericAlphabet.size());

        Message[letter] = M_Alpha.GenericAlphabet[a];
        a = C.Rotor_III.find(Message[letter])-Mod(InAlpha,C.Rotor_III.size());//1;
        Message[letter] = M_Alpha.GenericAlphabet[a];
        std::cout <<"Rotor 3 " <<Message[letter] << std::endl;
        letter++;
        InAlpha++;
    }
   return Message;
}

std::string Enigma::Decrypt(std::string Message)
{
    return Message;
}


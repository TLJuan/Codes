#include <iostream>
#include <string>

std::string Upper = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";
std::string Lower = "abcdefghijklmnopqrstuvwxyz_";

std::string Alpha_inv_str( std::string &txt )
{
    for(int i = 0; i < txt.length() ; ++i)
    {
        std::string tmp = txt;
        for(int j = 0; j < Upper.length() ; j++)
        {
            if (tmp[i] == Upper[j])
            {
                //std::cout << j << " ";
                tmp[i] = Upper[ Upper.length() - j  -1 ];
                txt[i] = tmp[i];
                break;
            }
        }
    }
    return txt;
}

std::string Transpose_Alpha(std::string txt, int key = 3) // Aka Rail Fence Crypto
{
    std::string new_str = "";
    int limits = (key-1)*2;
    //
    for(int i = 0; i < key; i++ )
    {
        int current;// = (key - 1 - i)*2;
        int counter = 0;

        for(int j = i; j < txt.length(); j = j + current )
        {
            if( (i == 0) || (i == key - 1) )
            {
                current = limits;
                new_str += txt[j];
            }
            else
            {
                if( counter%2 != 0 )
                {
                    current = limits - current;
                }
                else
                {
                    current = 2*(key - 1 - i);
                }
                new_str += txt[j];
            }
            //std::cout<< j << " ";
            counter++;
        }
    }
    return new_str;
}

std::string Decrypt_Transpose_Alpha(std::string txt, int key = 3 ) // Rail Fence Decryption
{
    std::string new_str = "";

    for(int i = 0; i < txt.length(); i++)
    {
        new_str+= "0";
    }
    int letter = 0;
    int limits = (key-1)*2;
    for(int i = 0; i < key; i++ )
    {
        int current;// = (key - 1 - i)*2;
        int counter = 0;

        for(int j = i; j < txt.length(); j = j + current )
        {
            if( (i == 0) || (i == key - 1) )
            {
                current = limits;
                new_str[j] = txt[letter];
            }
            else
            {
                if( counter%2 != 0 )
                {
                    current = limits - current;
                }
                else
                {
                    current = 2*(key - 1 - i);
                }
                new_str[j] = txt[letter];
            }
            //std::cout<< j << " ";
            counter++;
            letter++;
        }
    }
    return new_str;
}

// ____ ____ ____ ____ ____ ____ ____ ____ ____ //

std::string Encryption_Matrix_01(std::string txt, int key) // Spiral Matrix 1
{
    std::string new_str = "";
    int First = (key -1)*3;
    int current, anchor = -5;
    int formula = anchor - key;
    int aux = 2*(First - 1) + formula; // pos[1][1]

    for( int i = 0; i< key-1; i++)
    {
        for( int j = 0; j < key - 1; j++)
        {
            if ((j == 0))
            {
                current = First - i;
                new_str += txt[current];
            }
            else if(j == key-1 )
            {
                //
                new_str += txt[0 + i];
            }
            else
            {
                if( i == key-1)
                {
                    current = current -1;
                    new_str = txt[current];
                }
                else if( i == 0)
                {
                  current = current +1;
                  new_str += txt[current];
                  if(j == key -1)
                  {
                      new_str += txt[i];
                  }
                }
                else
                {
                    if( j == key -1)
                    {
                        new_str += txt[i];
                    }
                    //

                }
            }
        }//End for with j
    }//End for with i
}

std::string Encryption_Matrix_02(std::string txt, int key);
std::string Encryption_Matrix_03(std::string txt, int key);
std::string Encryption_Matrix_04(std::string txt, int key);


// ____ ____ ____ ____ ____ ____ ____ ____ ____ //

int main()
{

    std::string n5 ="Mensaje DE texto de Prueba, Plain Text del alumno, Juan Gabriel con codigo de alumno 171-10-39707. ";
    n5 = Transpose_Alpha(n5, 6 );
    std::cout << n5 <<std::endl;
    n5 = Decrypt_Transpose_Alpha(n5,6);
    std::cout << n5<<std::endl;
    std::cout << std::endl;

/*
    //001 Arturo
    std::string ns ="v5Z8Z555pW Wa15W.NZ__VN.NVNVtNTZN95ZgeN_NNUW5NNVNP9mUALUNZSSVkhYN5P1Y,.5Z8NVV9NEWJ791mjcTVVN5N9ZV1_ZN9NZIMZ1Wwiin55Um.VV7Y7977VU6 N,.WNckx6Z5N9.ZZn5Zix";
    std::cout << ns <<std::endl;
    ns = Decrypt_Transpose_Alpha(ns,7);
    ns = Alpha_inv_str(ns);
    std::cout << ns<<std::endl;
    std::cout << std::endl;
    //002 Jorge Luis
    std::string n2 ="u,W37h WNZU9W5.9cj T..5_ZN9NNa ,TZ,_DBTAmb YNNN5NTF91j NV7.Um1N,.c5Z9V9e";
    std::cout << n2 <<std::endl;
    n2 = Decrypt_Transpose_Alpha(n2,7);
    //std::cout << ns<<std::endl;;
    n2 = Alpha_inv_str(n2);
    std::cout << n2<<std::endl;
    std::cout << std::endl;
    //003 Luis Fernando
    std::string n3 ="tKNH93b5NZ.N9.yN5Y71ZjN6N9P1.16U99VWTN6Nc4N11N7NS9Zv81.uBZia96.W79K56_N_T9N97cg7935ZUKW119ZB.ZONijTU51,TzyV7N6Zi_.YA";
    std::cout << n3 <<std::endl;
    n3 = Decrypt_Transpose_Alpha(n3,7);
    //std::cout << ns<<std::endl;;
    n3 = Alpha_inv_str(n3);
    std::cout << n3<<std::endl;
    std::cout << std::endl;
    //004
    std::string n4 ="_N515.m19mUNU5wZVXVNWOVWN9UNUS.N9NZW.A1ZWOwwVZTN759NNVWZ6YZT212NZ99uNWwwwNU5P9U.WUZWS51VN1W5mV1.NG5wwwUQN9W7NZ5U91VWN5VZ7ZNWT_T1www529YQU7JU2L5Uww";
    std::cout << n4 <<std::endl;
    n4 = Decrypt_Transpose_Alpha(n4,7);
    //std::cout << ns<<std::endl;;
    n4 = Alpha_inv_str(n4);
    std::cout << n4<<std::endl;
    std::cout << std::endl;
    //005
    std::string n5 ="AWZmN3759W,WNc5yT6N5NmK_59UUQ8NZNT.81Z6ii.N59w7Me_M8W9NU55Y5_Z9535NkcV58W9.Ti9NWUm.NT.N_MNG_1NZij969415_fVV9VN16WSZNNDNm69.jc0NN1_H9 55N8y95Y166_T.NZ_,ka57NNNM_N9597Tg";
    std::cout << n5 <<std::endl;
    n5 = Decrypt_Transpose_Alpha(n5,7);
    n5 = Alpha_inv_str(n5);
    std::cout << n5<<std::endl;
    std::cout << std::endl;
*/
    return 0;
}

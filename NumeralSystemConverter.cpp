#include <iostream>
using namespace std;

int main()
{

    while (1)
    {
        // flag to check if there is an error
        bool ifError = 0;


        // 2 Arrays of characters for input & output
        char no[100], out[100] = {0};

        // variable x to store fractional number (After the point)
        double x = 0;

        // variable y to store integer number (Before the point)
        unsigned long long y = 0;

        // flag to check if the number(no[]) contains point
        bool if_point = 0;


        cout << "Enter the base of your input (2 - 36), enter '#' to finish\n";

        // variable to take the base that user will enter
        int inbase = 0;
        char base_char[3];

        int lm = 0;
        for(lm = 0; lm < 3; lm++)
        {
            cin >> base_char[lm];
            if(base_char[lm] == '#')
                break;
        }
        if(lm == 1)
        {
            inbase = base_char[0]-48;
        }
        else if ( lm == 2)
        {
            inbase = (base_char[1]-48) + (base_char[0] - 48)*10;
        }

        if (inbase > 36 || inbase < 2)
        {
            cout << "Wrong Input";
            ifError = 1;
        }

        if (!ifError)
        {
            if (inbase <= 10)
            {
                cout << "Use only numbers from 0 to " << inbase - 1;
            }
            else
            {
                cout << "Use only numbers from 0 to 9 and UPPERCASE letters from A to " << char(inbase +54);
            }
            cout << "\nfractional is allowed\n";
            cout << "Enter your number, then enter \"#\" to tell the program you finished\n";

            // variable to calculate maximum index user will reach as he won't always use 100 characters
            int sizCnt = -1;

            // for loop that takes input till user type the char "#"
            for (int i = 0; i < 100; i++)
            {
                cin >> no[i];
                if (no[i] != '#' && no[i] != '.' && inbase <= 10)
                {
                    if (no[i] < 48 || no[i] >= inbase + 48)
                    {
                        cout << "Wrong Input";
                        ifError = 1;
                        break;
                    }
                }
                else if (no[i] != '#' && no[i] != '.' && inbase > 10)
                {
                    if (no[i] < 48 || no[i] >= inbase + 55)
                    {
                        cout << "Wrong Input";
                        ifError = 1;
                        break;
                    }
                    else if (no[i] > 57 && no[i] < 65)
                    {
                        cout << "Wrong Input";
                        ifError = 1;
                        break;
                    }
                }
                sizCnt++;
                if (no[i] == '#')
                {
                    sizCnt--;
                    break;
                }
            }

            if (!ifError)
            {

                // for loop that checks every char user wrote searching for a decimal point
                for (int i = 0; i <= sizCnt; i++)
                {
                    if (no[i] == '.')
                    {
                        // do you remember our flag? we changed it's value when we found the point
                        if_point = 1;

                        // for loop that checks every letter after the point (fractional number)
                        for (int j = i + 1, k = -1; j <= sizCnt; j++, k--)
                        {

                            /* here we check the ascii code of the letter to know whether it is (48 - 57)
                            and that tells us that it is a number ('0' - '9')
                            OR
                            it is not so we know it is a letter ('A' - 'Z') (HEXADECIMAL and higher SYSTEMS)

                            REVISE ASCII TABLE
                            */

                            if (no[j] <= 9 + 48)
                            {

                                // here we calculate N^X REVISE NORMAL CONVERT WITH PAPER AND PEN
                                double pow = 1;
                                for (int l = 0; l < (k * -1); l++)
                                {
                                    pow *= inbase;
                                }

                                /* here we turn the power into negative power[ N ^ -X = 1 / (N^X) ]
                                  then we store all operations of calculating power */
                                x += (no[j] - 48) / pow;
                            }
                            else
                            {
                                // same operations in case it was a letter (HEXADECIMAL and higher SYSTEMS)
                                double pow = 1;
                                for (int l = 0; l < (k * -1); l++)
                                {
                                    pow *= inbase;
                                }
                                x += (no[j] - 55) / pow;

                            }
                        }

                        // for loop that checks every letter before the point (integer number)
                        for (int j = i - 1, k = 0; j >= 0; j--, k++)
                        {

                            if (no[j] <= 9 + 48)
                            {
                                int pow = 1;
                                for (int l = 0; l < k; l++)
                                {
                                    pow *= inbase;
                                }
                                y += (no[j] - 48) * pow;

                            }
                            else
                            {
                                int pow = 1;
                                for (int l = 0; l < k; l++)
                                {
                                    pow *= inbase;
                                }
                                y += (no[j] - 55) * pow;
                            }
                        }

                        // here we ask if we reached the last letter user entered and it still there is no decimal point
                    }
                    else if (i == sizCnt && if_point == 0)
                    {
                        // for loop that checks every letter before the point (integer number)
                        for (int j = i, k = 0; j >= 0; j--, k++)
                        {
                            if (no[j] <= 9 + 48)
                            {
                                int pow = 1;
                                for (int l = 0; l < k; l++)
                                {
                                    pow *= inbase;
                                }
                                y += (no[j] - 48) * pow;

                            }
                            else
                            {
                                int pow = 1;
                                for (int l = 0; l < k; l++)
                                {
                                    pow *= inbase;
                                }
                                y += (no[j] - 55) * pow;
                            }

                        }

                    }
                }

                cout << "Enter the base of your output (2 - 36), enter '#' to finish\n";
                int base = 0;
                char base_char2[3];

                int lm = 0;
                for(lm = 0; lm < 3; lm++)
                {
                    cin >> base_char2[lm];
                    if(base_char2[lm] == '#')
                        break;
                }
                if(lm == 1)
                {
                    base = base_char2[0]-48;
                }
                else if ( lm == 2)
                {
                    base = (base_char2[1]-48) + (base_char2[0] - 48)*10;
                }

                if (base > 36 || base < 2)
                {
                    cout << "Wrong Input";
                    ifError = 1;
                }

                if(!ifError)
                {
                    int m;

                    // loop to store our solutions of converting integer number
                    for (m = 0; y > 0; m++)
                    {
                        if (y % base <= 9)
                        {
                            out[m] = y % base + 48;
                        }
                        else
                        {
                            out[m] = y % base + 55;
                        }
                        y /= base;
                    }

                    // loop to print them reversly due to converting nature
                    for (int n = m; n >= 0; n--)
                    {
                        cout << out[n];
                    }

                    /* our dear flag again
                     how do you convert fractional decimal number to another system? this is the same but in code :p */
                    if (if_point == 1)
                    {
                        cout << ".";
                        double z = x;
                        while (1)
                        {
                            if (int(z * base) <= 9)
                            {
                                cout << int(z * base);
                            }
                            else
                            {
                                cout << char(int(z * base) + 55);
                            }
                            z = z * base - int(z * base);
                            // we check if our current value is integer
                            if (z * base - int(z * base) == 0)
                            {
                                // we just tried and found that we need one more operation before breaking
                                if (int(z * base) <= 9)
                                {
                                    cout << int(z * base);
                                }
                                else
                                {
                                    cout << char(int(z * base) + 55);
                                }
                                cout << "\n";
                                break;
                            }
                        }
                    }
                }
            }
        }


        //*****************************************
        else
        {
            cout << "Wrong Input\n";
        }
    }
}

#include <iostream>
using namespace std;

int amountOfLettersToDisplay = 1;

void DrawDiamond(int heigh, int space)
{
    if(heigh <= 0) return;

    char letter = 65;
    int lettersIndex = 2 * amountOfLettersToDisplay - 1; // Amount of letters to display on this iteration
    bool startDecreasing = false;
    
    for(int i = 0; i < space; i++)
        cout << " ";

    for(int i = 0; i < lettersIndex; i++)
    {
        cout << letter;

        if(startDecreasing)
        {
            letter--;
            continue;
        }
        
        if(i == (lettersIndex - i) - 1)
        {
            startDecreasing = true;
            letter -= 1;
        }
        else
        {
            letter++;   
        }
    }

    cout << endl;

    amountOfLettersToDisplay++;
    DrawDiamond(heigh - 1, space - 1);
}

int main(int argc, char* argv[])
{
    int heigh = 0;
    cin >> heigh;
    
    DrawDiamond(heigh, heigh);
    
    return 0;
}

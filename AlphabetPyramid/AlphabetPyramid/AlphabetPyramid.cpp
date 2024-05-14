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

void Input()
{
    cout << "Insert height of the diamond: ";
    
    int height = 0;
    cin >> height;

    if(height < 0 || height > 26)
    {
        cout << "Insert a valid number between 1-26" << endl;

        Input();

        return;
    }
    
    DrawDiamond(height, height);
}

int main(int argc, char* argv[])
{
    Input();
    
    return 0;
}

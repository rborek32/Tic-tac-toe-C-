
#include <stdio.h>
#include <windows.h>
#include <time.h>

boolean game = TRUE;
time_t t;

char ck;
char fields[3][3];

int z = 0;
int c = 0;
int eFields = 9;
int position;

void clearMap();
void createMap();
void generateMove(char ck);
void playerMove(char ck);
int emptyFields();
void checkWinner();

int main()
{
    printf("Choose your shape O/X: ");
    scanf("%c", &ck);

    if (toupper(ck) != 'X' && toupper(ck) != 'O')
    {
        printf("Incorrect charakter!");
        return 0;
    }
    clearMap();
    createMap();
    playerMove(ck);

    return 0;
}
void playerMove(char ck)
{
    int x = 0;
    int y = 0;
    do
    {
        printf("\nEnter position (1-9): ");
        scanf("%d", &position);
        scanf("%*[^\n]");
        scanf("%*c");

        switch (position)
        {
        case 1:
            x = 0, y = 0;
            break;
        case 2:
            x = 0, y = 1;
            break;
        case 3:
            x = 0, y = 2;
            break;
        case 4:
            x = 1, y = 0;
            break;
        case 5:
            x = 1, y = 1;
            break;
        case 6:
            x = 1, y = 2;
            break;
        case 7:
            x = 2, y = 0;
            break;
        case 8:
            x = 2, y = 1;
            break;
        case 9:
            x = 2, y = 2;
            break;
        default:
            printf("Select position in the range of 1-9!");
            break;
        }

        if (fields[x][y] != ' ')
        {
            printf("Position %d%d is already taken!", x, y);
            printf("\n%c", fields[x][y]);
        }
        else
        {
            fields[x][y] = ck;
            if (eFields != 1)
            {
                generateMove(ck);
            }
            eFields = eFields - 2;
        }
        createMap();
        printf("\nEmpty Fields: %d", eFields);
        checkWinner();
    } while (eFields > 0);
    printf("\nDRAW!");
}
void clearMap()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fields[i][j] = ' ';
        }
    }
}
void createMap()
{
    printf("\n %c | %c | %c ", fields[0][0], fields[0][1], fields[0][2]);
    printf("\n --|---|-- ");
    printf("\n %c | %c | %c ", fields[1][0], fields[1][1], fields[1][2]);
    printf("\n --|---|-- ");
    printf("\n %c | %c | %c ", fields[2][0], fields[2][1], fields[2][2]);
}
void generateMove(char ck)
{
    srand((unsigned)time(&t));
    do
    {
        z = rand() % 3;
        c = rand() % 3;
    } while (fields[z][c] != ' ');

    if (toupper(ck) == 'O' && fields[z][c] == ' ')
    {
        fields[z][c] = 'X';
    }
    else if (toupper(ck) == 'X' && fields[z][c] == ' ')
    {
        fields[z][c] = 'Y';
    }
}
void checkWinner()
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if ((fields[i][0] == fields[i][1] && fields[i][0] == fields[i][2]) &&
            (fields[i][0] != ' ' && fields[i][2] != ' '))
        {
            printf("\n%c wins!", fields[i][0]);
            _Exit(0);
        }
    }
    // check collumns
    for (int j = 0; j < 3; j++)
    {
        if ((fields[0][j] == fields[1][j] && fields[0][j] == fields[2][j]) &&
            (fields[0][j] != ' '))
        {
            printf("\n%c wins!", fields[0][j]);
            _Exit(0);
        }
    }
    // check diagonal
    if (((fields[0][0] == fields[1][1] && fields[0][0] == fields[2][2]) ||
         (fields[0][2] == fields[1][1] && fields[0][2] == fields[2][0]) && fields[1][1] != ' '))
    {
        printf("\n%c wins!", fields[1][1]);
        _Exit(0);
    }
}

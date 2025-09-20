#include <iostream>
using namespace std;

int main() {
    char tablet[9] = {'1','2','3','4','5','6','7','8','9'};
    char player = 'X';
    int move;
    bool game_over = false;

    while(!game_over) {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            cout << tablet[i] << " ";
            if ((i + 1) % 3 == 0) cout << "\n";
        }

        cout << "\nEs tu turno " << player << ", elija una posicion del 1 al 9: ";
        cin >> move;

        if (move < 1 || move > 9 || tablet[move - 1] == 'X' || tablet[move - 1] == 'O') {
            cout << "Movimiento invalido. Intenta de nuevo.\n";
            continue;
        }

        tablet[move - 1] = player;

      
        if ((tablet[0]==player && tablet[1]==player && tablet[2]==player) || 
            (tablet[3]==player && tablet[4]==player && tablet[5]==player) || 
            (tablet[6]==player && tablet[7]==player && tablet[8]==player) || 
            (tablet[0]==player && tablet[3]==player && tablet[6]==player) || 
            (tablet[1]==player && tablet[4]==player && tablet[7]==player) || 
            (tablet[2]==player && tablet[5]==player && tablet[8]==player) || 
            (tablet[0]==player && tablet[4]==player && tablet[8]==player) || 
            (tablet[2]==player && tablet[4]==player && tablet[6]==player))   
        {
            cout << "\nJugador " << player << " gana!\n";
            return 0;
        }

        
        bool draw = true;
        for (int i = 0; i < 9; i++) {
            if (tablet[i] != 'X' && tablet[i] != 'O') {
                draw = false;
                break;
            }
        }
        if (draw) {
            cout << "\nEmpate!\n";
            return 0;
        }

        
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

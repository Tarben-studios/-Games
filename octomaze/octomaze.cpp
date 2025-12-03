#include <iostream>
#include <unistd.h>
#include <cmath>

int fantasma_x = 0, fantasma_y = 0;
int bloco_original_fantasma = 0;
bool fantasma_inicializado = false;

using namespace std;

const int larg = 16;
const int alt = 16;

int v[larg][alt] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1},
    {1,0,1,0,1,0,3,1,0,1,0,0,0,1,0,1},
    {1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1},
    {1,1,1,0,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
    {1,2,1,1,1,1,1,1,0,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

template<int LARG, int ALT>
void plab(int (&lab)[LARG][ALT], int largura, int altura) {
    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < altura; j++) {
            if (lab[i][j] == 0)
                cout << "  ";
            else if (lab[i][j] == -1)
                cout << "\033[31m██\033[0m";
            else if (lab[i][j] == 1)
                cout << "██";
            else if (lab[i][j] == 2)
                cout << "👾";
            else if (lab[i][j] == 3)
                cout << "⛳️";
            else if (lab[i][j] == 4)
                cout << "📍";
            else if (lab[i][j] == 5)
                cout << "🚪";
            else if (lab[i][j] == 6)
                cout << "🚧";
            else if (lab[i][j] == 7)
                cout << "📦";
            else if (lab[i][j] == 8)
                cout << "🌀";
            else if (lab[i][j] == 9)
                cout << "🌀";    
            else if (lab[i][j] == 10)
                cout << "👻";
            else if (lab[i][j] == 11)
                cout << "🚪";
             
        }
        cout << endl;
    }
}

int main() {
    string direct, condicao;
    int i, j, loc, loc1;
    
    cout << "Labirinto! Ache o caminho correto e fuja!" << endl
         << "Movimentação via" << endl << "   W " <<endl
         << " A S D " <<endl;
    sleep(2);
    cout << "\033[2J\033[H";
    
    
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "███████╗ █████╗ ███████╗███████╗     ██╗" << endl;
    cout << "██╔════╝██╔══██╗██╔════╝██╔════╝    ███║" << endl;
    cout << "█████╗  ███████║███████╗█████╗      ╚██║" << endl;
    cout << "██╔══╝  ██╔══██║╚════██║██╔══╝       ██║" << endl;
    cout << "██║     ██║  ██║███████║███████╗     ██║" << endl;
    cout << "╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝     ╚═╝" << endl;

    //sleep(2);
    cout << "\033[2J\033[H";
    
    // Encontra posição inicial do jogador
    for (i = 0; i < larg; i++) {
        for (j = 0; j < alt; j++) {
            if (v[i][j] == 2) {
                loc = i;
                loc1 = j;
            }
        }
    }

    while(condicao == "vitoria") {    
        plab(v, larg, alt);
        cin >> direct;
        
        // Movimento para a direita
        if(direct == "direita" || direct == "Direita" || direct == "Right" || direct == "D" || direct == "d") {
            if(v[loc][loc1 + 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(v[loc][loc1 + 1] == 1 || v[loc][loc1 + 1] == -1) {
                cout << "Você bateu na parede!" << endl;
                v[loc][loc1 + 1] = -1;
                
            } else {
                v[loc][loc1] = 0;
                v[loc][loc1 + 1] = 2;
                loc1++;
            }
        }
        // Movimento para a esquerda
        else if(direct == "esquerda" || direct == "Esquerda" || direct == "Left" || direct == "a" || direct == "A") {
            if(v[loc][loc1 - 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(v[loc][loc1 - 1] == 1 || v[loc][loc1 - 1] == -1) {
                cout << "Você bateu na parede!" << endl;
                v[loc][loc1 - 1] = -1;
                
            } else {
                v[loc][loc1] = 0;
                v[loc][loc1 - 1] = 2;
                loc1--;
            }
        }
        // Movimento para cima
        else if(direct == "cima" || direct == "Cima" || direct == "Up" || direct == "W" || direct == "w") {
            if(v[loc - 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(v[loc - 1][loc1] == 1 || v[loc - 1][loc1] == -1) {
                cout << "Você bateu na parede!" << endl;
                v[loc - 1][loc1] = -1;
                
            } else {
                v[loc][loc1] = 0;
                v[loc - 1][loc1] = 2;
                loc--;
            }
        }
        // Movimento para baixo
        else if(direct == "baixo" || direct == "Baixo" || direct == "Down" || direct == "S" || direct == "s") {
            if(v[loc + 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(v[loc + 1][loc1] == 1 || v[loc + 1][loc1] == -1) {
                cout << "Você bateu na parede!" << endl;
                v[loc + 1][loc1] = -1;
                
            } else {
                v[loc][loc1] = 0;
                v[loc + 1][loc1] = 2;
                loc++;
            }
        }
        
        cout << "\033[2J\033[H";
    }   
    cout << "\033[2J\033[H";
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "███████╗ █████╗ ███████╗███████╗    ██████╗ " << endl;
    cout << "██╔════╝██╔══██╗██╔════╝██╔════╝   ╚════██╗" << endl;
    cout << "█████╗  ███████║███████╗█████╗      █████╔╝" << endl;
    cout << "██╔══╝  ██╔══██║╚════██║██╔══╝      ██╔═══╝" << endl;
    cout << "██║     ██║  ██║███████║███████╗    ███████╗" << endl;
    cout << "╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝    ╚══════╝" << endl;

   // sleep(2);
    cout << "\033[2J\033[H";

    int v2[20][18] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,2,0,0,0,0,1,0,0,1,0,6,1,0,0,0,0,1},
        {1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1},
        {1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1},
        {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1},
        {1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1},
        {1,1,1,0,1,1,1,4,1,1,0,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1},
        {1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,1},
        {1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1},
        {1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1},
        {1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,6,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,3,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    
    // Reset condition for second maze
    condicao = "";
    
    // Find initial player position in second maze
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 18; j++) {
            if (v2[i][j] == 2) {
                loc = i;
                loc1 = j;
            }
        }
    }

    while(condicao == "vitoria") {    
        plab(v2, 20, 18);
        cin >> direct;
        
        // Movimento para a direita
        if(direct == "direita" || direct == "Direita" || direct == "Right" || direct == "D" || direct == "d") {
            if(v2[loc][loc1 + 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(v2[loc][loc1 + 1] == 4) {
                // Press button and remove obstacles
                for(i = 0; i < 20; i++) {
                    for(j = 0; j < 18; j++) {
                        if(v2[i][j] == 6) v2[i][j] = 0;
                    }
                }
                v2[loc][loc1] = 0;
                v2[loc][loc1 + 1] = 2;
                loc1++;
            }
            else if(v2[loc][loc1 + 1] == 1 || v2[loc][loc1 + 1] == -1) {
                cout << "Você bateu na parede!" << endl;
                v2[loc][loc1 + 1] = -1;
                
            } else if(v2[loc][loc1 + 1] == 0) {
                v2[loc][loc1] = 0;
                v2[loc][loc1 + 1] = 2;
                loc1++;
            }
        }
        // Movimento para a esquerda
        else if(direct == "esquerda" || direct == "Esquerda" || direct == "Left" || direct == "a" || direct == "A") {
            if(v2[loc][loc1 - 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(v2[loc][loc1 - 1] == 4) {
                // Press button and remove obstacles
                for(i = 0; i < 20; i++) {
                    for(j = 0; j < 18; j++) {
                        if(v2[i][j] == 6) v2[i][j] = 0;
                    }
                }
                v2[loc][loc1] = 0;
                v2[loc][loc1 - 1] = 2;
                loc1--;
            }
            else if(v2[loc][loc1 - 1] == 1 || v2[loc][loc1 - 1] == -1) {
                cout << "Você bateu na parede!" << endl;
                v2[loc][loc1 - 1] = -1;
                
            } else if(v2[loc][loc1 - 1] == 0) {
                v2[loc][loc1] = 0;
                v2[loc][loc1 - 1] = 2;
                loc1--;
            }
        }
        // Movimento para cima
        else if(direct == "cima" || direct == "Cima" || direct == "Up" || direct == "W" || direct == "w") {
            if(v2[loc - 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(v2[loc - 1][loc1] == 4) {
                // Press button and remove obstacles
                for(i = 0; i < 20; i++) {
                    for(j = 0; j < 18; j++) {
                        if(v2[i][j] == 6) v2[i][j] = 0;
                    }
                }
                v2[loc][loc1] = 0;
                v2[loc - 1][loc1] = 2;
                loc--;
            }
            else if(v2[loc - 1][loc1] == 1 || v2[loc - 1][loc1] == -1) {
                cout << "Você bateu na parede!" << endl;
                v2[loc - 1][loc1] = -1;
                
            } else if(v2[loc - 1][loc1] == 0) {
                v2[loc][loc1] = 0;
                v2[loc - 1][loc1] = 2;
                loc--;
            }
        }
        // Movimento para baixo
        else if(direct == "baixo" || direct == "Baixo" || direct == "Down" || direct == "S" || direct == "s") {
            if(v2[loc + 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(v2[loc + 1][loc1] == 4) {
                // Press button and remove obstacles
                for(i = 0; i < 20; i++) {
                    for(j = 0; j < 18; j++) {
                        if(v2[i][j] == 6) v2[i][j] = 0;
                    }
                }
                v2[loc][loc1] = 0;
                v2[loc + 1][loc1] = 2;
                loc++;
            }
            else if(v2[loc + 1][loc1] == 1 || v2[loc + 1][loc1] == -1) {
                cout << "Você bateu na parede!" << endl;
                v2[loc + 1][loc1] = -1;
                
            } else if(v2[loc + 1][loc1] == 0) {
                v2[loc][loc1] = 0;
                v2[loc + 1][loc1] = 2;
                loc++;
            }
        }
        
        cout << "\033[2J\033[H";
    }
    cout << "\033[2J\033[H";
    condicao = "andamento";
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
   
    cout << "███████╗ █████╗ ███████╗███████╗   ██████╗ " << endl;
    cout << "██╔════╝██╔══██╗██╔════╝██╔════╝   ╚═══██╗" << endl;
    cout << "█████╗  ███████║███████╗█████╗     █████╔╝" << endl;
    cout << "██╔══╝  ██╔══██║╚════██║██╔══╝     ╚═══██╗" << endl;
    cout << "██║     ██║  ██║███████║███████╗   ██████╗" << endl;
    cout << "╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝   ╚═════╝" << endl;

   // sleep(2);
    cout << "\033[2J\033[H";
    
    int v5[20][20] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,0,0,1,0,0,1,0,6,1,0,0,0,0,1,0,1},
    {1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1},
    {1,1,1,0,1,1,1,4,1,1,0,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,1,0,1,0,0,0,0,7,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1},
    {1,0,0,0,0,0,1,6,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,3,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// Reset player position for the maze
for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
        if (v5[i][j] == 2) {
            loc = i;
            loc1 = j;
        }
    }
}

while(condicao != "vitoria") {    
    // Clear screen and redraw maze
    cout << "\033[2J\033[H";
    plab(v5, 20, 20);
    
    cin >> direct;
    
    // Right movement
    if(direct == "direita" || direct == "Direita" || direct == "Right" || direct == "D" || direct == "d") {
        if(loc1 + 1 < 20 && v5[loc][loc1 + 1] == 3) {
            condicao = "vitoria";
            break;
        }
        
        if(loc1 + 1 < 20 && v5[loc][loc1 + 1] == 4) {
            // Press button and remove obstacles
            for(i = 0; i < 20; i++) {
                for(j = 0; j < 20; j++) {
                    if(v5[i][j] == 6) v5[i][j] = 0;
                }
            }
            v5[loc][loc1] = 0;
            v5[loc][loc1 + 1] = 2;
            loc1++;
        }
        else if(loc1 + 1 < 20 && (v5[loc][loc1 + 1] == 1 || v5[loc][loc1 + 1] == -1)) {
            cout << "Você bateu na parede!" << endl;
            v5[loc][loc1 + 1] = -1;
            
        } 
        else if(loc1 + 2 < 20 && v5[loc][loc1 + 1] == 7 && v5[loc][loc1 + 2] == 0) {
            v5[loc][loc1 + 1] = 2;
            v5[loc][loc1 + 2] = 7;
            v5[loc][loc1] = 0;
            loc1++;
        }    
        else if(loc1 + 1 < 20 && v5[loc][loc1 + 1] == 0) {
            v5[loc][loc1] = 0;
            v5[loc][loc1 + 1] = 2;
            loc1++;
        }
    }
    // Left movement
    else if(direct == "esquerda" || direct == "Esquerda" || direct == "Left" || direct == "a" || direct == "A") {
        if(loc1 - 1 >= 0 && v5[loc][loc1 - 1] == 3) {
            condicao = "vitoria";
            break;
        }
        
        if(loc1 - 1 >= 0 && v5[loc][loc1 - 1] == 4) {
            // Press button and remove obstacles
            for(i = 0; i < 20; i++) {
                for(j = 0; j < 20; j++) {
                    if(v5[i][j] == 6) v5[i][j] = 0;
                }
            }
            v5[loc][loc1] = 0;
            v5[loc][loc1 - 1] = 2;
            loc1--;
        }
        else if(loc1 - 1 >= 0 && (v5[loc][loc1 - 1] == 1 || v5[loc][loc1 - 1] == -1)) {
            cout << "Você bateu na parede!" << endl;
            v5[loc][loc1 - 1] = -1;
            
        } 
        else if(loc1 - 2 >= 0 && v5[loc][loc1 - 1] == 7 && v5[loc][loc1 - 2] == 0) {
            v5[loc][loc1 - 1] = 2;
            v5[loc][loc1 - 2] = 7;
            v5[loc][loc1] = 0;
            loc1--;
        }
        else if(loc1 - 1 >= 0 && v5[loc][loc1 - 1] == 0) {
            v5[loc][loc1] = 0;
            v5[loc][loc1 - 1] = 2;
            loc1--;
        }
    }
    // Up movement
    else if(direct == "cima" || direct == "Cima" || direct == "Up" || direct == "W" || direct == "w") {
        if(loc - 1 >= 0 && v5[loc - 1][loc1] == 3) {
            condicao = "vitoria";
            break;
        }
        
        if(loc - 1 >= 0 && v5[loc - 1][loc1] == 4) {
            // Press button and remove obstacles
            for(i = 0; i < 20; i++) {
                for(j = 0; j < 20; j++) {
                    if(v5[i][j] == 6) v5[i][j] = 0;
                }
            }
            v5[loc][loc1] = 0;
            v5[loc - 1][loc1] = 2;
            loc--;
        }
        else if(loc - 1 >= 0 && (v5[loc - 1][loc1] == 1 || v5[loc - 1][loc1] == -1)) {
            cout << "Você bateu na parede!" << endl;
            v5[loc - 1][loc1] = -1;
            
        } 
        else if(loc - 2 >= 0 && v5[loc - 1][loc1] == 7 && v5[loc - 2][loc1] == 0) {
            v5[loc - 1][loc1] = 2;
            v5[loc - 2][loc1] = 7;
            v5[loc][loc1] = 0;
            loc--;
        }
        else if(loc - 1 >= 0 && v5[loc - 1][loc1] == 0) {
            v5[loc][loc1] = 0;
            v5[loc - 1][loc1] = 2;
            loc--;
        }
    }
    // Down movement
    else if(direct == "baixo" || direct == "Baixo" || direct == "Down" || direct == "S" || direct == "s") {
        if(loc + 1 < 20 && v5[loc + 1][loc1] == 3) {
            condicao = "vitoria";
            break;
        }
        
        if(loc + 1 < 20 && v5[loc + 1][loc1] == 4) {
            // Press button and remove obstacles
            for(i = 0; i < 20; i++) {
                for(j = 0; j < 20; j++) {
                    if(v5[i][j] == 6) v5[i][j] = 0;
                }
            }
            v5[loc][loc1] = 0;
            v5[loc + 1][loc1] = 2;
            loc++;
        }
        else if(loc + 1 < 20 && (v5[loc + 1][loc1] == 1 || v5[loc + 1][loc1] == -1)) {
            cout << "Você bateu na parede!" << endl;
            v5[loc + 1][loc1] = -1;
            
        } 
        else if(loc + 2 < 20 && v5[loc + 1][loc1] == 7 && v5[loc + 2][loc1] == 0) {
            v5[loc + 1][loc1] = 2;
            v5[loc + 2][loc1] = 7;
            v5[loc][loc1] = 0;
            loc++;
        }
        else if(loc + 1 < 20 && v5[loc + 1][loc1] == 0) {
            v5[loc][loc1] = 0;
            v5[loc + 1][loc1] = 2;
            loc++;
        }
    }
}    
    cout << "\033[2J\033[H";
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    
    
    
cout << "███╗   ███╗██╗   ██╗███╗   ██╗██████╗  ██████╗     ██████╗ " << endl;
cout << "████╗ ████║██║   ██║████╗  ██║██╔══██╗██╔═══██╗   ╚════██╗" << endl;
cout << "██╔████╔██║██║   ██║██╔██╗ ██║██║  ██║██║   ██║    █████╔╝" << endl;
cout << "██║╚██╔╝██║██║   ██║██║╚██╗██║██║  ██║██║   ██║   ██╔═══╝ " << endl;
cout << "██║ ╚═╝ ██║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝    ██████╗" << endl;
cout << "╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝     ╚═════╝" << endl <<endl;
    
    
    cout << "███████╗ █████╗ ███████╗███████╗     ██╗" << endl;
    cout << "██╔════╝██╔══██╗██╔════╝██╔════╝    ███║" << endl;
    cout << "█████╗  ███████║███████╗█████╗      ╚██║" << endl;
    cout << "██╔══╝  ██╔══██║╚════██║██╔══╝       ██║" << endl;
    cout << "██║     ██║  ██║███████║███████╗     ██║" << endl;
    cout << "╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝     ╚═╝" << endl;    
    
    sleep(2);
const int malt = 20;
const int mlarg = 21;
int mv1[20][21] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,6,0,0,8,1,9,0,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1},
    {1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1},
    {1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,1,0,1,0,7,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,7,1,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,0,0,4,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1},
    {1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,3,1},
    {1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,6,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
    
    for (i = 0; i < 20; i++) {
    for (j = 0; j < 21; j++) {
        if (mv1[i][j] == 2) {
            loc = i;
            loc1 = j;
        }
    }
}
    condicao = "jogando";
    
    while(condicao != "vitoria") {    
        // Limpa a tela e redesenha o labirinto
        cout << "\033[2J\033[H";
        plab(mv1, malt,mlarg);
        cin >> direct;
        
        // Movimento para direita
        if(direct == "direita" || direct == "Direita" || direct == "Right" || direct == "D" || direct == "d") {
            if(loc1 + 1 < mlarg && mv1[loc][loc1 + 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc1 + 1 < mlarg && mv1[loc][loc1 + 1] == 4) {
                // Pressiona botão e remove obstáculos
                for(int i = 0; i < malt; i++) {
                    for(int j = 0; j < mlarg; j++) {
                        if(mv1[i][j] == 6) mv1[i][j] = 0;
                    }
                }
                mv1[loc][loc1] = 0;
                mv1[loc][loc1 + 1] = 2;
                loc1++;
            }
            else if(loc1 + 1 < mlarg && (mv1[loc][loc1 + 1] == 1 || mv1[loc][loc1 + 1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv1[loc][loc1 + 1] = -1;
            } 
            else if(loc1 + 2 < mlarg && mv1[loc][loc1 + 1] == 7 && mv1[loc][loc1 + 2] == 0) {
                mv1[loc][loc1 + 1] = 2;
                mv1[loc][loc1 + 2] = 7;
                mv1[loc][loc1] = 0;
                loc1++;
            }    
            else if(loc1 + 1 < mlarg && mv1[loc][loc1 + 1] == 0) {
                mv1[loc][loc1] = 0;
                mv1[loc][loc1 + 1] = 2;
                loc1++;
            }
            else if(mv1[loc][loc1+1] == 8){
                for(int i = 0; i < malt; i++)
                {
                    for(int j = 0; j < mlarg; j++)
                    {
                        if(mv1[i][j] == 9) 
                        {
                        mv1[loc][loc1]=0;
                        mv1[i][j+1] = 2;
                        loc = i;
                        loc1 = j+1;
                        break;
                        }
                    }
                }
            }
        }
        // Movimento para esquerda
        else if(direct == "esquerda" || direct == "Esquerda" || direct == "Left" || direct == "A" || direct == "a") {
            if(loc1 - 1 >= 0 && mv1[loc][loc1 - 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc1 - 1 >= 0 && mv1[loc][loc1 - 1] == 4) {
                // Pressiona botão e remove obstáculos
                for(int i = 0; i < malt; i++) {
                    for(int j = 0; j < mlarg; j++) {
                        if(mv1[i][j] == 6) mv1[i][j] = 0;
                    }
                }
                mv1[loc][loc1] = 0;
                mv1[loc][loc1 - 1] = 2;
                loc1--;
            }
            else if(loc1 - 1 >= 0 && (mv1[loc][loc1 - 1] == 1 || mv1[loc][loc1 - 1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv1[loc][loc1 - 1] = -1;
            } 
            else if(loc1 - 2 >= 0 && mv1[loc][loc1 - 1] == 7 && mv1[loc][loc1 - 2] == 0) {
                mv1[loc][loc1 - 1] = 2;
                mv1[loc][loc1 - 2] = 7;
                mv1[loc][loc1] = 0;
                loc1--;
            }
            else if(loc1 - 1 >= 0 && mv1[loc][loc1 - 1] == 0) {
                mv1[loc][loc1] = 0;
                mv1[loc][loc1 - 1] = 2;
                loc1--;
            }
            else if(mv1[loc][loc1-1] == 9){
                for(int i = 0; i < malt; i++)
                {
                    for(int j = 0; j < mlarg; j++)
                    {
                        if(mv1[i][j] == 8) 
                        {
                        mv1[loc][loc1]=0;
                        mv1[i][j-1] = 2;
                        loc = i;
                        loc1 = j-1;
                        break;
                        }
                    }
                }
            }    
            
        }
        // Movimento para cima
        else if(direct == "cima" || direct == "Cima" || direct == "Up" || direct == "W" || direct == "w") {
            if(loc - 1 >= 0 && mv1[loc - 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc - 1 >= 0 && mv1[loc - 1][loc1] == 4) {
                // Pressiona botão e remove obstáculos
                for(int i = 0; i < malt; i++) {
                    for(int j = 0; j < mlarg; j++) {
                        if(mv1[i][j] == 6) mv1[i][j] = 0;
                    }
                }
                mv1[loc][loc1] = 0;
                mv1[loc - 1][loc1] = 2;
                loc--;
            }
            else if(loc - 1 >= 0 && (mv1[loc - 1][loc1] == 1 || mv1[loc - 1][loc1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv1[loc - 1][loc1] = -1;
            } 
            else if(loc - 2 >= 0 && mv1[loc - 1][loc1] == 7 && mv1[loc - 2][loc1] == 0) {
                mv1[loc - 1][loc1] = 2;
                mv1[loc - 2][loc1] = 7;
                mv1[loc][loc1] = 0;
                loc--;
            }
            else if(loc - 1 >= 0 && mv1[loc - 1][loc1] == 0) {
                mv1[loc][loc1] = 0;
                mv1[loc - 1][loc1] = 2;
                loc--;
            }
        }
        // Movimento para baixo
        else if(direct == "baixo" || direct == "Baixo" || direct == "Down" || direct == "S" || direct == "s") {
            if(loc + 1 < malt && mv1[loc + 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc + 1 < malt && mv1[loc + 1][loc1] == 4) {
                // Pressiona botão e remove obstáculos
                for(int i = 0; i < malt; i++) {
                    for(int j = 0; j < mlarg; j++) {
                        if(mv1[i][j] == 6) mv1[i][j] = 0;
                    }
                }
                mv1[loc][loc1] = 0;
                mv1[loc + 1][loc1] = 2;
                loc++;
            }
            else if(loc + 1 < malt && (mv1[loc + 1][loc1] == 1 || mv1[loc + 1][loc1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv1[loc + 1][loc1] = -1;
            } 
            else if(loc + 2 < malt && mv1[loc + 1][loc1] == 7 && mv1[loc + 2][loc1] == 0) {
                mv1[loc + 1][loc1] = 2;
                mv1[loc + 2][loc1] = 7;
                mv1[loc][loc1] = 0;
                loc++;
            }
            else if(loc + 1 < malt && mv1[loc + 1][loc1] == 0) {
                mv1[loc][loc1] = 0;
                mv1[loc + 1][loc1] = 2;
                loc++;
            }
        }
    }
    condicao ="jogando";
    
cout << "███╗   ███╗██╗   ██╗███╗   ██╗██████╗  ██████╗     ██████╗ " << endl;
cout << "████╗ ████║██║   ██║████╗  ██║██╔══██╗██╔═══██╗   ╚════██╗" << endl;
cout << "██╔████╔██║██║   ██║██╔██╗ ██║██║  ██║██║   ██║    █████╔╝" << endl;
cout << "██║╚██╔╝██║██║   ██║██║╚██╗██║██║  ██║██║   ██║   ██╔═══╝ " << endl;
cout << "██║ ╚═╝ ██║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝    ██████╗" << endl;
cout << "╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝     ╚═════╝" << endl <<endl;

    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "███████╗ █████╗ ███████╗███████╗    ██████╗ " << endl;
    cout << "██╔════╝██╔══██╗██╔════╝██╔════╝   ╚════██╗" << endl;
    cout << "█████╗  ███████║███████╗█████╗      █████╔╝" << endl;
    cout << "██╔══╝  ██╔══██║╚════██║██╔══╝      ██╔═══╝" << endl;
    cout << "██║     ██║  ██║███████║███████╗    ███████╗" << endl;
    cout << "╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝    ╚══════╝" << endl;
    
    sleep(2);

    const int malt2= 20;
    const int mlarg2 = 22;
    
    int mv2[20][22] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,1,0,0,0,0,0,0,1,4,0,0,0,0,0,0,0,8,1},
    {1,1,1,0,1,0,1,1,1,1,0,1,6,1,7,1,1,1,1,0,1,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1},
    {1,9,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
    {1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
    {1,1,1,7,1,0,1,1,7,1,1,1,1,1,0,1,1,1,0,1,1,1},
    {1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,6,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,0,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
    
    for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
        if (mv2[i][j] == 2) {
            loc = i;
            loc1 = j;}
        }
    }
    
     while(condicao != "vitoria") {    
        // Limpa a tela e redesenha o labirinto
        cout << "\033[2J\033[H";
        plab(mv2, malt2,mlarg2);
        cin >> direct;
        
        // Movimento para direita
        if(direct == "direita" || direct == "Direita" || direct == "Right" || direct == "D" || direct == "d") {
            if(loc1 + 1 < mlarg2 && mv2[loc][loc1 + 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc1 + 1 < mlarg2 && mv2[loc][loc1 + 1] == 4) {
                // Pressiona botão e remove obstáculos
                for(int i = 0; i < malt2; i++) {
                    for(int j = 0; j < mlarg2; j++) {
                        if(mv2[i][j] == 6) mv2[i][j] = 0;
                    }
                }
                mv2[loc][loc1] = 0;
                mv2[loc][loc1 + 1] = 2;
                loc1++;
            }
            else if(loc1 + 1 < mlarg2 && (mv2[loc][loc1 + 1] == 1 || mv2[loc][loc1 + 1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv2[loc][loc1 + 1] = -1;
            } 
            else if(loc1 + 2 < mlarg2 && mv2[loc][loc1 + 1] == 7 && mv2[loc][loc1 + 2] == 0) {
                mv2[loc][loc1 + 1] = 2;
                mv2[loc][loc1 + 2] = 7;
                mv2[loc][loc1] = 0;
                loc1++;
            }    
            else if(loc1 + 1 < mlarg2 && mv2[loc][loc1 + 1] == 0) {
                mv2[loc][loc1] = 0;
                mv2[loc][loc1 + 1] = 2;
                loc1++;
            }
            else if(mv2[loc][loc1+1] == 8){
                for(int i = 0; i < malt2; i++)
                {
                    for(int j = 0; j < mlarg2; j++)
                    {
                        if(mv2[i][j] == 9) 
                        {
                        mv2[loc][loc1]=0;
                        mv2[i][j+1] = 2;
                        loc = i;
                        loc1 = j+1;
                        break;
                        }
                    }
                }
            }
        }
        // Movimento para esquerda
        else if(direct == "esquerda" || direct == "Esquerda" || direct == "Left" || direct == "A" || direct == "a") {
            if(loc1 - 1 >= 0 && mv2[loc][loc1 - 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc1 - 1 >= 0 && mv2[loc][loc1 - 1] == 4) {
                // Pressiona botão e remove obstáculos
                for(int i = 0; i < malt2; i++) {
                    for(int j = 0; j < mlarg2; j++) {
                        if(mv2[i][j] == 6) mv2[i][j] = 0;
                    }
                }
                mv2[loc][loc1] = 0;
                mv2[loc][loc1 - 1] = 2;
                loc1--;
            }
            else if(loc1 - 1 >= 0 && (mv2[loc][loc1 - 1] == 1 || mv2[loc][loc1 - 1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv2[loc][loc1 - 1] = -1;
            } 
            else if(loc1 - 2 >= 0 && mv2[loc][loc1 - 1] == 7 && mv2[loc][loc1 - 2] == 0) {
                mv2[loc][loc1 - 1] = 2;
                mv2[loc][loc1 - 2] = 7;
                mv2[loc][loc1] = 0;
                loc1--;
            }
            else if(loc1 - 1 >= 0 && mv2[loc][loc1 - 1] == 0) {
                mv2[loc][loc1] = 0;
                mv2[loc][loc1 - 1] = 2;
                loc1--;
            }
            else if(mv2[loc][loc1-1] == 9){
                for(int i = 0; i < malt2; i++)
                {
                    for(int j = 0; j < mlarg2; j++)
                    {
                        if(mv2[i][j] == 8) 
                        {
                        mv2[loc][loc1]=0;
                        mv2[i][j-1] = 2;
                        loc = i;
                        loc1 = j-1;
                        break;
                        }
                    }
                }
            }    
            
        }
        // Movimento para cima
        else if(direct == "cima" || direct == "Cima" || direct == "Up" || direct == "W" || direct == "w") {
            if(loc - 1 >= 0 && mv2[loc - 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc - 1 >= 0 && mv2[loc - 1][loc1] == 4) {
                // Pressiona botão e remove obstáculos
                for(int i = 0; i < malt2; i++) {
                    for(int j = 0; j < mlarg2; j++) {
                        if(mv2[i][j] == 6) mv2[i][j] = 0;
                    }
                }
                mv2[loc][loc1] = 0;
                mv2[loc - 1][loc1] = 2;
                loc--;
            }
            else if(loc - 1 >= 0 && (mv2[loc - 1][loc1] == 1 || mv2[loc - 1][loc1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv2[loc - 1][loc1] = -1;
            } 
            else if(loc - 2 >= 0 && mv2[loc - 1][loc1] == 7 && mv2[loc - 2][loc1] == 0) {
                mv2[loc - 1][loc1] = 2;
                mv2[loc - 2][loc1] = 7;
                mv2[loc][loc1] = 0;
                loc--;
            }
            else if(loc - 1 >= 0 && mv2[loc - 1][loc1] == 0) {
                mv2[loc][loc1] = 0;
                mv2[loc - 1][loc1] = 2;
                loc--;
            }
        }
        // Movimento para baixo
        else if(direct == "baixo" || direct == "Baixo" || direct == "Down" || direct == "S" || direct == "s") {
            if(loc + 1 < malt2 && mv2[loc + 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc + 1 < malt2 && mv2[loc + 1][loc1] == 4) {
                // Pressiona botão e remove obstáculos
                for(int i = 0; i < malt2; i++) {
                    for(int j = 0; j < mlarg2; j++) {
                        if(mv2[i][j] == 6) mv2[i][j] = 0;
                    }
                }
                mv2[loc][loc1] = 0;
                mv2[loc + 1][loc1] = 2;
                loc++;
            }
            else if(loc + 1 < malt2 && (mv2[loc + 1][loc1] == 1 || mv2[loc + 1][loc1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv2[loc + 1][loc1] = -1;
            } 
            else if(loc + 2 < malt2 && mv2[loc + 1][loc1] == 7 && mv2[loc + 2][loc1] == 0) {
                mv2[loc + 1][loc1] = 2;
                mv2[loc + 2][loc1] = 7;
                mv2[loc][loc1] = 0;
                loc++;
            }
            else if(loc + 1 < malt2 && mv2[loc + 1][loc1] == 0) {
                mv2[loc][loc1] = 0;
                mv2[loc + 1][loc1] = 2;
                loc++;
            }
        }
    }
    condicao = " ";
    cout << "\033[2J\033[H";
    
cout << endl << endl << endl << endl << endl << endl << endl << endl;
cout << "\033[1;91m"; // Ativa vermelho brilhante (1 = negrito, 91 = vermelho claro)
cout << "███████╗ █████╗ ███████╗███████╗" << endl;
cout << "██╔════╝██╔══██╗██╔════╝██╔════╝" << endl;
cout << "█████╗  ███████║███████╗█████╗  " << endl;
cout << "██╔══╝  ██╔══██║╚════██║██╔══╝  " << endl;
cout << "██║     ██║  ██║███████║███████╗" << endl;
cout << "╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝" << endl;

cout << endl; // Espaço entre as palavras

cout << "███████╗██╗███╗   ██╗ █████╗ ██╗     " << endl;
cout << "██╔════╝██║████╗  ██║██╔══██╗██║     " << endl;
cout << "█████╗  ██║██╔██╗ ██║███████║██║     " << endl;
cout << "██╔══╝  ██║██║╚██╗██║██╔══██║██║     " << endl;
cout << "██║     ██║██║ ╚████║██║  ██║███████╗" << endl;
cout << "╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝" << endl;

sleep(3);
    
cout << "\033[0m"; // Reseta a cor para o padrão
    
    
cout << endl << endl << endl << endl << endl << endl << endl << endl 
     << "Fuja!"<<endl;
    
    cout << "\033[0m";
    sleep(2);
    
    
    
    
const int malt3 = 20;
const int mlar3 = 22;
int loq = 0;
int loq1 = 0;
// New maze layout (mv3)
int mv3[20][22] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,10,11,1},
    {1,0,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,4,1},
    {1,1,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,3,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,1,0,1,0,0,6,7,6,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,9,0,1},
    {1,1,1,1,1,0,4,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,7,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
    {1,0,1,0,0,0,1,0,6,5,1,0,0,0,1,0,0,0,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

    // Find initial player position (2)
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 22; j++) {
            if (mv3[i][j] == 2) {
                loc = i;
                loc1 = j;
            }
        }
    }

    // Find initial ghost position (10)
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 22; j++) {
            if (mv3[i][j] == 10) {
                loq = i;
                loq1 = j;
                fantasma_x = i;
                fantasma_y = j;
                bloco_original_fantasma = 0; // Espaço vazio
                fantasma_inicializado = true;
                break;
            }
        }
        if (fantasma_inicializado) break;
    }

    while(condicao != "vitoria") {    
        // Clear screen and redraw maze
        cout << "\033[2J\033[H";
        plab(mv3, malt3, mlar3);
        cin >> direct;
        
        // Right movement
        if(direct == "direita" || direct == "Direita" || direct == "Right" || direct == "D" || direct == "d") {
            if(loc1 + 1 < mlar3 && mv3[loc][loc1 + 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc1 + 1 < mlar3 && mv3[loc][loc1 + 1] == 4) {
                // Press button and remove obstacles
                for(int i = 0; i < malt3; i++) {
                    for(int j = 0; j < mlar3; j++) {
                        if(mv3[i][j] == 6) mv3[i][j] = 0;
                    }
                }
                mv3[loc][loc1] = 0;
                mv3[loc][loc1 + 1] = 2;
                loc1++;
            }
            else if(loc1 + 1 < mlar3 && (mv3[loc][loc1 + 1] == 1 || mv3[loc][loc1 + 1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv3[loc][loc1 + 1] = -1;
            } 
            else if(loc1 + 2 < mlar3 && mv3[loc][loc1 + 1] == 7 && mv3[loc][loc1 + 2] == 0) {
                mv3[loc][loc1 + 1] = 2;
                mv3[loc][loc1 + 2] = 7;
                mv3[loc][loc1] = 0;
                loc1++;
            }    
            else if(loc1 + 1 < mlar3 && mv3[loc][loc1 + 1] == 0) {
                mv3[loc][loc1] = 0;
                mv3[loc][loc1 + 1] = 2;
                loc1++;
            }
            else if(mv3[loc][loc1+1] == 8){
                for(int i = 0; i < malt3; i++) {
                    for(int j = 0; j < mlar3; j++) {
                        if(mv3[i][j] == 9) {
                            mv3[loc][loc1] = 0;
                            mv3[i][j+1] = 2;
                            loc = i;
                            loc1 = j+1;
                            break;
                        }
                    }
                }
            }
        }
        // Left movement
        else if(direct == "esquerda" || direct == "Esquerda" || direct == "Left" || direct == "A" || direct == "a") {
            if(loc1 - 1 >= 0 && mv3[loc][loc1 - 1] == 3) {
                condicao = "vitoria";
                break;
            }
            
            if(loc1 - 1 >= 0 && mv3[loc][loc1 - 1] == 4) {
                // Press button and remove obstacles
                for(int i = 0; i < malt3; i++) {
                    for(int j = 0; j < mlar3; j++) {
                        if(mv3[i][j] == 6) mv3[i][j] = 0;
                    }
                }
                mv3[loc][loc1] = 0;
                mv3[loc][loc1 - 1] = 2;
                loc1--;
            }
            else if(loc1 - 1 >= 0 && (mv3[loc][loc1 - 1] == 1 || mv3[loc][loc1 - 1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv3[loc][loc1 - 1] = -1;
            } 
            else if(loc1 - 2 >= 0 && mv3[loc][loc1 - 1] == 7 && mv3[loc][loc1 - 2] == 0) {
                mv3[loc][loc1 - 1] = 2;
                mv3[loc][loc1 - 2] = 7;
                mv3[loc][loc1] = 0;
                loc1--;
            }
            else if(loc1 - 1 >= 0 && mv3[loc][loc1 - 1] == 0) {
                mv3[loc][loc1] = 0;
                mv3[loc][loc1 - 1] = 2;
                loc1--;
            }
            else if(mv3[loc][loc1-1] == 9){
                for(int i = 0; i < malt3; i++) {
                    for(int j = 0; j < mlar3; j++) {
                        if(mv3[i][j] == 8) {
                            mv3[loc][loc1] = 0;
                            mv3[i][j-1] = 2;
                            loc = i;
                            loc1 = j-1;
                            break;
                        }
                    }
                }
            }    
        }
        // Up movement
        else if(direct == "cima" || direct == "Cima" || direct == "Up" || direct == "W" || direct == "w") {
            if(loc - 1 >= 0 && mv3[loc - 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            else if(mv3[loc-1][loc1] == 11){
                for(int i = 0; i < malt3; i++) {
                    for(int j = 0; j < mlar3; j++) {
                        if(mv3[i][j] == 5) {
                            mv3[loc][loc1] = 0;
                            mv3[i-1][j] = 2;
                            loc = i-1;
                            loc1 = j;
                            break;
                        }
                    }
                }
            }
            
            
            if(loc - 1 >= 0 && mv3[loc - 1][loc1] == 4) {
                // Press button and remove obstacles
                for(int i = 0; i < malt3; i++) {
                    for(int j = 0; j < mlar3; j++) {
                        if(mv3[i][j] == 6) mv3[i][j] = 0;
                    }
                }
                mv3[loc][loc1] = 0;
                mv3[loc - 1][loc1] = 2;
                loc--;
            }
            else if(loc - 1 >= 0 && (mv3[loc - 1][loc1] == 1 || mv3[loc - 1][loc1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv3[loc - 1][loc1] = -1;
            } 
            else if(loc - 2 >= 0 && mv3[loc - 1][loc1] == 7 && mv3[loc - 2][loc1] == 0) {
                mv3[loc - 1][loc1] = 2;
                mv3[loc - 2][loc1] = 7;
                mv3[loc][loc1] = 0;
                loc--;
            }
            else if(loc - 1 >= 0 && mv3[loc - 1][loc1] == 0) {
                mv3[loc][loc1] = 0;
                mv3[loc - 1][loc1] = 2;
                loc--;
            }
        }
        // Down movement
        else if(direct == "baixo" || direct == "Baixo" || direct == "Down" || direct == "S" || direct == "s") {
            if(loc + 1 < malt3 && mv3[loc + 1][loc1] == 3) {
                condicao = "vitoria";
                break;
            }
            else if(mv3[loc+1][loc1] == 5){
                for(int i = 0; i < malt3; i++) {
                    for(int j = 0; j < mlar3; j++) {
                        if(mv3[i][j] == 11) {
                            mv3[loc][loc1] = 0;
                            mv3[i+1][j] = 2;
                            loc = i+1;
                            loc1 = j;
                            break;
                        }
                    }
                }
            }
            if(loc + 1 < malt3 && mv3[loc + 1][loc1] == 4) {
                // Press button and remove obstacles
                for(int i = 0; i < malt3; i++) {
                    for(int j = 0; j < mlar3; j++) {
                        if(mv3[i][j] == 6) mv3[i][j] = 0;
                    }
                }
                mv3[loc][loc1] = 0;
                mv3[loc + 1][loc1] = 2;
                loc++;
            }
            else if(loc + 1 < malt3 && (mv3[loc + 1][loc1] == 1 || mv3[loc + 1][loc1] == -1)) {
                cout << "Você bateu na parede!" << endl;
                mv3[loc + 1][loc1] = -1;
            } 
            else if(loc + 2 < malt3 && mv3[loc + 1][loc1] == 7 && mv3[loc + 2][loc1] == 0) {
                mv3[loc + 1][loc1] = 2;
                mv3[loc + 2][loc1] = 7;
                mv3[loc][loc1] = 0;
                loc++;
            }
            else if(loc + 1 < malt3 && mv3[loc + 1][loc1] == 0) {
                mv3[loc][loc1] = 0;
                mv3[loc + 1][loc1] = 2;
                loc++;
            }
        }
        
        // --- MOVIMENTAÇÃO DO FANTASMA ---
        // 1. Restaura o bloco na posição atual do fantasma
        mv3[fantasma_x][fantasma_y] = bloco_original_fantasma;
        
        // 2. Calcula direção para o jogador
        int dx = loc - fantasma_x;
        int dy = loc1 - fantasma_y;
        int novo_x = fantasma_x;
        int novo_y = fantasma_y;
        
        // 3. Escolhe a melhor direção
        if (abs(dx) > abs(dy)) {
            if (dx > 0) novo_x++; // Direita
            else novo_x--;        // Esquerda
        } else {
            if (dy > 0) novo_y++; // Baixo
            else novo_y--;       // Cima
        }
        
        // 4. Verifica se a nova posição é válida
        if (novo_x >= 0 && novo_x < malt3 && novo_y >= 0 && novo_y < mlar3) {
            // Atualiza a posição do fantasma
            bloco_original_fantasma = mv3[novo_x][novo_y];
            mv3[novo_x][novo_y] = 10;
            fantasma_x = novo_x;
            fantasma_y = novo_y;
        } else {
            // Se movimento inválido, mantém na posição atual
            mv3[fantasma_x][fantasma_y] = 10;
        }
        
        // Atualiza as variáveis globais do fantasma
        loq = fantasma_x;
        loq1 = fantasma_y;
        
        // Verificação de colisão
        if ((abs(locx - fantasma_x) <= 0 && abs(locy - fantasma_y;) <= 1)) {
            
            cout << "YOU LOSE!!!" << endl;
            sleep(5);
            return 1;
        }
        
} 
    
    
    if(condicao == "vitoria")  
    {  
    cout << "\033[2J\033[H";
cout << "██████╗  █████╗ ██████╗  █████╗ ██████╗ ███████╗ ███╗   ██╗ ███████╗" << endl;
cout << "██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝ ████╗  ██║ ██╔════╝" << endl;
cout << "██████╔╝███████║██████╔╝███████║██████╔╝█████╗   ██╔██╗ ██║ ███████╗" << endl;
cout << "██╔═══╝ ██╔══██║██╔══██╗██╔══██║██╔══██╗██╔══╝   ██║╚██╗██║ ╚════██║" << endl;
cout << "██║     ██║  ██║██║  ██║██║  ██║██║  ██║███████╗ ██║ ╚████║ ███████║" << endl;
cout << "╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝ ╚═╝  ╚═══╝ ╚══════╝" << endl << endl <<endl;

sleep(2);

     cout << "          Você completou a beta do jogo" <<endl;
    }
    return 0;
}
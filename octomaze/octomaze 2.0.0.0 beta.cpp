#include <iostream>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <string> 
#include <termios.h>

using namespace std;
struct termios originalTermio;
int linha, coluna;
string level;
int locx, locy; 
char ultecla;

void restaurarTerminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &originalTermio);
}

void lerTecla() {
    struct termios newt;
    
    
    tcgetattr(STDIN_FILENO, &originalTermio);
    
    newt = originalTermio;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    ultecla = getchar();
    
    
    restaurarTerminal();
}

void lab(int lab[40][40], int largura, int altura) {
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


void fase(int v[][40]) {
    ifstream arquivo("fases.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    
    arquivo >> level;
    arquivo >> linha;
    arquivo >> coluna;
    
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            arquivo >> v[i][j]; 
        }
    }
    arquivo.close();
}


void playerloc(int v[][40], int alt, int larg, int &locx, int &locy) {
    for (int i = 0; i < larg; i++) {
        for (int j = 0; j < alt; j++) {
            if (v[i][j] == 2) {
                locx = i;
                locy = j;
                return; // Adicionei return para eficiência
            }
        }
    }
}

void move(int v[][40], char ultima, int &locx, int &locy) {
    int new_x = locx;
    int new_y = locy;
    
    if(ultima == 'w') {
        new_x = locx - 1;
    }
    else if(ultima == 'a') {
        new_y = locy - 1;
    }
    else if(ultima == 'd') {
        new_y = locy + 1;
    }
    else if(ultima == 's') {
        new_x = locx + 1;
    }
    
    
    if (new_x >= 0 && new_x < linha && new_y >= 0 && new_y < coluna) {
        v[locx][locy] = 0;       
        v[new_x][new_y] = 2;     
        locx = new_x;            
        locy = new_y;
    }
}

void limpar() {
    system("clear");
}

int main() {
    cin >> level;
    // Carrega a fase
    int v[40][40];
    fase(v);
    
    // Encontra a posição do jogador
    playerloc(v, coluna, linha, locx, locy);
    
    cout << "Level: " << level << endl;
    cout << "Pressione teclas W-A-S-D (Q para sair)...";
    
    while (true) {
        limpar();
        lab(v, linha, coluna);
        cout << "\nUse W-A-S-D para mover (Q para sair)" << endl;
        
        lerTecla(); // Lê a tecla
        
        if (ultecla == 'q' || ultecla == 'Q') break;
        
        if (ultecla == 'w' || ultecla == 'a' || ultecla == 's' || ultecla == 'd') {
            move(v, ultecla, locx, locy);
        }
    }
    
    return 0;
}

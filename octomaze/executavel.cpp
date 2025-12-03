#include <iostream>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <string> 
#include <termios.h>
#include "texto.h"
#include <cstdlib>

using namespace std;
struct termios originalTermio;

typedef struct falas{
    string dicas;
    string dialogos;
}falas;

const int largura = 30, altura = 18;
//variaveis globais

char ultecla;//ultima tecla usada

int locx = -1,locy = -1; //variaveis de localização do player

string atual; //valor da posição atual do player


string prox; //pega o bloco da proxima posição

int loc = -1, loc1 = -1; //variaveis de localização temporaria
/************************/

int timer = 0, pontos = 0; //variaveis de pontuação

int bombas = 0, vidas = 3; // interativos do menu

int uso = 0; //indice do timer

int timer_global = 0, pontos_global = 0; //pontuação final

int silver_key = -1,gold_key = -1;


/************************/


int nivel_atual = 0; //fase que está sendo jogada

int fase_atual,linha,coluna;//referentes ao nivel atual

/************************/

int bomba_explosion = 4, timer_explosion = -1;

string explosion = "off";


char cima = 'w', baixo = 's',direita = 'd',esquerda = 'a', confirmar = 'z';



string relogio[12] = {
    "🕐", "🕑", "🕒", "🕓", "🕔", "🕕", "🕖", "🕗", "🕘", "🕙",
    "🕚", "🕛"
};

string alfabeto[26]={
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", 
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
    "u", "v", "w", "x", "y", "z"};

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

void limpar() {
    system("clear");
}


void palavras(string v[18][30]){
    if(ultecla == 'w' || ultecla == cima)
    {
        for(int i = 0;i<26;i++)
        {
            if(v[locx -1][locy] == alfabeto[i])
            {
                cout << "funcionou 2" <<endl; 
                if((v[locx-1][locy] == "t" && v[locx-2][locy] == "c" && v[locx-3][locy] == "o" &&
                    v[locx-4][locy] == "e" && v[locx-5][locy] == "r" && v[locx-6][locy] == "a" &&
                    v[locx-7][locy] == "u" && v[locx-8][locy] == "o" && v[locx-9][locy] == "y"))
                    {
                    v[locx][locy] = "B$";
                    atual = "B$";
                    }
            }
        }

    }

}

//vetor, largura, altura
void pfase(string v[altura][largura]){
    for(int i = 0; i < altura; i++)
    {
        for(int j = 0; j < largura; j++)
        {   //cenario
            if(v[i][j] == "-1")
                cout << "\033[31m██\033[0m";
            else if(v[i][j] == "0")
                cout << "  ";
            else if(v[i][j] == "1")
                cout << "██";
            
            //controlaveis
            else if(v[i][j] == "oct")
                cout << "👾";
            
            else if(v[i][j] == "xxx")
                cout << "???";

            //interativos
            else if(v[i][j] == "11")
                cout << "💣";
            else if(v[i][j] == "22")    
                cout << "💥";
            else if(v[i][j] == "33")    
                cout << "🔥";
            else if(v[i][j] == "44")
                cout << "\033[37m⛆⛆\033[0m";

            else if(v[i][j] == "13")
                cout << "🗝️ ";
            else if(v[i][j] == "23")
                cout << "🔑";
            else if(v[i][j] == "dicas")
                cout <<"🪧 ";

            //money money money
            else if(v[i][j] == "R$")
                cout << "💎";
            else if(v[i][j] == "B$")
                cout << "💰";
            else if(v[i][j] == "$$$")
                cout << "💷";
            else if(v[i][j] == "$$")
                cout << "💶";
            else if(v[i][j] == "$")
                cout << "💵";
        
            //letras
            else if(v[i][j] == "a")
                cout << "\033[34m🇦 \033[0m";
            else if(v[i][j] == "b")
                cout << "\033[34m🇧 \033[0m";
            else if(v[i][j] == "c")
                cout << "\033[34m🇨 \033[0m";
            else if(v[i][j] == "d")
                cout << "\033[34m🇩 \033[0m";
            else if(v[i][j] == "e")
                cout << "\033[34m🇪 \033[0m";
            else if(v[i][j] == "f")
                cout << "\033[34m🇫 \033[0m";
            else if(v[i][j] == "g")
                cout << "\033[34m🇬 \033[0m";
            else if(v[i][j] == "h")
                cout << "\033[34m🇭 \033[0m";
            else if(v[i][j] == "i")
                cout << "\033[34m🇮 \033[0m";
            else if(v[i][j] == "j")
                cout << "\033[34m🇯 \033[0m";
            else if(v[i][j] == "k")
                cout << "\033[34m🇰 \033[0m";
            else if(v[i][j] == "l")
                cout << "\033[34m🇱 \033[0m";
            else if(v[i][j] == "m")
                cout << "\033[34m🇲 \033[0m";
            else if(v[i][j] == "n")
                cout << "\033[34m🇳 \033[0m";
            else if(v[i][j] == "o")
                cout << "\033[34m🇴 \033[0m";
            else if(v[i][j] == "p")
                cout << "\033[34m🇵 \033[0m";
            else if(v[i][j] == "q")
                cout << "\033[34m🇶 \033[0m";
            else if(v[i][j] == "r")
                cout << "\033[34m🇷 \033[0m";
            else if(v[i][j] == "s")
                cout << "\033[34m🇸 \033[0m";
            else if(v[i][j] == "t")
                cout << "\033[34m🇹 \033[0m";
            else if(v[i][j] == "u")
                cout << "\033[34m🇺 \033[0m";
            else if(v[i][j] == "v")
                cout << "\033[34m🇻 \033[0m";
            else if(v[i][j] == "w")
                cout << "\033[34m🇼 \033[0m";
            else if(v[i][j] == "x")
                cout << "\033[34m🇽 \033[0m";
            else if(v[i][j] == "y")
                cout << "\033[34m🇾 \033[0m";
            else if(v[i][j] == "z")
                cout << "\033[34m🇿 \033[0m";
            
        }
    cout << endl;
    }
}

void buscar_item(string v[18][30], string X){
for(int i = 0; i < altura;i++)
    {
    for(int j = 0;j<largura;j++)
        {
        if(v[i][j] == X)
        {
        loc = i;
        loc1 = j;
        return;
        }
        }
    }


}

//vetor,largura,altura,valor procurado
void buscar_player(string v[altura][largura],string X){
for(int i = 0; i < altura;i++)
    {
    for(int j = 0;j<largura;j++)
        {
        if(v[i][j] == X)
        {
        locx = i;
        locy = j;
        atual = v[locx][locy];
        return;
        }
        }
    }

}

//mostra o HUD
void HUD(){ 
cout << "🪙  " << pontos << "     " << relogio[uso] << " " << timer
     << "     💣      " << bombas << "      ❤️ " << vidas <<   endl;
if(silver_key > 0) cout << "🗝️   " << silver_key;
if(gold_key > 0) cout <<   "🔑   " << gold_key;
cout << endl;
uso = (uso + 1)% 12;
timer_global++;
timer++;

}

//ler a fase atual
void ler_fase(string v[altura][largura]){

    static ifstream arquivo("fases.txt"); // Abre só uma vez
    static bool primeira_vez = true;
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    
    // Lê os dados do arquivo
    arquivo >> fase_atual;
    
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            arquivo >> v[i][j]; 
        }
    }
    (!primeira_vez);
    // Arquivo permanece aberto para a próxima leitura!

}

//move o personagem
void move(string v[altura][largura], int locx,int locy){
    string armazena;

if(ultecla == 'z' || ultecla == confirmar)
    {
        if(v[locx -1][locy] == "dicas")
        cout <<"funciona";

        else if(v[locx -1][locy] == "11") 
        {
            explosion = "on";
            //beep();//CONCERTAR
            
        }
    }

    if(timer_global  != timer_explosion && explosion == "on")
        {        
        bomba_explosion--;

            timer_explosion = timer_global;
            if(bomba_explosion == 0)
            {
            buscar_item(v,"11");
            for(int i = loc -1;i < loc + 2;i++)
            {
                for(int j = loc1 -1; j < loc1 +2;j++)
                {
                    v[i][j] = "22";
                }
            }
            limpar();
            pfase(v);
            sleep(0.755);

            for(int i = loc -1;i < loc + 2;i++)
            {
                for(int j = loc1 -1; j < loc1 +2;j++)
                {
                    v[i][j] = "33";
                }
            }
            limpar();
            pfase(v);
            sleep(0.755);

            for(int i = loc -1;i < loc + 2;i++)
            {
                for(int j = loc1 -1; j < loc1 +2;j++)
                {
                    v[i][j] = "44";
                }
            }

            limpar();
            pfase(v);
            sleep(0.755);

            for(int i = loc -1;i < loc + 2;i++)
            {
                for(int j = loc1 -1; j < loc1 +2;j++)
                {
                    v[i][j] = "0";
                }
            }
            
            explosion = "off";
            }
        }    

     if(ultecla == 'w')
    {
    prox = v[locx - 1][locy];
    if(v[locx -1][locy] == "1")
        v[locx -1][locy] = "-1";

    else if(v[locx -1][locy] == "0")
        {
        v[locx -1][locy] = atual;
        v[locx][locy] = "0";
        }

    else if(v[locx-1][locy] == "$")
    {
        pontos = pontos + 100;
        v[locx][locy] = "0";
        v[locx -1][locy] = atual;
    }
    else if(v[locx-1][locy] == "$$")
    {
        pontos = pontos + 300;
        v[locx][locy] = "0";
        v[locx -1][locy] = atual;
    }

    else if(v[locx-1][locy] == "$$$")
    {
        pontos = pontos + 500;
        v[locx][locy] = "0";
        v[locx -1][locy] = atual;
    }
    else if(v[locx-1][locy] == "B$")
    {
        pontos = pontos + 1000;
        v[locx][locy] = "0";
        v[locx -1][locy] = atual;
    }   
    else if(v[locx-1][locy] == "R$")
    {
        pontos = pontos + 5000;
        v[locx][locy] = "0";
        v[locx -1][locy] = atual;
    }



    //OBRIGATOTIAMENTE AS ULTIMAS FUNÇÔES DE MOVE
    else if(v[locx-2][locy] == "0" )
    {
        v[locx][locy] = "0";
        armazena = v[locx-1][locy];
        
        v[locx -2][locy] = armazena;
        v[locx-1][locy] = atual;
    }
    


    else
        palavras(v);
    
    
}
    

else if(ultecla == 's')
    {
    prox = v[locx + 1][locy];
        if(v[locx +1][locy] == "1")
        v[locx +1][locy] = "-1";

    else if(v[locx +1][locy] == "0")
        {
        v[locx][locy] = "0";
        v[locx +1][locy] = atual;
        }
    else if(v[locx+2][locy] == "0" )
    {
        v[locx][locy] = "0";
        armazena = v[locx+1][locy];
            
        v[locx +2][locy] = armazena;
        v[locx+1][locy] = atual;
            
    }

    }

else if(ultecla == 'a')
    {
    prox = v[locx][locy-1];
        if(v[locx][locy - 1] == "1")
        v[locx][locy -1] = "-1";

    else if(v[locx][locy-1] == "0")
        {
        v[locx][locy] = "0";
        v[locx][locy -1] = atual;
        }
    else if(v[locx][locy-2] == "0" )
    {
        v[locx][locy] = "0";
        armazena = v[locx][locy-1];
            
        v[locx][locy-2] = armazena;
        v[locx][locy-1] = atual;
            
    }

    }

else if(ultecla == 'd')
    {
    prox = v[locx][locy+1];
        if(v[locx][locy + 1] == "1")
        v[locx][locy +1] = "-1";

    else if(v[locx][locy+1] == "0")
        {
        v[locx][locy] = "0";
        v[locx][locy +1] = atual;
        }
    
    else if(v[locx][locy+2] == "0" )
    {
        v[locx][locy] = "0";
        armazena = v[locx][locy+1];
            
        v[locx][locy+2] = armazena;
        v[locx][locy+1] = atual;
            
    }
}
}

//limpa a tela

//função referente a tudo sobre o menu
void menu_principal(){
int menu = 0;
menu_puro();
sleep(1);
//escolher opção do menu principal
while(ultecla != 'z' && ultecla != confirmar)
{
    lerTecla();
    limpar();
    if(ultecla == 'w' || ultecla == cima)
        menu = (menu - 1 + 3)%3;
    else if(ultecla == 's' || ultecla == baixo)
        menu = (menu + 1)%3;

    if(menu == 0)
        menu_jogar();
    else if(menu == 1)
        menu_novo_jogo();
    else if(menu == 2)
        menu_option();
    sleep(0.3);
}
limpar();

if(menu == 0)
    return;

else if(menu == 1)
    return;

    //escolher opção dentro do option
else if(menu == 2)
    {   int option = 0;
        ultecla = '`';
        option_puro();
        sleep(1);
        while(ultecla != 'z' && ultecla != confirmar)
        {
        lerTecla();
        limpar();
        sleep(0.3);
        if(ultecla == 'w' || ultecla == cima)
            option = (option + 1)%3;
        else if(ultecla == 's' || ultecla == baixo)
            option = (option +2)%3;

        if(option == 0)
            option_alterar_controles();
        else if(option == 1)
            option_escolher_fase();
        else if(option == 2)
            option_modo_dificil();

        
        }
        if(option == 0)
        {
        limpar();
        int key_bind = 0;
        keybind();
            while(ultecla != 'x'){
                lerTecla();
                limpar();

                if(ultecla == 'w' || ultecla == cima)
                    key_bind = (key_bind + 3)%4;
                else if(ultecla == 's' || ultecla == baixo)
                    key_bind = (key_bind +1)%4;


                if(key_bind == 0)
                    keybind_cima(" ");
                else if(key_bind == 1)
                    keybind_baixo(" ");
                else if(key_bind == 2)
                    keybind_esquerda(" ");
                else if(key_bind == 3)
                    keybind_direita(" ");

                if(ultecla == 'z' || ultecla == confirmar )
                    limpar();
                if((ultecla == 'z' || ultecla == confirmar )&& key_bind == 0)
                {
                    keybind_cima("sim");
                        cout << "Digite uma tecla" <<endl;
                    lerTecla();
                    if(ultecla == 'w' || ultecla == 's' || ultecla == 'a' || ultecla == 'd' || ultecla == 'z' || ultecla == 'x')
                    {
                        cout << "Valor invalido!"<<endl;
                        sleep(2);
                        ultecla = '`';
                    }
                    else 
                    cima = ultecla;
                    limpar();
                    keybind_cima(" ");
                }
                else if((ultecla == 'z' || ultecla == confirmar )&& key_bind == 1)
                {
                    keybind_baixo("sim");
                        cout << "Digite uma tecla" <<endl;
                    lerTecla();
                    if(ultecla == 'w' || ultecla == 's' || ultecla == 'a' || ultecla == 'd' || ultecla == 'z' || ultecla == 'x')
                    {
                        cout << "Valor invalido!"<<endl;
                        sleep(2);
                        ultecla = '`';
                    }
                    else 
                    baixo = ultecla;
                    limpar();
                    keybind_baixo(" ");
                }

                else if((ultecla == 'z' || ultecla == confirmar )&& key_bind == 2)
                {
                    keybind_esquerda("sim");
                        cout << "Digite uma tecla" <<endl;
                    lerTecla();
                    if(ultecla == 'w' || ultecla == 's' || ultecla == 'a' || ultecla == 'd' || ultecla == 'z' || ultecla == 'x')
                    {
                        cout << "Valor invalido!"<<endl;
                        sleep(2);
                        ultecla = '`';
                    }
                    else 
                        esquerda = ultecla;

                    limpar();
                    keybind_esquerda(" ");
                }
                else if((ultecla == 'z' || ultecla == confirmar )&& key_bind == 3)
                {
                    keybind_direita("sim");
                        cout << "Digite uma tecla" <<endl;
                    lerTecla();
                    if(ultecla == 'w' || ultecla == 's' || ultecla == 'a' || ultecla == 'd' || ultecla == 'z' || ultecla == 'x')
                    {
                        cout << "Valor invalido!"<<endl;
                        sleep(2);
                        ultecla = '`';
                    }
                    else 
                        direita = ultecla;
                    limpar();
                    keybind_direita(" ");
                }
            }
        }
    
    
        else if(option == 1)
            {
                
            }
    
    
    
    
    }

}

void acicionar_dialogos(){
    ifstream arquivo("fases.txt"); // Abre só uma vez
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    

}

int main(){

//bem_vindo();
string fase[18][30] = {
    {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
    {"1","0","y","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","o","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","u","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","a","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","r","0","0","0","0","0","0","0","0","R$","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","e","0","0","0","y","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","o","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","c","0","0","0","0","0","0","0","0","0","0","0","dicas","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","t","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","oct","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","0","0","0","0","0","0","0","22","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","0","11","0","0","0","0","0","0","0","s","0","0","t","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","0","0","0","0","13","0","0","0","0","i","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"}
};


//menu_principal();
//menu_principal();
buscar_player(fase,"oct");
while(ultecla != 'k' || vidas <= 0){
    
buscar_player(fase,atual);
limpar();
HUD();
pfase(fase);
lerTecla();
move(fase,locx,locy);
//push(fase);
}

return 0;}
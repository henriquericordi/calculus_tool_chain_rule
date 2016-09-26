#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void cabecalho(void);
string inttostring (int);
void limpatela(void);
string inserir_funcao(void);
void derivada(string);
string copiar(string);
void derivada_dentro(string);
void simplificacao(string);

string primaria = "";
int x, y;

void cabecalho(void){
    cout << "+--------------------------------------------------------------+\n";
    cout << "|Software para Cálculo de Derivadas Compostas (Regra da Cadeia)|\n";
    cout << "|UENP/CLM - CCT - Ciência da Computação - Professora: Caroline |\n";
    cout << "|Alunos: Rafael dos Santos Braz  || José Henrique Ricordi Cruz |\n";
    cout << "+--------------------------------------------------------------+\n\n";
}

void limpatela(void){
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef __linux__
    system("clear");
    #endif
}

string inserir_funcao(void){
    string funcao;
    cout << "f(x)=";
    getline(cin, funcao);
    return funcao;
}

void derivada(string funcao){
    for (int cont = 0; cont < funcao.length(); cont++){
        funcao[cont] = tolower(funcao[cont]);
    }
    cout << "f'(x)=";
    if (funcao.find("-sen") != -1){
        primaria += "-cos(" + copiar(funcao) + ")*";
        derivada_dentro(copiar(funcao));
    } else if (funcao.find("-cos") != -1 ){
        primaria += "sen(" + copiar(funcao) + ")*";
        derivada_dentro(copiar(funcao));
    } else if (funcao.find("sen") != -1 ){
        primaria += "cos(" + copiar(funcao) + ")*";
        derivada_dentro(copiar(funcao));
    } else if (funcao.find("cos") != -1 ){
        primaria += "-sen(" + copiar(funcao) + ")*";
        derivada_dentro(copiar(funcao));
    }
    cout << endl;
}

string copiar(string funcao){
    string f = "";
    for (int c = funcao.find('(') + 1; c < funcao.find(')'); c++){
        f += funcao[c];
    }
    return f;
}

string inttostring (int n){
  stringstream s;
  s << n;
  return s.str();
}

void derivada_dentro(string funcao){
    string f1 = "", f2 = "", mostrar = "";
    string f1_1 = "", f1_2 = "";
    string f2_1 = "", f2_2 = "";
    for (int c = 0; c < funcao.find('^'); c++){
        f1 += funcao[c];
    }
    for (int c = funcao.find('^') + 1; c < funcao.length(); c++){
        f2 += funcao[c];
    }
    int statusf1 = f1.find('*');
    int statusf2 = f2.find('*');
    if (statusf1 != -1){
        for (int c = 0; c < statusf1; c++){
            f1_1 += f1[c];
        }
        for (int c = statusf1 + 1; c < f1.length(); c++){
            f1_2 += f1[c];
        }
    }
    if (statusf2 != -1){
        for (int c = 0; c < statusf2; c++){
            f2_1 += f2[c];
        }
        for (int c = statusf2 + 1; c < f2.length(); c++){
            f2_2 += f2[c];
        }
    }
    if (statusf1 == -1 && statusf2 == -1){
        if (f1[0] != 'x'){
            mostrar += '0';
        } else{
            if (isdigit(f2[0]) && f2.length() == 1){
                if (f2.length() == 1){
                    if (f2[0] != '1'){
                        mostrar += f2 + '*' + f1;
                        int n = atoi(f2.c_str()) - 1;
                        mostrar += '^' + inttostring(n);
                    } else{
                        mostrar += f2 + '*' + f1;
                        int n = atoi(f2.c_str()) - 1;
                        mostrar += '^' + inttostring(n);
                    }
                } else{
                    mostrar += f2 + '*' + f1;
                    int n = atoi(f2.c_str()) - 1;
                    mostrar += '^' + inttostring(n);
                }
            } else if (f2.find('/') == -1){
                mostrar += f2 + '*' + f1 + '^' + f2 + "-1";
            } else if (f2.find('/') != -1){
                mostrar += f2 + '*' + f1 + '^' + '(' + f2 + ')' + "-1";
            }
        }
    } else if (statusf1 != -1 && statusf2 == -1){
        if (((f1_1.find('/') == -1 && f2.find('/') == -1) && (isdigit(f1_1[0]) || f1_1[0] == '-')) && (isdigit(f2[0]) || f2[0] == '-')){
            int n1 = atoi(f1_1.c_str());
            int n2 = atoi(f2.c_str());
            int aux = n1 * n2;
            int exp = n2 - 1;
            mostrar += inttostring(aux) + '*' + f1_2 + '^' + inttostring(exp);
        }  else if (f2.find('/') == -1 && f1_1.find('/') == -1){
            mostrar += f1_1 + '*' + f2 + '*' + f1_2 + '^' + f2 + "-1";
        } else if (f2.find('/') != -1 && f1_1.find('/') == -1){
            mostrar += f1_1 + '*' + '(' + f2 + ')' + '*' + f1_2 + '^' + '(' + f2 + ')' + "-1";
        } else if (f2.find('/') != -1 && f1_1.find('/') != -1){
            mostrar += '(' + f1_1 + ')' + '*' + '(' + f2 + ')' + '*' + f1_2 + '^' + '(' + f2 + ')' + "-1";
        } else if (f2.find('/') == -1 && f1_1.find('/') != -1){
            mostrar += '(' + f1_1 + ')' + '*' + f2 + '*' + f1_2 + '^' + f2 + "-1";
        }
    } else if (statusf1 == -1 && statusf2 != -1){
        if (((isdigit(f2_1[0]) || f2_1[0] == '-') && f2_1.find('/') == -1) && ((isdigit(f2_2[0]) || f2_2[0] == '-') && f2_2.find('/') == -1)){
            int n1 = atoi(f2_1.c_str());
            int n2 = atoi(f2_2.c_str());
            int aux = n1 * n2;
            int exp = aux - 1;
            mostrar += inttostring(aux) + '*' + f1 + '^' + inttostring(exp);
        } else if ((f2_1.find('/') == -1) && (f2_2.find('/') == -1)){
            mostrar += f2 + '*' + f1 + '^' + f2 + "-1";
        } else if ((f2_1.find('/') == -1) && (f2_2.find('/') != -1)){
            mostrar += f2_1 + '*'+ '(' + f2_2 + ')' + '*' + f1 + '^' + f2_1 + '*'+ '(' + f2_2 + ')' + "-1";
        } else if ((f2_1.find('/') != -1) && (f2_2.find('/') == -1)){
            mostrar += '(' + f2_1 + ')' + '*' + f2_2 + '^' + '(' + f2_1 + ')' + '*' + f2_2 + "-1";
        } else if ((f2_1.find('/') != -1) && (f2_2.find('/') != -1)){
            mostrar += '(' + f2_1 + ')' + '*' + '(' + f2_2 + ')' + f1 + '^' + '(' + f2_1 + ')' + '*' + '(' + f2_2 + ')' + "-1";
        }
    } else if (statusf1 != -1 && statusf2 != -1){
        if (((isdigit(f2_1[0]) || f2_1[0] == '-') && f2_1.find('/') == -1) && ((isdigit(f2_2[0]) || f2_2[0] == '-') && f2_2.find('/') == -1) && ((isdigit(f1_1[0]) || f1_1[0] == '-') && f1_1.find('/') == -1)){
            int n1 = atoi(f2_1.c_str());
            int n2 = atoi(f2_2.c_str());
            int base = atoi(f1_1.c_str());
            int aux = n1 * n2;
            int exp = aux - 1;
            int aux2 = aux * base;
            mostrar += inttostring(aux2) + '*' + f1_2 + '^' + inttostring(exp);
        }
        else if ((f1_1.find('/') == -1) && (f2_1.find('/') == -1) && (f2_2.find('/') == -1)){
            mostrar += f1_1 + '*' + f2 + '*' + f1_2 + '^' + f2 + "-1";
        }
        else if ((f1_1.find('/') == -1) && (f2_1.find('/') == -1) && (f2_2.find('/') != -1)){
            mostrar += f1_1 + '*' + f2_1 + '*' + '(' + f2_2 + ')' + '*' + f1_2 + '^' + f2_1 + '*' + '(' + f2_2 + ')' + "-1";
        }
        else if ((f1_1.find('/') == -1) && (f2_1.find('/') != -1) && (f2_2.find('/') == -1)){
            mostrar += f1_1 + '*' + '(' + f2_1 + ')' + '*' + f2_2 + '*' + f1_2 + '^' + '(' + f2_1 + ')' + '*' + f2_2 + "-1";
        }
        else if ((f1_1.find('/') == -1) && (f2_1.find('/') != -1) && (f2_2.find('/') != -1)){
            mostrar += f1_1 + '*' + '(' + f2_1 + ')' + '*' + '(' + f2_2 + ')' + '*' + f1_2 + '^' + '(' + f2_1 + ')' + '*' + '(' + f2_2 + ')' + "-1";
        }
        else if ((f1_1.find('/') != -1) && (f2_1.find('/') == -1) && (f2_2.find('/') == -1)){
            mostrar += '(' + f1_1 + ')' + '*' + f2 + '*' + f1_2 + '^' + f2 + "-1";
        }
        else if ((f1_1.find('/') != -1) && (f2_1.find('/') == -1) && (f2_2.find('/') != -1)){
            mostrar += '(' + f1_1 + ')' + '*' + f2_1 + '*' + '(' + f2_2 + ')' + '*' + f1_2 + '^' + f2_1 + '*' + '(' + f2_2 + ')' + "-1";
        }
        else if ((f1_1.find('/') != -1) && (f2_1.find('/') != -1) && (f2_2.find('/') == -1)){
            mostrar += '(' + f1_1 + ')' + '*' + '(' + f2_1 + ')' + '*' + f2_2 + '*' + f1_2 + '^' + '(' + f2_1 + ')' + '*' + f2_2 + "-1";
        }
        else if ((f1_1.find('/') != -1) && (f2_1.find('/') != -1) && (f2_2.find('/') != -1)){
            mostrar += '(' + f1_1 + ')' + '*' + '(' + f2_1 + ')' + '*' + '(' + f2_2 + ')' + '*' + f1_2 + '^' + '(' + f2_1 + ')' + '*' + '(' + f2_2 + ')' + "-1";
        }
    }
    simplificacao(mostrar);
}

void simplificacao(string funcao){
    x = (funcao.find("0*"));
    string simplificada = funcao;
    if (funcao.find("*0") != -1 || x != -1){
        if((x == 0) || x != 0 && isdigit(x - 1) == false){
            simplificada = "0";
            primaria = "";
        }
        else{
            simplificada = funcao;
        }
    }
    else {
        simplificada = funcao;
    }
    x = simplificada.find("^1");
    if (x != -1){
        if (x + 1 == simplificada.length() - 1){
            simplificada.erase(x, 2);
        }
        else {
            if(isdigit(x + 2) == false){
                simplificada.erase(x, 2);
            }
        }
    }
    x = simplificada.find("^0");
    if (x != -1){
        if (x + 1 == simplificada.length() - 1){
            if (simplificada.find_last_of("*", x)){
                simplificada.erase(simplificada.find("*") + 1,x + 1);
                simplificada += '1';
            } else{
                simplificada.erase(0,x + 1);
                simplificada += '1';
            }
        }
    }
    x = simplificada.find("*1");
    if(x != -1){
        if (x + 1 == simplificada.length() - 1){
            simplificada.erase(x, 2);
            if (simplificada.length() == 1 && simplificada[0] == '1'){
                simplificada = "";
                primaria.erase(primaria.length() - 1 ,1);
            }
        }
    }
    x = simplificada.find("^");
    y = simplificada.find("-");
    if(x && y && isdigit(simplificada[y + 1]) && isdigit(simplificada[y - 1])){
        string simp1 = "", simp2 = "";
        for(int i = x + 1; i < y ; i++){
            simp1 += simplificada[i];
        }
        for(int i = y + 1; i < simplificada.length(); i++){
            simp2 += simplificada[i];
        }
        int n1 = atoi(simp1.c_str());
        int n2 = atoi(simp2.c_str());
        int aux = n1 - n2;
        simplificada.erase(x + 1);
        simplificada += inttostring(aux);
    }
    cout << primaria << simplificada << endl;
}

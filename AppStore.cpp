#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <climits>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<string>> content;
vector<string> row;
string line, word;

int optionMenu, inputPassword, passwordAux, password[2], limitShow;
string spacesToPrint;

void showGames();
void menuUser();
void menuAdmin();
void menuDeveloper();

void checkArchive();
void rewriteArchive();
void optionFail();
/*void checkUpper();*/

int main() {
    checkArchive();
    do
    {
        cout<<"--- --- ---  UAN MIST/VAPE/HAZE/FOG STORE  --- --- ---"<<endl<<endl; //Todos los nombres son sinonimos de Steam, por temas de copyright
        cout<<"1. Usuario"<<endl;  
        cout<<"2. Administrador"<<endl;
        cout<<"3. Developer"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<endl<<"Seleccione un perfil: "<<endl;
        cin>>optionMenu;
        optionFail();
        switch (optionMenu)
        {
        case 1:
            menuUser();
            break;
        case 2:
            cout<<endl<<"Ingrese la contraseña"<<endl;
            cin>>inputPassword;
            if (password[0] == inputPassword)
            {
                menuAdmin();
            }
            else
            {
                cout<<"Contraseña Erronea"<<endl;
            }
            break;

        case 3:
            cout<<endl<<"Ingrese la contraseña"<<endl;
            cin>>inputPassword;
            if (password[1] == inputPassword)
            {
                menuDeveloper();
            }
            else
            {
                cout<<"Contraseña Erronea"<<endl;
            }
            break;

        case 0:
            break;

        default:
            cout<<"Esa opcion no esta disponible"<<endl;
            break;
        }
    } while (optionMenu!=0);
    
    return 0;
}

void showGames()
{

}
void menuUser()
{
    cout<<"Hello World User"<<endl;
}
void menuAdmin()
{
    cout<<"Hello World Admin"<<endl;
}
void menuDeveloper()
{
    cout<<"Hello World Developer"<<endl;
}

void checkArchive()
{
	fstream baseDatos("Base_Datos_AppStore.txt", ios::in);
    if (baseDatos.is_open())
    {
        while (getline(baseDatos, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            	content.push_back(row);
        }
    }
    else
    {
        baseDatos.open("Base_Datos_AppStore.txt", ios::out);

        baseDatos << "Name,\n";
        baseDatos << "ID,\n";
        baseDatos << "Category,\n";
        baseDatos << "Size,\n";
        baseDatos << "Price,\n";
        baseDatos << "LicenciasDisponibles,\n";
        baseDatos << "LicenciasVendidas,\n";
        baseDatos << "Imagen,\n";
        baseDatos << "Passwords,\n";

        baseDatos.close();
        fstream baseDatos("Base_Datos_AppStore.txt", ios::in);

        while (getline(baseDatos, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            	content.push_back(row);
        }
    }

    baseDatos.close();

    std::string::size_type sz;
	passwordAux = stoi(content[8][1], &sz);
	password[0] = passwordAux;
	passwordAux = stoi(content[8][2], &sz);
	password[1] = passwordAux;
}
void rewriteArchive()
{
	ofstream baseDatos;

    baseDatos.open("Base_Datos_AppStore.txt", ios::out);

    for (int i = 0, j = 0; i < content.size(); i++)
    {
        for (; j < content[0].size(); j++)
        {
            if (j == content[0].size() - 1)
            {
                baseDatos << content[i][j] << "," << endl;
                break;
            }
            else
            {
                baseDatos << content[i][j] << ",";
            }
        }
        j = 0;
    }

    baseDatos.close();	
}
void optionFail()
{
	if (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Opción no valida" << endl;
        getchar();
    }
}

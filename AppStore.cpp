#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <climits>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<string>> content;
vector<vector<string>> passwordsVector;
vector<string> row;
string line, word;

int optionMenu, inputPassword, passwordAux, password[2], limitShow, sales, salesAUX;
string spacesToPrint;
char uSure;

class game
{
    public:
        string name;
        string category;
        unsigned int id;
        unsigned int price;
        unsigned int size;
        unsigned int totalLicencias;
        unsigned int licenciasVendidas;
};

void showGames();
void menuUser();
void menuAdmin();
    void menuSales();
    void menuTopSales();
void menuDeveloper();

void checkArchive();
void rewriteArchive();
void optionFail();
/*void checkUpper();*/

int main() {
    checkArchive();
    do
    {
        cout<<"--- --- ---  UAN MIST/HAZE/FOG STORE  --- --- ---"<<endl<<endl; //Todos los nombres son sinonimos de Steam, por temas de copyright
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
            optionMenu=7;
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
            optionMenu=7;
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
            optionMenu=7;
            break;

        case 0:
            cout << "Quiere cerrar el programa? - s/n" << endl;
            cin >> uSure;
            if (uSure == 's' || uSure == 'S')
            {
                rewriteArchive();
                break;
            }
            else
            {
                optionMenu = 7;
                system("clear");
                break;
            }
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
    do
    {
        cout<<"--- --- ---  Bienvenido Admin  --- --- ---"<<endl<<endl;
        cout<<"1. Comprar licencias"<<endl; //No hay mucho que explicar...
        cout<<"2. Catalogo de Juegos"<<endl; //Selecciòn de juegos para vender - dice cantidad de licencias de cada juego
        cout<<"3. Ventas"<<endl; //Cantidad de ventas totales, puede ver el top de juegos vendidos
        cout<<"0. Salir de Admin"<<endl;
        cin>>optionMenu;
        optionFail();
        switch (optionMenu)
        {
        case 1:
            //Abre catalogo de juegos, publicados por el developer
            break;
        case 2:
            //Abre catalgo de juegos ya comprados - de juegos de los que tiene licencia, si se acaban las licencias se va del caatalogo?
            break;

        case 3:
            do
            {
                cout<<"--- --- ---  Ventas  --- --- ---"<<endl<<endl;
                cout<<"1. Ventas Totales"<<endl;
                cout<<"2. Top Juegos"<<endl;
                cout<<"0. Salir del menu VENTAS"<<endl;
                cin>>optionMenu;
                optionFail();
                switch (optionMenu)
                {
                    case 1:
                        menuSales();
                        optionMenu = 7;
                        break;
                    case 2:
                        menuTopSales();
                        optionMenu = 7;
                        break;
                    case 0:
                        optionMenu = 7;
                        break;
                    default:
                        cout<<"Esa opcion no esta disponible"<<endl;
                        break;
                }
            } while (optionMenu!=7);
            break;

        case 0:
            break;
        default:
            cout<<"Esa opcion no esta disponible"<<endl;
            break;
        }
    } while (optionMenu!=0);
}
    void menuSales()
    {
        do
        {
            cout<<"--- --- ---  Ventas Totales  --- --- ---"<<endl<<endl;
            for (int j = 1; j < content[0].size(); j++)
            {
                std::string::size_type sz;
                salesAUX = stoi(content[8][j], &sz);
                sales = sales + salesAUX;
            }
            cout <<"El total de las ventas es de: $"<<sales<<endl<<endl;
            sales = 0;
            
            cout<<"0. Salir de Ventas Totales"<<endl;
            cin>>optionMenu;
            optionFail();
            switch (optionMenu)
            {
                case 0:
                    optionMenu=7;
                    break;
                default:
                    cout<<"Esa opcion no esta disponible"<<endl;
                    break;
            }
        } while (optionMenu!=7);
        
    }
    void menuTopSales()
    {

    }
void menuDeveloper()
{
    cout<<"Hello World Developer"<<endl;
    //dar la opción de poder subir sus juegos a un catalogo
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
    
	fstream basePasswords("Passwords.txt", ios::in);
    if (basePasswords.is_open())
    {
        while (getline(basePasswords, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            	passwordsVector.push_back(row);
        }
    }
    else
    {
        basePasswords.open("Passwords.txt", ios::out);

        basePasswords <<"Passwords,0,0,\n";

        basePasswords.close();
        fstream basePasswords("Passwords.txt", ios::in);

        while (getline(basePasswords, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            	passwordsVector.push_back(row);
        }
    }

    basePasswords.close();
    std::string::size_type sz;
	passwordAux = stoi(passwordsVector[0][1], &sz);
	password[0] = passwordAux;
	passwordAux = stoi(passwordsVector[0][2], &sz);
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

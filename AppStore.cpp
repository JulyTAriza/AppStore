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
            break;

        case 0:
            break;
        default:
            cout<<"Esa opcion no esta disponible"<<endl;
            break;
        }
    } while (optionMenu!=0);
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

        baseDatos << "Name,ID,Category,Size,Price,LicenciasDisponibles,LicenciasVendidas,Imagen" << endl;

        baseDatos << "Dont Starve,DS001,Aventura,1GB,4.99,100,50,Image1.jpg" << endl;
        baseDatos << "Starfield,SF002,Rol,125GB,59.99,200,100,Image2.jpg" << endl;
        baseDatos << "The Legend of Zelda: Breath of the Wild,ZL003,Aventura,13.4GB,59.99,500,250,Image3.jpg" << endl;
        baseDatos << "Red Dead Redemption 2,RD004,Acción,105GB,49.99,400,200,Image4.jpg" << endl;
        baseDatos << "The Elder Scrolls V: Skyrim,TS005,RPG,25GB,19.99,600,300,Image5.jpg" << endl;
        baseDatos << "Cyber Shadow,CS006,Plataforma,1GB,14.99,100,50,Image6.jpg" << endl;
        baseDatos << "Outer Worlds 2,OW007,RPG,35GB,49.99,400,200,Image7.jpg" << endl;


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

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <climits>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> content;
vector<vector<string>> passwordsVector;
vector<string> row;
string line, word;

int optionMenu, inputPassword, passwordAux, password[2], limitShow;
float sales, salesAUX;
string spacesToPrint;
char uSure;
const char LIMIT = ',';

class Game
{
    public:
        string name;
        string id;
        string category;
        string size;
        float price;
        unsigned int licenciasDisponibles;
        unsigned int licenciasVendidas;
        string imagen;
        bool compradoPorUsuario;
        Game() : compradoPorUsuario(false) {}
};
vector<Game> games;
Game videoGame;

void showGames();
void menuUser();
void menuAdmin();
void menuSales();
void menuTopSales();
void menuDeveloper();
void menuComprar();

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
                //rewriteArchive();
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
void menuComprar()
{
    cout << "--- --- ---  Comprar Licencias  --- --- ---" << endl << endl;
    cout << "Lista de juegos disponibles para comprar:" << endl;

    for (int i = 0; i < games.size(); i++)
    {
        Game& currentGame = games[i];
        cout << i + 1 << ". " << currentGame.name << " (ID: " << currentGame.id << ")" << endl;
    }

    int gameChoice;
    cout << "Seleccione el juego que desea comprar (ingrese el número): ";
    cin >> gameChoice;

    // Verificar si la elección está dentro del rango válido
    if (gameChoice >= 1 && gameChoice <= games.size())
    {
        Game& selectedGame = games[gameChoice - 1];

        if (selectedGame.licenciasDisponibles > 0)
        {
            // Realizar la compra
            selectedGame.licenciasVendidas++;
            selectedGame.licenciasDisponibles--;

            cout << "Licencia comprada con éxito para el juego: " << selectedGame.name << endl;
        }
        else
        {
            cout << "No quedan licencias disponibles para el juego seleccionado." << endl;
        }
    }
    else
    {
        cout << "Opción no válida. Por favor, seleccione un número de juego válido." << endl;
    }

    cout << "Presione Enter para continuar...";
    cin.ignore(); // Limpiar el búfer de entrada
    cin.get();    // Esperar a que el usuario presione Enter
}


void showGames() {
    cout << "Lista de juegos disponibles:" << endl;

    for (int i = 0; i < games.size(); i++) {
        cout << i + 1 << ". " << games[i].name << " (ID: " << games[i].id << ")" << endl;
    }
}

void menuUser()
{
    cout<<"Hello World User"<<endl;
    showGames();
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
            menuComprar();
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
            for (int i = 0; i < games.size(); i++)
            {
                videoGame = games[i];
                salesAUX = videoGame.price * videoGame.licenciasVendidas;
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
        do
        {
            cout<<"--- --- ---  Top Juegos Vendidos  --- --- ---"<<endl<<endl;
            //sort(content.begin(), content.end(), greater<int>());
            cout<<"0. Salir de Top Juegos"<<endl;
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
        string linea, name, id, category, size, price, licenciasDisponibles, licenciasVendidas, imagen, sales;
    	while (getline(baseDatos, linea))
    	{
    		stringstream input_stringstream(linea);
    		getline(input_stringstream, name, LIMIT);
    		getline(input_stringstream, id, LIMIT);
    		getline(input_stringstream, category, LIMIT);
    		getline(input_stringstream, size, LIMIT);
    		getline(input_stringstream, price, LIMIT);
    		getline(input_stringstream, licenciasDisponibles, LIMIT);
    		getline(input_stringstream, licenciasVendidas, LIMIT);
    		getline(input_stringstream, imagen, LIMIT);
    		videoGame.name = name;
    		videoGame.id = id;
    		videoGame.category = category;
    		videoGame.size = size;
    		videoGame.price = stof(price);
    		videoGame.licenciasDisponibles = stoi(licenciasDisponibles);
    		videoGame.licenciasVendidas = stoi(licenciasVendidas);
    		videoGame.imagen = imagen;
    		
    		games.push_back(videoGame);
    	}
    }
    else
    {
        baseDatos.open("Base_Datos_AppStore.txt", ios::out);

        //baseDatos << "Name,ID,Category,Size,Price,LicenciasDisponibles,LicenciasVendidas,Imagen" << endl;
        baseDatos << "Dont Satve,DS001,Aventura,1GB,4.99,100,50,Image1.jpg" << endl;
        baseDatos << "Starfield,SF002,Rol,125GB,59.99,200,100,Image2.jpg" << endl;
        baseDatos << "The Legend of Zelda: Breath of the Wild,ZL003,Aventura,13.4GB,59.99,500,250,Image3.jpg" << endl;
        baseDatos << "Red Dead Redemption 2,RD004,Acción,105GB,49.99,400,200,Image4.jpg" << endl;
        baseDatos << "The Elder Scrolls V: Skyrim,TS005,RPG,25GB,19.99,600,300,Image5.jpg" << endl;
        baseDatos << "Cyber Shadow,CS006,Plataforma,1GB,14.99,100,50,Image6.jpg" << endl;
        baseDatos << "Outer Worlds 2,OW007,RPG,35GB,49.99,400,200,Image7.jpg" << endl;

        baseDatos.close();
        fstream baseDatos("Base_Datos_AppStore.txt", ios::in);
        string linea, name, id, category, size, price, licenciasDisponibles, licenciasVendidas, imagen, sales;
        while (getline(baseDatos, linea))
    	{
    		stringstream input_stringstream(linea);
    		getline(input_stringstream, name, LIMIT);
    		getline(input_stringstream, id, LIMIT);
    		getline(input_stringstream, category, LIMIT);
    		getline(input_stringstream, size, LIMIT);
    		getline(input_stringstream, price, LIMIT);
    		getline(input_stringstream, licenciasDisponibles, LIMIT);
    		getline(input_stringstream, licenciasVendidas, LIMIT);
    		getline(input_stringstream, imagen, LIMIT);
    		videoGame.name = name;
    		videoGame.id = id;
    		videoGame.category = category;
    		videoGame.size = size;
    		videoGame.price = stof(price);
    		videoGame.licenciasDisponibles = stoi(licenciasDisponibles);
    		videoGame.licenciasVendidas = stoi(licenciasVendidas);
    		videoGame.imagen = imagen;
    		
    		games.push_back(videoGame);
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
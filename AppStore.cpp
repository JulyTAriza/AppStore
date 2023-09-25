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
        string secretDeveloperID;
        string imagen;
};
vector<Game> games;
Game videoGame;

void showGames();
void menuUser();
void menuAdmin();
void menuDeveloper();
    void menuSales();
    void menuTopSales();

void checkArchive();
void rewriteArchive();
void optionFail();
/*void checkUpper();*/

//Developer Functions
    // Subir 
        void uploadGame();
        void updateGameInDatabase();
        void generateUniqueID();
    //Editar 
        void editGameInformationInMemory();
        void editVideogameInformation();
        void displayGameInformation();
    //Actualizar 
        void uploadGameUpdates();
        void updateGame(Game &gameToUpdate, const string &updateVersion, const string &updateDescription);
        void displayUpdateInfo(const Game &gameToUpdate, const string &updateVersion, const string &updateDescription);
    //Ver
        void viewGameSales();



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

void showGames()
{
    for (int i = 0; i < games.size(); i++)
        {
            Game videoGame = games.at(i);
            cout << "Tenemos el juego " << videoGame.name << " con ID " << videoGame.id << "\n";
        }//Pendiente de mostrar más info
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
    //OBLIGATORIA
void menuDeveloper()
{
    cout<<"Hello World Developer"<<endl;
    int developerOption;
    do{
        cout << "--- --- ---  Menú de Desarrollador  --- --- ---" << endl << endl;
        cout << "1. Subir un juego" << endl;
        cout << "2. Editar información de un juego" << endl;
        cout << "3. Subir actualizaciones de un juego" << endl;
        cout << "4. Ver cuántos juegos has vendido" << endl;
        cout << "0. Salir del Menú de Desarrollador" << endl;
        cin >> developerOption;
        optionFail();

            switch (developerOption)
            {
            case 1:
                uploadGame();
                break;
            case 2:
                editVideogameInformation();
                break;
            case 3:
                uploadGameUpdates();
                break;
            case 4:
                viewGameSales();
                break;
            case 0:

                break;
            default:
                cout << "That option is not available" << endl;
                break;
            }
        } while (developerOption != 0);
}

//OBLIGATORIA
// Función para generar una ID única para un juego y asignarla a newGame
void generateUniqueID(Game &newGame)
{
    // Inicializa un generador de números pseudoaleatorios con una semilla basada en el tiempo actual
    mt19937 rng(static_cast<unsigned int>(time(nullptr)));

    // Crea una distribución uniforme de enteros en el rango [1000, 9999]
    uniform_int_distribution<int> dist(1000, 9999);

    // Genera una ID única usando la distribución y el generador de números aleatorios
    int uniqueID = dist(rng);

    // Convierte la ID única en una cadena y la asigna al juego
    newGame.id = to_string(uniqueID);
    cout << "La ID designada es: " << newGame.id << endl;
}

//OBLIGATORIA
void uploadGame()
{
    Game newGame;

    cout << "Ingrese el nombre del juego: ";
    cin.ignore(); // Ignora cualquier entrada pendiente en el búfer
    getline(cin, newGame.name);

    cout << "Ingrese la categoría del juego (Rompecabezas, acción o deporte): ";
    getline(cin, newGame.category);

    cout << "Ingrese el tamaño del juego: ";
    cin >> newGame.size;

    cout << "Ingrese el precio del juego: ";
    cin >> newGame.price;

    cout << "Ingrese la cantidad de licencias disponibles: ";
    cin >> newGame.licenciasDisponibles;

    newGame.licenciasVendidas = 0;

    cout << "Ingrese el nombre del archivo de imagen del juego: ";
    cin.ignore(); // Ignora cualquier entrada pendiente en el búfer
    getline(cin, newGame.imagen);

    // Generar la ID única y asignarla al juego
    generateUniqueID(newGame);

    games.push_back(newGame);

    ofstream baseDatos("Base_Datos_AppStore.txt", ios::app);
    if (baseDatos.is_open())
    {
        baseDatos << newGame.name << "," << newGame.id << "," << newGame.category << ","
                    << newGame.size << "," << newGame.price << ","
                    << newGame.licenciasDisponibles << "," << newGame.licenciasVendidas << ","
                    << newGame.imagen << endl;

        baseDatos.close();
        cout << "El juego se ha cargado exitosamente en la base de datos." << endl;
    }
    else
    {
        cout << "Error al abrir el archivo de base de datos." << endl;
    }
}

//OBLIGATORIA
// Función para mostrar la información de un juego
void displayGameInformation(const Game &game)
{
    cout << "Información actual del juego:" << endl;
    cout << "Nombre: " << game.name << endl;
    cout << "Categoría: " << game.category << endl;
    cout << "Tamaño: " << game.size << endl;
    cout << "Precio: " << game.price << endl;
    cout << "Licencias Disponibles: " << game.licenciasDisponibles << endl;
    cout << "Licencias Vendidas: " << game.licenciasVendidas << endl;
    cout << "Imagen: " << game.imagen << endl;
}

//OBLIGATORIA
// Función para editar la información de un juego en la base de datos
void updateGameInDatabase(const Game &gameToUpdate)
{
    // Abre el archivo de base de datos en modo de escritura
    ofstream baseDatos("Base_Datos_AppStore.txt");
    if (baseDatos.is_open())
    {
        // Recorre la lista de juegos para actualizar la base de datos
        for (const Game &game : games)
        {
            // Escribe la información del juego en el archivo, separando los campos por comas
            baseDatos << game.name << "," << game.id << "," << game.category << ","
                        << game.size << "," << game.price << ","
                        << game.licenciasDisponibles << "," << game.licenciasVendidas << ","
                        << game.imagen << endl;
        }

        // Cierra el archivo después de escribir la información actualizada
        baseDatos.close();
    }
    else
    {
        // Muestra un mensaje de error si no se pudo abrir el archivo
        cout << "Error al abrir el archivo de base de datos." << endl;
    }
}

//OPCIONAL / MODIFICABLE
// Función para editar la información de un juego en la estructura de datos
void editGameInformationInMemory(Game &gameToEdit)
{
    // Muestra la información actual del juego
    displayGameInformation(gameToEdit);

    // Solicita al usuario que ingrese la nueva información (o presione Enter para dejarla sin cambios)
    cout << "Ingrese la nueva información (o presione Enter para dejarla sin cambios):" << endl;

    cin.ignore(); // Limpia el búfer del teclado

    // Solicita al usuario ingresar el nuevo nombre del juego
    cout << "Nuevo nombre: ";
    string newName;
    getline(cin, newName);
    if (!newName.empty())
    {
        gameToEdit.name = newName; // Actualiza el nombre si se proporciona uno nuevo
    }

    // Solicita al usuario ingresar la nueva categoría del juego
    cout << "Nueva categoría: ";
    string newCategory;
    getline(cin, newCategory);
    if (!newCategory.empty())
    {
        gameToEdit.category = newCategory; // Actualiza la categoría si se proporciona una nueva
    }

    // Solicita al usuario ingresar el nuevo tamaño del juego
    cout << "Nuevo tamaño: ";
    string newSize;
    getline(cin, newSize);
    if (!newSize.empty())
    {
        gameToEdit.size = newSize; // Actualiza el tamaño si se proporciona uno nuevo
    }

    // Solicita al usuario ingresar el nuevo precio del juego
    cout << "Nuevo precio: ";
    string newPriceInput;
    getline(cin, newPriceInput);
    if (!newPriceInput.empty())
    {
        gameToEdit.price = stof(newPriceInput); // Actualiza el precio si se proporciona uno nuevo
    }

    // Solicita al usuario ingresar la nueva cantidad de licencias disponibles
    cout << "Nuevas licencias disponibles: ";
    string newLicensesAvailableInput;
    getline(cin, newLicensesAvailableInput);
    if (!newLicensesAvailableInput.empty())
    {
        gameToEdit.licenciasDisponibles = stoi(newLicensesAvailableInput); // Actualiza las licencias disponibles si se proporcionan nuevas
    }

    // Solicita al usuario ingresar la nueva cantidad de licencias vendidas
    cout << "Nuevas licencias vendidas: ";
    string newLicensesSoldInput;
    getline(cin, newLicensesSoldInput);
    if (!newLicensesSoldInput.empty())
    {
        gameToEdit.licenciasVendidas = stoi(newLicensesSoldInput); // Actualiza las licencias vendidas si se proporcionan nuevas
    }

    // Solicita al usuario ingresar el nuevo nombre del archivo de imagen del juego
    cout << "Nueva imagen: ";
    string newImagen;
    cin.ignore(); // Limpia el búfer antes de ingresar la imagen
    getline(cin, newImagen);
    if (!newImagen.empty())
    {
        gameToEdit.imagen = newImagen; // Actualiza el nombre de la imagen si se proporciona uno nuevo
    }

    cout << "La información del juego se ha actualizado exitosamente." << endl;

    // Actualiza la información en la base de datos
    updateGameInDatabase(gameToEdit);
}

//OPCIONAL
// Función principal para editar la información de un juego
void editVideogameInformation()
{
    string gameID;
    cout << "Ingrese el ID del juego que desea editar: ";
    cin >> gameID;

    // Buscar el juego por su ID
    bool found = false;
    for (int i = 0; i < games.size(); i++)
    {
        if (games[i].id == gameID)
        {
            found = true;
            Game &gameToEdit = games[i];

            // Llama a editGameInformationInMemory para editar la información del juego encontrado
            editGameInformationInMemory(gameToEdit);
            break;
        }
    }

    if (!found)
    {
        cout << "No se encontró un juego con el ID proporcionado." << endl;
    }
}

//OPCIONABLE
// Función para subir actualizaciones de un juego
void uploadGameUpdates()
{
    string gameID;
    cout << "Ingrese el ID del juego para el cual desea subir una actualización: ";
    cin >> gameID;

    bool found = false;
    for (int i = 0; i < games.size(); i++)
    {
        if (games[i].id == gameID)
        {
            found = true;
            Game &gameToUpdate = games[i];

            // Parte 3: Entrada de detalles de la actualización
            string updateDescription;
            cout << "Ingrese una breve descripción de la actualización: ";
            cin.ignore();
            getline(cin, updateDescription);

            string updateVersion;
            cout << "Ingrese la versión de la actualización: ";
            getline(cin, updateVersion);

            // Llama a updateGame para aplicar la actualización
            updateGame(gameToUpdate, updateVersion, updateDescription);

            // Muestra información sobre la actualización subida
            displayUpdateInfo(gameToUpdate, updateVersion, updateDescription);

            break;
        }
    }

    if (!found)
    {
        cout << "No se encontró un juego con el ID proporcionado." << endl;
    }
}

//OPCIONABLE
// Función para aplicar una actualización a un juego
void updateGame(Game &gameToUpdate, const string &updateVersion, const string &updateDescription)
{
    // Modifica el nombre del juego para incluir la versión de la actualización
    gameToUpdate.name += " - " + updateVersion;

    // Cambia el tamaño del juego a "Updated" para indicar que ha sido actualizado
    gameToUpdate.size = "Updated"; 

    // Restablece la cantidad de licencias vendidas a 0 después de la actualización
    gameToUpdate.licenciasVendidas = 0; 

    // Cambia el nombre de la imagen del juego para reflejar la actualización
    gameToUpdate.imagen = "UpdatedImage.jpg"; 

    // Llama a updateGameInDatabase para reflejar los cambios en la base de datos
    updateGameInDatabase(gameToUpdate);
}

//OPCIONAL
// Función para mostrar información de una actualización
void displayUpdateInfo(const Game &gameToUpdate, const string &updateVersion, const string &updateDescription)
{
    cout << "La actualización se ha subido exitosamente para el juego: " << gameToUpdate.name << endl;
    cout << "Versión de la actualización: " << updateVersion << endl;
    cout << "Descripción de la actualización: " << updateDescription << endl;
}

//OPCIONAL
// Función para ver las ventas de un juego
void viewGameSales()
{
    string gameId;
    cout << "Ingrese el ID del juego del que desea ver las ventas: ";
    cin >> gameId;

    bool found = false;
    for (const Game &game : games)
    {
        if (game.id == gameId)
        {
            found = true;
            cout << "Ventas del juego '" << game.name << "' (ID: " << gameId << "): " << game.licenciasVendidas << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "No se encontró un juego con el ID proporcionado." << endl;
    }
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
        baseDatos << "Dont Satve,DS001,Accion,1GB,4.99,100,50,Image1.jpg" << endl;
        baseDatos << "Starfield,SF002,Accion,125GB,59.99,200,100,Image2.jpg" << endl;
        baseDatos << "The Legend of Zelda: Breath of the Wild,ZL003,Rompecabezas,13.4GB,59.99,500,250,Image3.jpg" << endl;
        baseDatos << "Red Dead Redemption 2,RD004,Accion,105GB,49.99,400,200,Image4.jpg" << endl;
        baseDatos << "The Elder Scrolls V: Skyrim,TS005,Accion,25GB,19.99,600,300,Image5.jpg" << endl;
        baseDatos << "Cyber Shadow,CS006,Rompecabezas,1GB,14.99,100,50,Image6.jpg" << endl;
        baseDatos << "Outer Worlds 2,OW007,Accion,35GB,49.99,400,200,Image7.jpg" << endl;

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
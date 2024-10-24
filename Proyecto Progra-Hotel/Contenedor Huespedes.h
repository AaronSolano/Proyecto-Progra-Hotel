#pragma once
#include "Librerias.h"
#include "Huesped.h"

class ContenedorHuespedes
{
private:
    vector<Huesped> ListaHuespedes;

public:
    void RegistrarHuesped()
    {
		RecuperarContenedor(); // recolecta los datos guardados en el txt y los carga en la lista de huespedes antes de registrar uno nuevo.

        int Cedula;
        string Nombre;
        string Apellido;
        int Telefono;
        string Correo;

        cout << "Ingrese la cedula del huesped ( Incluir ceros): ";
        while (!(cin >> Cedula) || Cedula < 1 || Cedula > 9999999999) {
            cout << "Ingrese nuevamente la Cedula ( Incluir ceros ): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese el nombre del huesped: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, Nombre);
        while (Nombre.empty()) {
            cout << "Ingrese nuevamente el Nombre: ";
            getline(cin, Nombre);
        }

        cout << "Ingrese los apellidos del huesped: ";
        getline(cin, Apellido);
        while (Apellido.empty()) {
            cout << "Ingrese nuevamente el Apellido: ";
            getline(cin, Apellido);
        }

        cout << "Ingrese el telefono del huesped (8 digitos): ";
        while (!(cin >> Telefono) || Telefono < 10000000 || Telefono > 99999999) {
            cout << "Ingrese nuevamente el Numero de Telefono (8 digitos): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese el correo del huesped: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, Correo);
        while (Correo.empty()) {
            cout << "Ingrese nuevamente el Correo: ";
            getline(cin, Correo);
        }

        if (!verificarCedula(Cedula))
        {
            Huesped huesped(Cedula, Nombre, Apellido, Telefono, Correo);
            ListaHuespedes.push_back(huesped);
            cout << "---------------------------------------------------" << endl;
            cout << "Huesped registrado con exito  !!!" << endl;
            cout << "---------------------------------------------------" << endl;
        }
        else
        {
            cout << "---------------------------------------------------" << endl;
            cout << "La cedula ya se encuentra registrada   !!!" << endl;
            cout << "---------------------------------------------------" << endl;

        }
        // Mostrar la lista de huespedes después de registrar uno nuevo
        for (int i = 0; i < ListaHuespedes.size(); i++)
        {
            ListaHuespedes[i].getDatosHuesped();

        }


    }

    bool validarHuesped(int idHuesped) //validar en el check in
    {
        bool existeHuesped = false;
        for (int i = 0; i < ListaHuespedes.size(); i++)
        {
            if (ListaHuespedes[i].getCedula() == idHuesped)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "El huesped se encuentra registrado!!!" << endl;
                cout << "---------------------------------------------------" << endl;
                existeHuesped = true;
            }
        }
        if (!existeHuesped)
        {
            cout << "---------------------------------------------------" << endl;
            cout << "El huesped no se encuentra registrado o no existe!!! " << endl;
            cout << "---------------------------------------------------" << endl;
        }
        return existeHuesped;
    }

    bool verificarCedula(int _cedula)
    {
        for (int i = 0; i < ListaHuespedes.size(); i++)
        {
            if (ListaHuespedes[i].getCedula() == _cedula)
            {
                return true;
            }
        }
        return false;
    }

    void ModificarHuesped(int _cedula)
    {
        string Nombre;
        string Apellido;
        int Telefono;
        string Correo;

        if (ListaHuespedes.empty())
        {
            cout << "--------------------------------------------" << endl;
            cout << " No hay Huespedes Registrados" << endl;
            cout << "--------------------------------------------" << endl;
        }
        else
        {
			for (int i = 0; i < ListaHuespedes.size(); i++)
			{
				if (ListaHuespedes[i].getCedula() == _cedula)
				{
					
					cout << "Ingrese el nombre del huesped: ";
					cin.ignore(); // Limpiar el buffer
					getline(cin, Nombre);
					while (Nombre.empty()) {
						cout << "Ingrese nuevamente el Nombre: ";
						getline(cin, Nombre);
					}

					cout << "Ingrese el apellido del huesped: ";
					getline(cin, Apellido);
					while (Apellido.empty()) {
						cout << "Ingrese nuevamente el Apellido: ";
						getline(cin, Apellido);
					}

					cout << "Ingrese el telefono del huesped (8 digitos): ";
					while (!(cin >> Telefono) || Telefono < 10000000 || Telefono > 99999999) {
						cout << "Ingrese nuevamente el Numero de Telefono (8 digitos): ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

					cout << "Ingrese el correo del huesped: ";
					cin.ignore(); // Limpiar el buffer
					getline(cin, Correo);
					while (Correo.empty()) {
						cout << "Ingrese nuevamente el Correo: ";
						getline(cin, Correo);
					}

					ListaHuespedes[i].setActualizarHuesped(Nombre, Apellido, Telefono, Correo);
					cout << "--------------------------------------------" << endl;
					cout << "Huesped modificado con exito  !!!" << endl;
					cout << "--------------------------------------------" << endl;
					ListaHuespedes[i].getDatosHuesped();
					break;
				}
				else
				{
					cout << "--------------------------------------------" << endl;
					cout << "Huesped no encontrado" << endl;
					cout << "--------------------------------------------" << endl;
				}
			}
            

        }
        
		
       
    }

	void ConsultarHuesped(int _cedula)
	{
		int cantidadHuespedes = ListaHuespedes.size();

		if (ListaHuespedes.empty())
		{
			cout << "--------------------------------------------" << endl;
			cout << " No hay Huespedes Registrados" << endl;
			cout << "--------------------------------------------" << endl;
		}
		else
		{
			for (int i = 0; i < ListaHuespedes.size(); i++)
			{
				if (ListaHuespedes[i].getCedula() == _cedula)
				{
					ListaHuespedes[i].getDatosHuesped();
					break;
				}
				else
				{
					cout << "--------------------------------------------" << endl;
					cout << "Huesped no encontrado" << endl;
					cout << "--------------------------------------------" << endl;
				}
			}
		}
		cout << "--------------------------------------------" << endl;
		cout << "Cantidad de Huespedes Registrados: " << cantidadHuespedes << endl;
		cout << "--------------------------------------------" << endl;
	}

    void GuardarContenedor() const
    {
        if (ListaHuespedes.empty())
        {
            cout << "--------------------------------------------" << endl;
            cout << "No hay Huespedes Registrados !!!" << endl;
            cout << "--------------------------------------------" << endl;
        }
        else
        {
            ofstream archivo("Huespedes.txt");

            if (archivo.is_open()) {
                for (int i = 0; i < ListaHuespedes.size(); i++) {
                    archivo << ListaHuespedes[i].getCedula()
                        << "-" << ListaHuespedes[i].getNombre()
                        << "-" << ListaHuespedes[i].getApellido()
                        << "-" << ListaHuespedes[i].getTelefono()
                        << "-" << ListaHuespedes[i].getCorreo()
                        << endl;
                }
                archivo.close();
                cout << "----------------------------------------------------------------" << endl;
                cout << "Lista de Huespedes almacenados en el archivo correctamente..." << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
        }

    }

	void RecuperarContenedor()
	{
        ListaHuespedes.clear();

        ifstream archivo("Huespedes.txt");
        if (archivo.is_open())
        {
        	string linea;
			while (getline(archivo, linea))
			{
				stringstream ss(linea);

				string cedula, nombre, apellido, telefono, correo;

				getline(ss, cedula, '-');

				getline(ss, nombre, '-');

				getline(ss, apellido, '-');

				getline(ss, telefono, '-');

				getline(ss, correo, '-');

				Huesped huesped(stoi(cedula), nombre, apellido, stoi(telefono), correo);

				ListaHuespedes.push_back(huesped);
               
            }
            archivo.close();
            cout << "----------------------------------------------------------------" << endl;
            cout << "Lista de Huespedes cargados desde el archivo correctamente..." << endl;
            cout << "----------------------------------------------------------------" << endl;

        }
        

	}  

    void menuHuespedes()
    {
        char opcion;

        do
        {
            system("cls");
            cout << "***********| Menu Huespedes |***********" << endl;
            cout << "* 1- Registrar Nuevo Huesped           *" << endl;
            cout << "* 2- Modificar Huesped                 *" << endl;
            cout << "* 3- Consultar todos los Datos         *" << endl;
            cout << "* 4- Guardar contenedor en archivo     *" << endl;
            cout << "* 5- Recuperar datos del archivo       *" << endl;
            cout << "* 6- Regresar a menú principal         *" << endl;
            cout << "****************************************" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case '1':
            {
                system("cls");
                RegistrarHuesped();

                system("pause");
                break;
            }
            case '2':
            {
                system("cls");

				int cedula;
				cout << "Ingrese la cedula del huesped a modificar: ";
				while (!(cin >> cedula) || cedula < 1 || cedula > 9999999999) {
					cout << "Ingrese nuevamente la Cedula (hasta 10 digitos): ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				ModificarHuesped(cedula);

                

                system("pause");
                break;
            }
            case '3':
            {
                system("cls");
				
				int cedula;
				cout << "Ingrese la cedula del huesped a consultar: ";
				while (!(cin >> cedula) || cedula < 1 || cedula > 9999999999) {
					cout << "Ingrese nuevamente la Cedula (hasta 10 digitos): ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				ConsultarHuesped(cedula);

                system("pause");
                break;
            }
            case '4':
            {

                system("cls");
                GuardarContenedor();

                system("pause");
                break;
            }
            case '5':
            {
                system("cls");
				RecuperarContenedor();
                system("pause");
                break;
            }
            case '6':
            {
                system("cls");
                cout << "-----------------------------------" << endl;
                cout << "Regresando al Menu principal......." << endl;
                cout << "-----------------------------------" << endl;
                break;
            }
            default:
            {

                cout << "Ingrese un valor valido !!" << endl;
                break;
            }

            }
        } while (opcion != '6');

    }
};
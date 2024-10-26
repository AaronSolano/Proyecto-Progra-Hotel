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

		// Ingresar la cedula de huesped y el while valida que sea un numero y que tenga 10 digitos maximo
        cout << "Ingrese la cedula del huesped ( Incluir ceros): ";
        while (!(cin >> Cedula) || Cedula < 1 || Cedula > 9999999999) {
            cout << "Ingrese nuevamente la Cedula ( Incluir ceros ): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

		// ingresa el nombre y el while valida que no este vacio
        cout << "Ingrese el nombre del huesped: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, Nombre);
        while (Nombre.empty()) {
            cout << "Ingrese nuevamente el Nombre: ";
            getline(cin, Nombre);
        }
        // ingresa el nombre y el while valida que no este vacio
        cout << "Ingrese los apellidos del huesped: ";
        getline(cin, Apellido);
        while (Apellido.empty()) {
            cout << "Ingrese nuevamente el Apellido: ";
            getline(cin, Apellido);
        }
		// ingresa el telefono y el while valida que sea un numero y que tenga 8 digitos como minimo - maximo
        cout << "Ingrese el telefono del huesped (8 digitos): ";
		while (!(cin >> Telefono) || Telefono < 10000000 || Telefono > 99999999) // permite  solo 8 digitos y sale del bucle cuando se cumple
        {
            cout << "Ingrese nuevamente el Numero de Telefono (8 digitos): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
		// ingresa el correo y el while valida que no este vacio el dato ingresado
        cout << "Ingrese el correo del huesped: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, Correo);
		while (Correo.empty()) // valida que no este vacio el dato ingresado
        {
            cout << "Ingrese nuevamente el Correo: ";
            getline(cin, Correo);
        }
		// verifica si la cedula ya esta registrada
        if (!verificarCedula(Cedula))
        {
			Huesped huesped(Cedula, Nombre, Apellido, Telefono, Correo); // crea un objeto huesped con los datos ingresados
			ListaHuespedes.push_back(huesped); // agrega el objeto huesped a la lista de huespedes

            cout << "\033[32m---------------------------------------------------\033[0m" << endl;
            cout << "\033[32mHuesped registrado con exito  !!!\033[0m" << endl;
            cout << "\033[32m---------------------------------------------------\033[0m" << endl;
        }
        else
        {
            cout << "\033[---------------------------------------------------\033[0m" << endl;
            cout << "\033[31m La cedula ya se encuentra registrada   !!! \033[0m" << endl;
            cout << "\033[---------------------------------------------------\033[0m" << endl;

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
		for (int i = 0; i < ListaHuespedes.size(); i++) // recorre la lista de huespedes
        {
			if (ListaHuespedes[i].getCedula() == idHuesped) // verifica si la cedula ingresada coincide con alguna de la lista
            {
                cout << "\033[32m---------------------------------------------------\033[0m" << endl;
                cout << "\033[32mEl huesped se encuentra registrado!!!\033[0m" << endl;
                cout << "\033[32m---------------------------------------------------\033[0m" << endl;
                existeHuesped = true;
            }
        }
		if (!existeHuesped) // si no se encuentra el huesped
        {
            cout << "\033[31m---------------------------------------------------\033[0m" << endl;
            cout << "\033[31mEl huesped no se encuentra registrado o no existe!!!\033[0m" << endl;
            cout << "\033[31m---------------------------------------------------\033[0m" << endl;
        }
        return existeHuesped;
    }

	bool verificarCedula(int _cedula) // verifica si la cedula ya esta registrada
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
        bool encontrado = false;

		if (ListaHuespedes.empty()) // si la lista de huespedes esta vacia
        {
            cout << "\033[31m--------------------------------------------\033[0m" << endl;
            cout << "\033[31m No hay Huespedes Registrados\033[0m" << endl;
            cout << "\033[31m--------------------------------------------\033[0m" << endl;
        }
        else
        {
			for (int i = 0; i < ListaHuespedes.size(); i++) // recorre la lista de huespedes
			{
                

				if (ListaHuespedes[i].getCedula() == _cedula) // verifica si la cedula ingresada coincide con alguna de la lista y si es asi modifica los datos
                {
                    encontrado = true;

					// ingresa el nombre del huesped y el bucle while no deja que el dato este vacio
                    cout << "Ingrese el nombre del huesped: ";
                    cin.ignore(); // Limpiar el buffer
                    getline(cin, Nombre);
                    while (Nombre.empty()) 
                    {
                        cout << "Ingrese nuevamente el Nombre: ";
                        getline(cin, Nombre);
                    }

					// ingresa el apellido del huesped y el bucle while no deja que el dato este vacio
                    cout << "Ingrese el apellido del huesped: ";
                    getline(cin, Apellido);
                    while (Apellido.empty()) 
                    {
                        cout << "Ingrese nuevamente el Apellido: ";
                        getline(cin, Apellido);
                    }

					// ingresa el telefono del huesped y el bucle while no permite que sea menor ni mayor a 8 digitos
                    cout << "Ingrese el telefono del huesped (8 digitos): ";
                    while (!(cin >> Telefono) || Telefono < 10000000 || Telefono > 99999999) {
                        cout << "Ingrese nuevamente el Numero de Telefono (8 digitos): ";
                        cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer
                    }

					// ingresa el correo del huesped y el bucle while no deja que el dato este vacio
                    cout << "Ingrese el correo del huesped: ";
                    cin.ignore(); // Limpiar el buffer
                    getline(cin, Correo);
                    while (Correo.empty()) {
                        cout << "Ingrese nuevamente el Correo: ";
                        getline(cin, Correo);
                    }

					ListaHuespedes[i].setActualizarHuesped(Nombre, Apellido, Telefono, Correo); // actualiza los datos del huesped
                    cout << "\033[32m--------------------------------------------\033[0m" << endl;
                    cout << "\033[32mHuesped modificado con exito  !!!\033[0m" << endl;
                    cout << "\033[32m--------------------------------------------\033[0m" << endl;

					ListaHuespedes[i].getDatosHuesped();    // muestra los datos del huesped modificado
                    break;
                }
                
				
			}
			if (!encontrado) // si no se encuentra el huesped
            {
                cout << "\033[31m--------------------------------------------\033[0m" << endl;
                cout << "\033[31mHabitacion no encontrada\033[0m" << endl;
                cout << "\033[31m--------------------------------------------\033[0m" << endl;

            }
            

        }
        
		
       
    }

	void ConsultarHuesped(int _cedula) // consulta los datos de un huesped por su numero de cedula
	{
        bool encontrado = false;
		int cantidadHuespedes = ListaHuespedes.size();

		if (ListaHuespedes.empty()) // si la lista de huespedes esta vacia
		{
            cout << "\033[31m--------------------------------------------\033[0m" << endl;
            cout << "\033[31m No hay Huespedes Registrados\033[0m" << endl;
            cout << "\033[31m--------------------------------------------\033[0m" << endl;
		}
		else
		{
			for (int i = 0; i < ListaHuespedes.size(); i++) // recorre la lista de huespedes
			{
				if (ListaHuespedes[i].getCedula() == _cedula) // verifica si la cedula ingresada coincide con alguna de la lista y si es asi muestra los datos
				{
					encontrado = true; //   si se encuentra el huesped

					ListaHuespedes[i].getDatosHuesped(); // muestra los datos del huesped
					break;
				}
				
			}
			if (!encontrado) // si no se encuentra el huesped
            {
                cout << "\033[31m--------------------------------------------\033[0m" << endl;
                cout << "\033[31mHuesped no encontrado\033[0m" << endl;
                cout << "\033[31m--------------------------------------------\033[0m" << endl;
            }
		}
		cout << "--------------------------------------------" << endl; // muestra la cantidad de huespedes registrados
		cout << "Cantidad de Huespedes Registrados: " << cantidadHuespedes << endl;
		cout << "--------------------------------------------" << endl;
	}

    void GuardarContenedor() const
    {
        if (ListaHuespedes.empty())
        {
            cout << "--------------------------------------------" << endl;
            cout << "\033[31mNo hay Huespedes Registrados !!!\033[0m" << endl;
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
                cout << "\033[32mLista de Huespedes almacenados en el archivo correctamente...\033[0m" << endl;
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
            cout << "\033[32mLista de Huespedes cargados desde el archivo correctamente...\033[0m" << endl;
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
                cout << "\033[32mRegresando al Menu principal.......\033[0m" << endl;
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
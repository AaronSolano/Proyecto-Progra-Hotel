#pragma once
#include "Librerias.h"
#include "Habitacion.h"

class ContenedorHabitaciones
{
private:
	vector<Habitacion> ListaHabitaciones;

public:


	void RegistrarHabitacion()
	{
		
        int numHabitacion, piso, cantPersonas;
        double precioXnoche;
        string descripcion;
		bool estado = true;

        // ingresa el numero de la habitacion y verifica que no sea menor a 1. y sale del bucle cuando se
        // cumple la condicion de ser mayor a uno.
        cout << "Ingrese el numero de habitacion: ";
        while (!(cin >> numHabitacion) || numHabitacion < 1) {
            cout << "Ingrese nuevamente: ";
            cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer 
        }

        // ingresa el numero del piso donde se encuentra la habitacion y verifica que no sea menor a 1. y sale del bucle cuando se
       // cumple la condicion de ser mayor a uno.
        cout << "Ingrese el piso: ";
        while (!(cin >> piso) || piso < 1) {
            cout << " Ingrese nuevamente: ";
            cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        }

        // ingresa la descripcion y verifica que no este vacio. y sale del bucle cuando se
       // cumple la condicion de no ser espacios vacios.
        cout << "Ingrese la descripcion: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, descripcion);
        while (descripcion.empty()) {
            cout << "Ingrese nuevamente: ";
            getline(cin, descripcion);
        }

        // ingresa la cantidad de personas y verifica que no sea menor a 1. y sale del bucle cuando se
       // cumple la condicion de ser mayor a uno.
        cout << "Ingrese la cantidad de personas: ";
        while (!(cin >> cantPersonas) || cantPersonas < 1) {
            cout << "Ingrese nuevamente: ";
            cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        }

        // ingresa el precio de la habitacion x noche y verifica que no sea menor a 1. y sale del bucle cuando se
       // cumple la condicion de ser mayor a uno.
        cout << "Ingrese el precio por noche: ";
        while (!(cin >> precioXnoche) || precioXnoche < 1) {
            cout << "Ingrese nuevamente: ";
            cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        } 

		// Verificar si la habitación ya existe antes de registrarla
        if (!verificarHabitacion(numHabitacion))
        {
           
			system("cls");
			Habitacion nuevaHabitacion(numHabitacion, piso, descripcion, cantPersonas, precioXnoche, estado); // crea un objeto de tipo habitacion
			ListaHabitaciones.push_back(nuevaHabitacion); // agrega la habitacion al vector de habitaciones
            cout << "---------------------------------------------------" << endl;
            cout << "\033[32mHabitacion registrada con exito !!!\033[0m" << endl;
            cout << "---------------------------------------------------" << endl;
        }
        else
        {
			system("cls");
            cout << "---------------------------------------------------" << endl;  
            cout << "\033[31mLa habitacion ya existe !!!!\033[0m" << endl;
            cout << "---------------------------------------------------" << endl;
        }

        // Mostrar la lista de habitaciones después de registrar una nueva
        for (int i = 0; i < ListaHabitaciones.size(); i++)
        {
            ListaHabitaciones[i].getDatosHabitacion();

        }
    }
	
	bool validarHabitacionReserva(int numHabit) //validar en el check in para saber si existe la habitacion y si esta disponible
    {
        bool sePuedeReservar = false;
        for (int i = 0; i < ListaHabitaciones.size(); i++)
        {
			if (ListaHabitaciones[i].getNumeroHabitacion() == numHabit) // recorre el vector en busca del numero de habitacion 
			{
				if (ListaHabitaciones[i].getEstado() == 1)  // si la habitacion esta disponible es = true y muestra los datos de la habitacion
                {
                    sePuedeReservar = true;
                    cout << "\033[32m---------------------------------------------------" << endl;
                    cout << "La habitacion se encuentra disponible " << endl;
                    cout << "---------------------------------------------------\033[0m" << endl;
                    
                }
			}
		}
		if (!sePuedeReservar) // si no se puede reservar muestra un mensaje
        {
            cout << "\033[31m---------------------------------------------------" << endl;
            cout << "La habitacion no se encuentra disponible!!! " << endl;
            cout << "---------------------------------------------------\033[0m" << endl;
		}
		return sePuedeReservar;
    }

	bool verificarHabitacion(int numHabitacion) // metodo para verificar si la habitacion ya existe
	{
		for (int i = 0; i < ListaHabitaciones.size(); i++) // recorre el vector de habitaciones
		{
			if (ListaHabitaciones[i].getNumeroHabitacion() == numHabitacion) // si encuentra la habitacion retorna true
			{
				return true;
			}
		}
		return false; // si no encuentra la habitacion retorna false
	}


    void ModificarHabitacion(int numHabitacion)
    {

        int piso;
        string descripcion;
        int cantPersonas;
        double precioXnoche;
        bool encontrada = false;

		if (ListaHabitaciones.empty()) // si no hay habitaciones registradas muestra un mensaje
        {
            cout << "\033[31m--------------------------------------------" << endl;
            cout << " No hay Habitaciones Registradas" << endl;
            cout << "--------------------------------------------\033[0m" << endl;
        }
        else
        {
			for (int i = 0; i < ListaHabitaciones.size(); i++) // recorre el vector de habitaciones
            {
				if (ListaHabitaciones[i].getNumeroHabitacion() == numHabitacion)  // si encuentra la habitacion
                {
					encontrada = true; // cambia el estado de la variable a true

					// ingresa el numero del piso donde se encuentra la habitacion y verifica que no sea menor a 1. y sale del bucle cuando se
                    cout << "Ingrese el piso: ";
                    while (!(cin >> piso) || piso < 1)
                    {
                        cout << " Ingrese nuevamente: ";
                        cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
                    }

					// ingresa la descripcion y verifica que no este vacio. y sale del bucle cuando se cumple la condicion de no ser espacios vacios.
                    cout << "Ingrese la descripcion: ";
                    cin.ignore(); // Limpiar el buffer
                    getline(cin, descripcion);
                    while (descripcion.empty()) 
                    {
                        cout << "Ingrese nuevamente: ";
                        getline(cin, descripcion);
                    }

					// ingresa la cantidad de personas y verifica que no sea menor a 1. y sale del bucle cuando se cumple la condicion de ser mayor a uno.
                    cout << "Ingrese la cantidad de personas: ";
                    while (!(cin >> cantPersonas) || cantPersonas < 1)
                    {
                        cout << "Ingrese nuevamente: ";
                        cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Limpiar el buffer
                    }

					// ingresa el precio de la habitacion x noche y verifica que no sea menor a 1.
                    // y sale del bucle cuando se cumple la condicion de ser mayor a uno.
                    cout << "Ingrese el precio por noche: ";
                    while (!(cin >> precioXnoche) || precioXnoche < 1) 
                    {
                        cout << "Ingrese nuevamente: ";
                        cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
                    }
					ListaHabitaciones[i].setActualizarHabitacion(piso, descripcion, cantPersonas, precioXnoche); // actualiza los datos de la habitacion
                    cout << "\033[32m---------------------------------------------------" << endl;
                    cout << "Habitacion actualizada con exito!!!" << endl;
                    cout << "---------------------------------------------------\033[0m" << endl; 

					ListaHabitaciones[i].getDatosHabitacion(); // muestra los datos de la habitacion
					break;
				}
                
            
           
            }
			if (!encontrada) // si no encuentra la habitacion muestra un mensaje
            {
                cout << "\033[31m--------------------------------------------" << endl;
                cout << " La habitacion no existe !!! ..." << endl;
                cout << "--------------------------------------------\033[0m" << endl;
            }

        }
        


    }

	void ConsultarHabitaciones() // metodo para consultar las habitaciones
	{
		system("cls");
		if (ListaHabitaciones.empty()) // si no hay habitaciones registradas muestra un mensaje
        {
            cout << "\033[31m--------------------------------------------" << endl;
            cout << " No hay Habitaciones Registradas" << endl;
            cout << "--------------------------------------------\033[0m" << endl;
        }
        else
        {
			int totalHabitaciones = ListaHabitaciones.size(); // total de habitaciones
			int totalHabitacionesDisponibles = 0; // total de habitaciones disponibles iniciado en cero, para extraer datos de cada ingreso

            cout << "------------|  Lista Habitaciones  |------------" << endl;
			for (int i = 0; i < ListaHabitaciones.size(); i++) // recorre el vector de habitaciones
            {

				ListaHabitaciones[i].getDatosHabitacion(); // muestra los datos de la habitacion

				if (ListaHabitaciones[i].getEstado()) // si la habitacion esta disponible suma 1 al total de habitaciones disponibles
                {
					totalHabitacionesDisponibles++; // suma 1 al total de habitaciones disponibles
                }
                
            }
            cout << "--------------------------------------------" << endl;
			cout << "Total de habitaciones: " << totalHabitaciones << endl; // muestra el total de habitaciones
			cout << "Total de habitaciones disponibles: " << totalHabitacionesDisponibles << endl; // muestra el total de habitaciones disponibles
            cout << "--------------------------------------------" << endl;
        }

	}

    void guardarContenedor() const 
{
        if (ListaHabitaciones.empty())
        {
			cout << "--------------------------------------------" << endl;
            cout << "\033[31mNo hay Habitaciones Registradas !!!\033[0m" << endl;
			cout << "--------------------------------------------" << endl;
		}
        else
        {
            ofstream archivo("Habitaciones.txt");

            if (archivo.is_open()) {
                for (int i = 0; i < ListaHabitaciones.size(); i++) {
                    archivo << ListaHabitaciones[i].getNumeroHabitacion()
                        << "-" << ListaHabitaciones[i].getPiso()
                        << "-" << ListaHabitaciones[i].getDescripcion()
                        << "-" << ListaHabitaciones[i].getCantidadPersonas()
						<< "-" << ListaHabitaciones[i].getPrecioXnoche()
                        << "-" << (ListaHabitaciones[i].getEstado() ? "Disponible" : "Ocupada")
                        << endl;
                }
                archivo.close();
                cout << "----------------------------------------------------------------" << endl;
                cout << "\033[32mLista de Habitaciones almacenados en el archivo correctamente...\033[0m" << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
        }
    }

    void RecuperarDatos()
    {
       
        ListaHabitaciones.clear();

        ifstream archivo("Habitaciones.txt");
       if (archivo.is_open())
       {

           string linea;
           while (getline(archivo, linea))
           {
               stringstream ss(linea);
               string numHabitacion, piso, descripcion, cantPersonas, precioXnoche, estado;

                getline(ss, numHabitacion, '-');

                getline(ss, piso, '-');

                getline(ss, descripcion, '-');

                getline(ss, cantPersonas, '-');

                getline(ss, precioXnoche, '-');

				getline(ss, estado);

				int numHabitacionInt = stoi(numHabitacion);
				int pisoInt = stoi(piso);
				int cantPersonasInt = stoi(cantPersonas);
				double precioXnocheDouble = stod(precioXnoche);

				bool _estado = (estado == "Disponible");

				
				


				Habitacion nuevaHabitacion(numHabitacionInt, pisoInt, descripcion, cantPersonasInt, precioXnocheDouble, _estado); // crea un objeto de tipo habitacion


                 ListaHabitaciones.push_back(nuevaHabitacion);
           }
           archivo.close();
           cout << "----------------------------------------------------------------" << endl;
           cout << "\033[32mLista de Habitaciones cargados desde el archivo correctamente...\033[0m" << endl;
           cout << "----------------------------------------------------------------" << endl;

       }
        
    }

	void ConsultarEstadoHabitacion() // metodo para consultar el estado de la habitacion
    {

        int numHabitacion;
		// ingresa el numero de la habitacion y verifica que no sea menor a 1. y sale del bucle cuando se cumple la condicion de ser mayor a uno.
		cout << "Ingrese el numero de habitacion: ";
		while (!(cin >> numHabitacion) || numHabitacion < 1) 
        {
			cout << "Ingrese nuevamente: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
		}

		if (ListaHabitaciones.empty()) // si no hay habitaciones registradas muestra un mensaje
        {
            cout << "\033[31m--------------------------------------------" << endl;
            cout << " No hay Habitaciones Registradas" << endl;
            cout << "--------------------------------------------\033[0m" << endl;
            return;

        }
		else
		{
			for (int i = 0; i < ListaHabitaciones.size(); i++) // recorre el vector de habitaciones
			{
				if (ListaHabitaciones[i].getNumeroHabitacion() == numHabitacion) // si encuentra la habitacion muestra los datos de la habitacion
				{
					
					ListaHabitaciones[i].getDatosHabitacion(); // muestra los datos de la habitacion
					
					return;
				}
			}
			cout << "\033[31m--------------------------------------------" << endl; // si no encuentra la habitacion muestra un mensaje
            cout << "La habitacion no existe !!!" << endl;
            cout << "--------------------------------------------\033[0m" << endl;
		}
    }

	void actualizarEstadoHabitacion(int numHabitacion, bool estado)  // metodo para actualizar el estado de la habitacion
	{
		for (int i = 0; i < ListaHabitaciones.size(); i++) // recorre el vector de habitaciones
		{
			if (ListaHabitaciones[i].getNumeroHabitacion() == numHabitacion) // si encuentra la habitacion actualiza el estado
			{
				ListaHabitaciones[i].setEstado(estado); // actualiza el estado de la habitacion
			}
		}
	}

    // metodo para verificar la disponibilidad de una habitación
    bool verificarDisponibilidad(int codHabitacion) 
    {
        // recorre la lista de habitaciones para encontrar la habitacion con el codigo dado
        for (int i = 0; i < ListaHabitaciones.size();i++) 
        {
            if (ListaHabitaciones[i].getNumeroHabitacion() == codHabitacion) 
            {
                return ListaHabitaciones[i].getEstado(); // retorna el metodo en valor true si la habitacion esta disponible
            }
        }
        // Si no se encuentra la habitacion, retorna false
        return false;
    }


    int obtenerprecio(int numHabitacion)
    {
        int precio = 0;
        
		for (int i = 0; i < ListaHabitaciones.size(); i++)
		{
			if (ListaHabitaciones[i].getNumeroHabitacion() == numHabitacion)
			{
				precio = ListaHabitaciones[i].getPrecioXnoche();
			}
		}
        return precio;
    }


	//menu de habitaciones

    void menuHabitaciones()
    {
        char opcion;

        do
        {
            system("cls");
            cout << "*********| Menu Habitaciones |**********" << endl;
            cout << "* 1- Registrar una habitación          *" << endl;
            cout << "* 2- Modificar una habitación          *" << endl;
            cout << "* 3- Consultar todas los Habitaciones  *" << endl;
            cout << "* 4- Guardar contenedor en archivo     *" << endl;
            cout << "* 5- Recuperar datos del archivo       *" << endl;
            cout << "* 6- Consultar estado de habitación    *" << endl;
			cout << "* 7- Regresar a menú principal         *" << endl;
            cout << "****************************************" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case '1':
            {
				system("cls");
				RegistrarHabitacion();

                system("pause");
                break;
            }
            case '2':
            {
				system("cls");

				int numHabitacion;
				cout << "Ingrese el numero de habitacion a modificar: ";
				while (!(cin >> numHabitacion) || numHabitacion < 1) {
					cout << "Ingrese nuevamente: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				ModificarHabitacion(numHabitacion);

                system("pause");
                break;
            }
            case '3':
            {
				system("cls");
				ConsultarHabitaciones();

                system("pause");
                break;
            }
            case '4':
            {

				system("cls");
				guardarContenedor();

                system("pause");
                break;
            }
            case '5':
            {
				system("cls");
				RecuperarDatos();
                system("pause");
                break;
            }
            case '6':
            {
				system("cls");
				ConsultarEstadoHabitacion();

                system("pause");
                break;
            }
            case '7':
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
        } while (opcion != '7');

    }
};
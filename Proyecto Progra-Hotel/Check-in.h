#pragma once
#include "Librerias.h"

class CheckIn
{
private:
	int cedHuesped;
	int codHabitacion;
	string fechaCheckIn;
	bool estado;
	int consecutivo;

public:
	CheckIn(int _cedHuesped, int _codHabitacion, string _fechaCheckIn, bool _estado, int _consecutivo)
	{
		this->cedHuesped = _cedHuesped;
		this->codHabitacion = _codHabitacion;
		this->fechaCheckIn = _fechaCheckIn;
		this->estado = _estado;
		this->consecutivo = _consecutivo;
	}
	void setActualizarCheckIn(int _cedHuesped, int _codHabitacion, string _fechaCheckIn, bool _estado)
	{
		this->cedHuesped = _cedHuesped;
		this->codHabitacion = _codHabitacion;
		this->fechaCheckIn = _fechaCheckIn;
		this->estado = _estado;
	}

    void getDatosCheckIn()
    {
		cout << "-------------------------------------------------" << endl;
		cout << "Consecutivo:             #" << consecutivo << endl;
		cout << "Cedula del Huesped:       " << cedHuesped << endl;
		cout << "Numero de Habitacion:     " << codHabitacion << endl;
		cout << "Fecha Ingreso:            " << fechaCheckIn << endl;
		cout << "Estado:                   " << (estado ? "\033[33mPendiente\033[0m" : "\033[32mProcesado\033[0m") << endl;
		cout << "-------------------------------------------------" << endl;


    }

	const int getCedHuesped() const
	{
		return this->cedHuesped;
	}

	const int getCodHabitacion() const
	{
		return this->codHabitacion;
	}

	const string getFechaCheckIn() const
	{
		return this->fechaCheckIn;
	}

	const bool getEstado() const
	{
		return this->estado;
	}

	const int getConsecutivo() const
	{
		return this->consecutivo;
	}



};


    class contenedorCheckIn
    {
    private:
        vector<CheckIn> listaCheckIn;
        ContenedorHuespedes* contenedorHuesped;
        ContenedorHabitaciones* contenedorHabitacion;
        int contadorConsecutivo = 1;

    public:

        contenedorCheckIn(ContenedorHabitaciones& contenedorHabitacion, ContenedorHuespedes& contenedorHuesped)
        {
			this->contenedorHabitacion = &contenedorHabitacion; // se acceden a los datos por medio de puntos,
            this->contenedorHuesped = &contenedorHuesped;       //trayendo los datos de sus clases correspodientes
            RecuperarContenedor();
          
        }



        // Realizar un nuevo Check-In
        void realizarCheckIn()
        {
           

            int cedHuesped, codHabitacion;
            string fechaCheckIn;
            bool estado = true;

            //  |  Aqui ingresa el numero de cedula del huesped y se valida si cumple en no tener menos   |
			//  v  de 10 digitos de la cedula                                                             v

            cout << "Ingrese la cédula del huésped: ";
            while (!(cin >> cedHuesped) || cedHuesped < 1 || cedHuesped > 9999999999)
            {
                cout << "Ingrese nuevamente la cedula del huesped (Incluir ceros): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //  <-- descarta cualquier carácter sobrante en el búfer.
            }


            // |  aqui Verificar si la cédula del huésped ya ha sido registrada,       |
            // v  recorriendo el vector buscando una cedula previamente registrada     v
            for (int i = 0; i < listaCheckIn.size(); i++)
            {
                if (listaCheckIn[i].getCedHuesped() == cedHuesped)
                {
                   
                    cout << "\033[1;31mError: La cédula del huésped ya ha sido registrada.\033[0m" << endl;
                    
                    return;
                }
            }


            //  | verificar si el huesped está registrado y si no esta registrado,  |
			//  v le pide registrarlo en el momento                                 v

            if (!contenedorHuesped->validarHuesped(cedHuesped))   
            {                                                     
                char opcion;
                cout << "\033[1;33mEl huésped no está registrado. ¿Desea registrarlo ahora? (s/n): \033[0m";
                cin >> opcion;
                if (opcion == 's' || opcion == 'S')
                {
                    contenedorHuesped->RegistrarHuesped();
                }
                else
                {
                    cout << "\033[1;33mCheck-In cancelado.\033[0m" << endl;
                    return;
                }
            }

             //  |   ingreso del numero de habitatacion que desea el usuario y  |
             //  v   el bucle while no permite que se anoten numeros negativos  v

            cout << "Ingrese el numero de la habitación: ";      
            while (!(cin >> codHabitacion) || codHabitacion < 1)  
            { 
                cout << "Ingrese nuevamente: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // verifica si la habitacion esta disponible para el check-in
            if (!contenedorHabitacion->verificarDisponibilidad(codHabitacion)) {
                char opcion;
                cout << "\033[1;31mLa habitación seleccionada no está disponible para check-in.\033[0m" << endl;
                cout << "¿Desea elegir otra habitación o cancelar el check-in? (e para elegir otra, c para cancelar): ";
                cin >> opcion;

                if (opcion == 'e' || opcion == 'E') {
                    // solicita una nueva habitacion
                    cout << "Ingrese el número de la nueva habitación: ";
                    while (!(cin >> codHabitacion) || codHabitacion < 1) {
                        cout << "Ingrese nuevamente el número de la habitación: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    // verifica la disponibilidad de la nueva habitación
                    if (!contenedorHabitacion->verificarDisponibilidad(codHabitacion)) {
                        cout << "\033[1;31mLa nueva habitación tampoco está disponible. Check-In cancelado.\033[0m" << endl;
                        return;
                    }
                }
                else {
                    cout << "\033[1;33mCheck-In cancelado.\033[0m" << endl;
                    return;
                }
            }


            //  | verificar si el huesped está registrado y si no esta registrado,  |
           //   v le pide registrarlo en el momento                                 v
            if (!contenedorHabitacion->validarHabitacionReserva(codHabitacion))
            {
                char opcion;
                cout << "\033[1;33mLa habitación no está registrada. ¿Desea registrarla ahora? (s/n): \033[0m";
                cin >> opcion;
                if (opcion == 's' || opcion == 'S')
                {
                    contenedorHabitacion->RegistrarHabitacion();
                }
                else
                {
                    cout << "\033[1;33mCheck-In cancelado.\033[0m" << endl;
                    return;
                }
            }

           
			// ingreso de la fecha de check-in
            cout << "Ingrese la fecha de Check-In: ";
            cin >> fechaCheckIn;

			//  |   Verificar si la habitación y el huésped son válidos por medio de punteros,   | 
			//  v   y si lo son los agrega al vector lista check in.                             v
            if (contenedorHabitacion->validarHabitacionReserva(codHabitacion) && contenedorHuesped->validarHuesped(cedHuesped))
            {
                CheckIn nuevoCheckIn(cedHuesped, codHabitacion, fechaCheckIn, estado, contadorConsecutivo++);
                listaCheckIn.push_back(nuevoCheckIn);

				contenedorHabitacion->actualizarEstadoHabitacion(codHabitacion, false); // cambia el estado de la habitacion por medio de su metodo, que accede a la habitacion
                cout << "---------------------------------------------------" << endl;
                cout << "\033[1;32mCheck-In realizado con éxito, Consecutivo: " << nuevoCheckIn.getConsecutivo() << "\033[0m" << endl;
                cout << "---------------------------------------------------" << endl;
            }

            
        }


        // Listar todos los Check-Ins
        void listarCheckIns()
        {
            if (listaCheckIn.empty())
            {
                cout << "---------------------------------------------------" << endl;
				cout << "\033[1;31mNo hay Check-Ins registrados.\033[0m" << endl;
                cout << "---------------------------------------------------" << endl;
				return;
            }
            else
            {
                for (int i = 0; i < listaCheckIn.size(); i++)
                {
                    listaCheckIn[i].getDatosCheckIn();

                }
            }
            cout << "Total de Check-Ins: " << listaCheckIn.size() << endl;
            cout << "-------------------------------------------------" << endl;
        }

        // Modificar un Check-In existente
        /*void modificarCheckIn()
        {
            int consecutivo;
            bool nuevoEstado;
            cout << "Ingrese el número de consecutivo del Check-In a modificar: ";
            cin >> consecutivo;
            cout << "Ingrese el nuevo estado (0 = Procesado, 1 = Pendiente): ";
            cin >> nuevoEstado;

            for (int i = 0; i < listaCheckIn.size(); i++)
            {
                if (listaCheckIn[i].getConsecutivo() == consecutivo)
                {
                    listaCheckIn[i].setActualizarCheckIn(listaCheckIn[i].getCedHuesped(), listaCheckIn[i].getCodHabitacion(), listaCheckIn[i].getFechaCheckIn(), nuevoEstado);
                    cout << "-------------------------------------------------" << endl;
                    cout << "\033[1;32mCheck-In modificado con exito.\033[0m" << endl;
                    cout << "-------------------------------------------------" << endl;
                    return;
                }
            }
            cout << "-------------------------------------------------" << endl;
            cout << "\033[1;31mCheck-In no encontrado.\033[0m" << endl;
            cout << "-------------------------------------------------" << endl;
        }*/

       // Cargar los Check-Ins desde un archivo 
        void RecuperarContenedor()
        {
            ifstream archivo("checkin.txt");
            listaCheckIn.clear();
            string linea;
            int ultimoConsecutivo = 0; // Para almacenar el último consecutivo leído
            while (getline(archivo, linea)) 
            {
                stringstream ss(linea); 
                string cedHuespedStr, codHabitacionStr, fechaCheckIn, estadoStr, consecutivoStr;

                // Leer los valores separados por comas
                getline(ss, cedHuespedStr, '-');
                getline(ss, codHabitacionStr, '-');
                getline(ss, fechaCheckIn, '-');
                getline(ss, estadoStr, '-');
                getline(ss, consecutivoStr);

                // Convertir los datos a los tipos correctos
                int cedHuesped = stoi(cedHuespedStr);
                int codHabitacion = stoi(codHabitacionStr);
                bool estado = (estadoStr == "true");
                int consecutivo = stoi(consecutivoStr);
                // Actualizar el último consecutivo leído

                if (consecutivo > ultimoConsecutivo)
                    ultimoConsecutivo = consecutivo;

                // Crear un nuevo objeto CheckIn y agregarlo a la lista
                CheckIn checkIn(cedHuesped, codHabitacion, fechaCheckIn, estado, consecutivo);
                listaCheckIn.push_back(checkIn);
            }
            archivo.close();

            // Establecer el contadorConsecutivo al valor siguiente del último consecutivo leído
            contadorConsecutivo = ultimoConsecutivo + 1;

            cout << "---------------------------------------------------" << endl;
            cout << "\033[1;32mDatos cargados desde el archivo con exito.\033[0m" << endl;
            cout << "---------------------------------------------------" << endl;
        }

        // Guardar los Check-Ins en un archivo 
        void GuardarContenedor()
        {
            ofstream archivo("checkin.txt");
            if (listaCheckIn.empty())
            {
                cout << "--------------------------------------------" << endl;
                cout << "\033[1;31mNo hay Check-Ins registrados\033[0m" << endl;
				cout << "--------------------------------------------" << endl; 
            }

            for (int i = 0; i < listaCheckIn.size(); i++)
            {
                archivo << listaCheckIn[i].getCedHuesped() << " - ";
				archivo << listaCheckIn[i].getCodHabitacion() << " - ";
				archivo << listaCheckIn[i].getFechaCheckIn() << " - ";
				archivo << listaCheckIn[i].getEstado() << " - ";
				archivo << listaCheckIn[i].getConsecutivo() << endl;
			}
            archivo.close();
            cout << "--------------------------------------------" << endl;
            cout << "\033[1;32mDatos guardados en el archivo con exito.\033[0m" << endl;
            cout << "--------------------------------------------" << endl;
        }

        void menucheckIn()
        {
            char opcion;

            do
            {
                system("cls");
                cout << "*********| Menu Check-In |**********" << endl;
                cout << "* 1- Realizar Check-In de una habitacion      *" << endl;
                cout << "* 2- Consultar todos los Check-Ins            *" << endl;
                cout << "* 3- Modificar un Check-In                    *" << endl;
                cout << "* 4- Guardar contenedor                       *" << endl;
                cout << "* 5- Recuperar datos del archivo              *" << endl;
                cout << "* 6- Regresar a menú principal                *" << endl;
                cout << "****************************************" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;

                switch (opcion)
                {
                case '1':
                {
                    system("cls");
                    realizarCheckIn();
                    system("pause");
                    break;
                }
                case '2':
                {
                    system("cls");

                    listarCheckIns();

                    system("pause");
                    break;
                }
                case '3':
                {
                    system("cls");
                    /*modificarCheckIn();*/

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
        

   
    




	
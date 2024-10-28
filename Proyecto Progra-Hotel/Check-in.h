#pragma once
#include "Librerias.h"

class CheckIn
{
private:
	int cedHuesped;
	int codHabitacion;
	string fechaCheckIn;
	bool estado = true;
	int consecutivo;

public:
	CheckIn(int _cedHuesped, int _codHabitacion, string _fechaCheckIn, int _consecutivo, bool _estado)
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
        cout << "-------------------------------------------------" << endl;
		cout << "Cedula del Huesped:       " << cedHuesped << endl;
		cout << "Numero de Habitacion:     " << codHabitacion << endl;
		cout << "Fecha Ingreso:            " << fechaCheckIn << endl;
		cout << "Estado:                   " << (estado ? "\033[33m Pendiente \033[0m" : "\033[32mProcesado\033[0m") << endl;
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

	void setestadoCheckIn(bool _estado)
	{
		this->estado = _estado;
	}



};


    class ContenedorCheckIn
    {
    private:
        vector<CheckIn> listaCheckIn;
        ContenedorHuespedes* contenedorHuesped;
        ContenedorHabitaciones* contenedorHabitacion;
        int contadorConsecutivo = 1;

    public:

        
        ContenedorCheckIn(ContenedorHabitaciones& contenedorHabitacion, ContenedorHuespedes& contenedorHuesped)
        {
			this->contenedorHabitacion = &contenedorHabitacion; // se acceden a los datos por medio de puntos,
            this->contenedorHuesped = &contenedorHuesped;       //trayendo los datos de sus clases correspodientes

          
        }

        int obtenerNumHabitacion(int numConsecutivo) const
        {
            for (const auto& checkIn : listaCheckIn)
            {
                if (checkIn.getConsecutivo() == numConsecutivo)
                {
                    return checkIn.getCodHabitacion();
                }
            }
            throw std::invalid_argument("Número de consecutivo no encontrado");
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
			

			time_t timestamp; // variable para almacenar la fecha y hora actual
			time(&timestamp); // obtener la fecha y hora actual de la computadora

			struct tm timeInfo; // estructura para almacenar la fecha y hora desglosada
			localtime_s(&timeInfo, &timestamp); // estructura para almacenar la fecha y hora
            
			char buffer[80]; // buffer para almacenar la fecha y hora formateada
			strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", &timeInfo); // formatear la fecha y hora
            

			fechaCheckIn = buffer; // asignar la fecha y hora formateada a la variable fechaCheckIn


			//  |   Verificar si la habitación y el huésped son válidos por medio de punteros,   | 
			//  v   y si lo son los agrega al vector lista check in.                             v
            if (contenedorHabitacion->validarHabitacionReserva(codHabitacion) && contenedorHuesped->validarHuesped(cedHuesped))
            {
                CheckIn nuevoCheckIn(cedHuesped, codHabitacion, fechaCheckIn, contadorConsecutivo++, estado);
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
                string cedHuespedStr, codHabitacionStr, fechaCheckIn, consecutivoStr, estadoStr;

                // Leer los valores separados por comas
                getline(ss, cedHuespedStr, '-');
                getline(ss, codHabitacionStr, '-');
                getline(ss, fechaCheckIn, '-');
                getline(ss, consecutivoStr, '-');
                getline(ss, estadoStr);

                // Convertir los datos a los tipos correctos
                int cedHuesped = stoi(cedHuespedStr);
                int codHabitacion = stoi(codHabitacionStr);
                bool estado = (estadoStr == "Pendiente");
                int consecutivo = stoi(consecutivoStr);
                // Actualizar el último consecutivo leído

                if (consecutivo > ultimoConsecutivo)
                    ultimoConsecutivo = consecutivo;

                // Crear un nuevo objeto CheckIn y agregarlo a la lista
                CheckIn checkIn(cedHuesped, codHabitacion, fechaCheckIn,consecutivo, estado);
                listaCheckIn.push_back(checkIn);
            }
            archivo.close();

            // Establecer el contadorConsecutivo al valor siguiente del último consecutivo leído
            contadorConsecutivo = ultimoConsecutivo + 1;

			contenedorHabitacion->RecuperarDatos();

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
                archivo << listaCheckIn[i].getCedHuesped() << "-" <<
                    listaCheckIn[i].getCodHabitacion() << "-" <<
                    listaCheckIn[i].getFechaCheckIn() << "-" <<
                    listaCheckIn[i].getConsecutivo() << "-" <<
                    (listaCheckIn[i].getEstado() ? "Pendiente" : "Procesado")
                    << endl;
			}
            archivo.close();
			contenedorHabitacion->guardarContenedor();
            cout << "--------------------------------------------" << endl;
            cout << "\033[1;32mDatos guardados en el archivo con exito.\033[0m" << endl;
            cout << "--------------------------------------------" << endl;
        }


        bool validarConsecutivo(int numConsecutivo) // para validad el numero de consecutivo en el check out 
        {
			for (int i = 0; i < listaCheckIn.size(); i++)
			{
				if (listaCheckIn[i].getConsecutivo() == numConsecutivo)
				{
				
					return listaCheckIn[i].getConsecutivo();
				}
			}
			
            return false;
        }



		void actualizarEstadoCheckIn(int consecutivo, bool estado) // para actualizar el estado del check in por medio del check-Out
        {
			for (int i = 0; i < listaCheckIn.size(); i++)
			{
				if (listaCheckIn[i].getConsecutivo() == consecutivo)
				{
					listaCheckIn[i].setestadoCheckIn(estado);
					return;
				}
			}
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
                cout << "* 3- Guardar contenedor en archivo            *" << endl;
                cout << "* 4- Recuperar datos del archivo              *" << endl;
                cout << "* 5- Regresar a menú principal                *" << endl;
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
                    GuardarContenedor();
                    system("pause");
                    break;
                }
                case '4':
                {
                    system("cls");
                    RecuperarContenedor();
                    system("pause");
                    break;
                }
                case '5':
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
            } while (opcion != '5');

        }


        
    };
        

   
    




	
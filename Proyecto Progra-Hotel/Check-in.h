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
			this->contenedorHabitacion = &contenedorHabitacion;
            this->contenedorHuesped = &contenedorHuesped;
        }



        // Cargar los Check-Ins desde un archivo binario
        void RecuperarContenedor()
        {
            ifstream archivo("checkin.txt");
            listaCheckIn.clear();
            string linea;
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

                // Crear un nuevo objeto CheckIn y agregarlo a la lista
                CheckIn checkIn(cedHuesped, codHabitacion, fechaCheckIn, estado, consecutivo);
                listaCheckIn.push_back(checkIn);
            }
            archivo.close();
            cout << "Datos cargados desde el archivo con exito." << endl;
        }

        // Guardar los Check-Ins en un archivo binario
        void GuardarContenedor()
        {
            ofstream archivo("checkin.txt");
            if (listaCheckIn.empty())
            {
                cout << "--------------------------------------------" << endl;
				cout << "No hay Check-Ins registrados" << endl;
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
            cout << "Datos guardados en el archivo con exito." << endl;
        }

        // Realizar un nuevo Check-In
        void realizarCheckIn()
        {
            RecuperarContenedor();

            int cedHuesped, codHabitacion;
            string fechaCheckIn;
            bool estado = true;

            cout << "Ingrese la cédula del huésped: ";
            while (!(cin >> cedHuesped) || cedHuesped < 1 || cedHuesped > 9999999999)
            {
				cout << "Ingrese nuevamente la cedula del huesped (Incluir ceros): ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

            cout << "Ingrese el numero de la habitación: ";
            while (!(cin >> codHabitacion) || codHabitacion < 1) {
                cout << "Ingrese nuevamente: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Ingrese la fecha de Check-In: ";
            cin >> fechaCheckIn;

            if (contenedorHabitacion->validarHabitacionReserva(codHabitacion) && contenedorHuesped->validarHuesped(cedHuesped)) 
            {
                CheckIn nuevoCheckIn(cedHuesped, codHabitacion, fechaCheckIn, estado, contadorConsecutivo++);
                listaCheckIn.push_back(nuevoCheckIn);
                cout << "Check-In realizado con éxito." << endl;
            }

            
        }


        // Listar todos los Check-Ins
        void listarCheckIns()
        {
            for (int i = 0; i < listaCheckIn.size(); i++)
            {
                cout << "Consecutivo: " << listaCheckIn[i].getConsecutivo()
                    << ", Huesped: " << listaCheckIn[i].getCedHuesped()
                    << ", Habitacion: " << listaCheckIn[i].getCodHabitacion()
                    << ", Fecha Ingreso: " << listaCheckIn[i].getFechaCheckIn()
                    << ", Estado: " << (listaCheckIn[i].getEstado() ? "Pendiente" : "Procesado") << endl;
            }
            cout << "Total de Check-Ins: " << listaCheckIn.size() << endl;
        }

        // Modificar un Check-In existente
        void modificarCheckIn()
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
                    cout << "Check-In modificado con exito." << endl;
                    return;
                }
            }
            cout << "Check-In no encontrado." << endl;
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
                    modificarCheckIn();

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
                    system("pause");
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
        

   
    




	
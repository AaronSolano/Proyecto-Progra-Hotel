#pragma once
#include "Librerias.h"
#include "CheckOut.h"

class ContenedorCheckOut
{
private:
	vector<checkOut> ListaCheckOuts;
	ContenedorCheckIn* contenedorCheckIn;
	ContenedorHabitaciones* contenedorHabitaciones;
	ContenedorHuespedes* contenedorHuespedes;

public:

	ContenedorCheckOut( ContenedorCheckIn& contenedorCheckIn, ContenedorHabitaciones& contenedorHabitaciones, ContenedorHuespedes& contenedorHuespedes)
	{
		this->contenedorCheckIn = &contenedorCheckIn;
		this->contenedorHabitaciones = &contenedorHabitaciones;
		this->contenedorHuespedes = &contenedorHuespedes;
	}

	void RealizarCheckOut()
	{
		int numConsecutivo;
		string FechaCheckOut;
		

		cout << "Ingrese el numero de consecutivo: ";
		while (!(cin >> numConsecutivo))
		{
			cin.clear();
			cin.ignore(123, '\n');
			cout << "\033[1;33mIngrese un numero valido: \033[0m";
		}
		
		for (int i = 0; i < ListaCheckOuts.size(); i++) // recorrer la lista de check-outs para verificar si ya se realizo el check-out
		{
			if (ListaCheckOuts[i].getNumConsecutivo() == numConsecutivo)
			{
				cout << "\033[31mEl Check-Out ya ha sido realizado para este numero de consecutivo\033[0m" << endl;
				return;
			}
		}

		if (!contenedorCheckIn->validarConsecutivo(numConsecutivo))  // verificar si el numero de consecutivo existe
		{
			cout << "\033[31mEl numero de consecutivo no existe\033[0m" << endl;
			return;
		}

        int numHabitacion = contenedorCheckIn->obtenerNumHabitacion(numConsecutivo);

		// ingreso de la fecha de check-out


		time_t timestamp; // variable para almacenar la fecha y hora actual
		time(&timestamp); // obtener la fecha y hora actual de la computadora

		struct tm timeInfo; // estructura para almacenar la fecha y hora desglosada
		localtime_s(&timeInfo, &timestamp); // estructura para almacenar la fecha y hora

		char buffer[80]; // buffer para almacenar la fecha y hora formateada
		strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", &timeInfo); // formatear la fecha y hora


		FechaCheckOut = buffer; // asignar la fecha y hora formateada a la variable fechaCheckIn


		checkOut nuevoCheckOut(numConsecutivo, FechaCheckOut);
		ListaCheckOuts.push_back(nuevoCheckOut);

		cout << "\033[1;32mCheck-Out realizado con exito\033[0m" << endl;
		contenedorCheckIn->actualizarEstadoCheckIn(numConsecutivo, false); // cambiar el estado del check-in a procesado
		contenedorHabitaciones->actualizarEstadoHabitacion(numHabitacion, true); // cambiar el estado de la habitacion a disponible

		cout << "----------------------| Factura de Hospedaje |----------------------" << endl;
		contenedorCheckIn->FacturaHospedaje(numConsecutivo);

		
	}

	void consultarCheckOut()
	{
		int cantidadCheckOuts = ListaCheckOuts.size();
		if (ListaCheckOuts.empty())
		{

			cout << "--------------------------------------------" << endl;
			cout << "\033[31mNo hay Check-Outs Registrados !!!\033[0m" << endl;
			cout << "--------------------------------------------" << endl;
		}
		else
		{
			
			cout << "\033[1;33m------------------- Lista de Check-Outs Registrados --------------------\033[0m" << endl;
			
			for (int i = 0; i < ListaCheckOuts.size(); i++)
			{
				cout << "--------------------------------------------------------------------" << endl;
				cout << "Fecha de Check-Out: " << ListaCheckOuts[i].getFechaCheckOut() << endl;
				contenedorCheckIn->FacturaHospedaje(ListaCheckOuts[i].getNumConsecutivo());
				
			}

		}
		
		cout << "\033[1;33mCantidad de Check-Outs Registrados: \033[0m" << cantidadCheckOuts << endl;
		cout << "--------------------------------------------------------------------" << endl;
	}

	void GuardarDatos()
	{
		if (ListaCheckOuts.empty())
		{
			cout << "--------------------------------------------" << endl;
			cout << "\033[31mNo hay Check-Outs Registrados !!!\033[0m" << endl;
			cout << "--------------------------------------------" << endl;
		}
		else
		{
			ofstream archivo("CheckOut.txt");

			if (archivo.is_open()) {
				for (int i = 0; i < ListaCheckOuts.size(); i++)
				{
					archivo << ListaCheckOuts[i].getNumConsecutivo()
						<< "-" << ListaCheckOuts[i].getFechaCheckOut() 
						<< endl;
						
				}
				archivo.close();
				contenedorHabitaciones->guardarContenedor();
				contenedorCheckIn->GuardarContenedor();
				cout << "----------------------------------------------------------------" << endl;
				cout << "\033[32mLista de Check-Outs almacenados en el archivo correctamente...\033[0m" << endl;
				cout << "----------------------------------------------------------------" << endl;
			}
		}

	}

	void recuperarDatos()
	{
		ListaCheckOuts.clear();

		ifstream archivo("CheckOut.txt");

		if (archivo.is_open())
		{
			string linea;

			while (getline(archivo, linea))
			{
				stringstream ss(linea);
				string numConsecutivo,fechaCheckOut;

				getline(ss, numConsecutivo, '-');
				getline(ss, fechaCheckOut);

				int _numConsecutivoInt = stoi(numConsecutivo);

				checkOut nuevoCheckOut(_numConsecutivoInt, fechaCheckOut);
				ListaCheckOuts.push_back(nuevoCheckOut);
			}
			archivo.close();

			

			cout << "--------------------------------------------" << endl;
			cout << "\033[32mDatos de Check-Outs recuperados correctamente...\033[0m" << endl;
			cout << "--------------------------------------------" << endl;
		}
		
	}





	void menuCheckOut()
	{
		char opcion;
		do
		{
			system("cls");
			cout << "************************************" << endl;
			cout << "* 1. - Realizar Check-Out         - *" << endl;
			cout << "* 2. - Consultar Check-Out        - *" << endl;
			cout << "* 3. - Guardar Datos              - *" << endl;
			cout << "* 4. - Recuperar Datos            - *" << endl;
			cout << "* 5. - Salir                      - *" << endl;
			cout << "************************************" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;

			switch (opcion)
			{
			case '1':
			{
				RealizarCheckOut();
				system("pause");
				break;
			}
			case '2':
			{
				consultarCheckOut();
				
				system("pause");
				break;
			}
			case '3':
			{
				GuardarDatos();
				system("pause");
				break;
			}
			case '4':
			{
				recuperarDatos();
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
				cout << "\033[31mOpcion no valida\033[0m" << endl;
				system("pause");
				break;
			}
			}
		} while (opcion != '5');

	}





};
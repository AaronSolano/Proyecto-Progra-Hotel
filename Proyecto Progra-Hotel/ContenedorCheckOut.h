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

	void ConsultarCheckOut()
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

		if (!contenedorCheckIn->validarConsecutivo(numConsecutivo) == numConsecutivo)
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
		
	}



};
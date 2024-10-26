#pragma once
#include "Librerias.h"

class Habitacion
{
private:
	int NumeroHabitacion;
	int Piso;
	string Descripcion;
	int CantidadPersonas;
	double PrecioXnoche;
	bool Estado = true;

public:

	Habitacion(int _numHabitacion, int _piso, string _descripcion, int _cantidaPersonas, double _precioXnoche)
	{
		this->NumeroHabitacion = _numHabitacion;
		this->Piso = _piso;
		this->Descripcion = _descripcion;
		this->CantidadPersonas = _cantidaPersonas;
		this->PrecioXnoche = _precioXnoche;
	
	}

	void setActualizarHabitacion(int _piso, string _descripcion, int _cantidadPersonas, double _precioXnoche)
	{
		this->Piso = _piso;
		this->Descripcion = _descripcion;
		this->CantidadPersonas = _cantidadPersonas;
		this->PrecioXnoche = _precioXnoche;
	}

	void getDatosHabitacion()
	{
		cout << "--------------------------------------------" << endl;
		cout << "Numero de habitacion: " << NumeroHabitacion << endl;
		cout << "Piso:                 " << Piso << endl;
		cout << "Descripcion:          " << Descripcion << endl;
		cout << "Cantidad de personas: " << CantidadPersonas << endl;
		cout << "Precio por noche:     " << PrecioXnoche << endl;
        cout << "Estado:               " << (Estado ? "\033[32mDisponible\033[0m" : "\033[31mOcupada\033[0m") << endl;
		cout << "--------------------------------------------" << endl;

	}

	const int getNumeroHabitacion() const
	{
		return NumeroHabitacion;
	}

	const int getPiso() const
	{
		return Piso;
	}

	const string getDescripcion() const
	{
		return Descripcion;
	}

	const int getCantidadPersonas() const
	{
		return CantidadPersonas;
	}

	const double getPrecioXnoche() const
	{
		return PrecioXnoche;
	}

	const bool getEstado() const
	{
		return Estado;
	}

	void setEstado(bool _estado)
	{
		Estado = _estado;
	}


};
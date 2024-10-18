#pragma once
#include "Librerias.h"

class Huesped
{
private:

	int Cedula;
	string Nombre;
	string Apellido;
	int Telefono;
	string Correo;

public:
	Huesped(int _cedula, string _nombre, string _apellido, int _telefono, string _correo)
	{
		this->Cedula = _cedula;
		this->Nombre = _nombre;
		this->Apellido = _apellido;
		this->Telefono = _telefono;
		this->Correo = _correo;

	}

	void setActualizarHuesped(string _nombre, string _apellido, int _telefono, string _correo)
	{
		this->Nombre = _nombre;
		this->Apellido = _apellido;
		this->Telefono = _telefono;
		this->Correo = _correo;
	}

	void getDatosHuesped()
	{
		cout << "--------------------------------------------" << endl;
		cout << "Cedula:    " << this->Cedula << endl;
		cout << "Nombre:    " << this->Nombre << endl;
		cout << "Apellidos: " << this->Apellido << endl;
		cout << "Telefono:  " << this->Telefono << endl;
		cout << "Correo:    " << this->Correo << endl;
		cout << "--------------------------------------------" << endl;

	}
	const int getCedula() const
	{
		return this->Cedula;
	}
	const string getNombre() const
	{
		return this->Nombre;
	}
	const string getApellido() const
	{
		return this->Apellido;
	}
	const int getTelefono() const
	{
		return this->Telefono;
	}
	const string getCorreo() const
	{
		return this->Correo;
	}
};
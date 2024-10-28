#pragma once
#include "Librerias.h"

class checkOut
{
private:
	int numConsecutivo;
	string FechaCheckOut;

public:

	checkOut(int _numConsecutivo, string _FechaCheckOut)
	{
		this->numConsecutivo = _numConsecutivo;
		this->FechaCheckOut = _FechaCheckOut;
	}

	void getDatosCheckOut()
	{
		cout << "-------------------------------------------------" << endl;
		cout << "Numero de Consecutivo: " << this->numConsecutivo << endl;
		cout << "Fecha de Check-Out: " << this->FechaCheckOut << endl;
		cout << "-------------------------------------------------" << endl;
	}

	const int getNumConsecutivo() const
	{
		return this->numConsecutivo;
	}
	const string getFechaCheckOut() const
	{
		return this->FechaCheckOut;
	}
	
};
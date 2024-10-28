#pragma once
#include "Librerias.h"
#include "CheckOut.h"

class ContenedorCheckOut
{
private:
	vector<checkOut> ListaCheckOuts;
	ContenedorCheckIn* contenedorCheckIn;

	public:

	ContenedorCheckOut( ContenedorCheckIn& contenedorCheckIn)
	{
		this->contenedorCheckIn = &contenedorCheckIn;
		
	}

	



};
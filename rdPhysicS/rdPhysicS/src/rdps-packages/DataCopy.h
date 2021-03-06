#ifndef	__DATA_COPY_H__
#define	__DATA_COPY_H__

#include "../GlobalDefs.h"
#include "../World.h"

RDPS_BEGIN
	PKG_BEGIN
		/********************************************************************************************************************************************
		 *
		 * Classe responsavel em armazenar os dados que ser�o enviados para
		 * o dispositivo openCL como copia.
		 *
		 ********************************************************************************************************************************************/
		template<class T>
		class DataCopy
		{
		private:
			T data;
			int id;

		public:
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * recebe como rarametro o dados que ser� enviado
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			DataCopy(T &_data);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor de copia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			DataCopy(const DataCopy &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna o dado
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			inline T GetData() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Fun��o auxiliar que retorna o id
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			inline int GetId() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao de sobrecar de operador para copia de dados
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			inline DataCopy &operator=(const DataCopy &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Atualiza os dados na aplicacao OpenCL
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			inline DataCopy &UpdateData(T &_data);
		};

		template<class T>
		inline DataCopy<T>::DataCopy(T &_data) :
							data(_data), 
							id(-1)
		{}

		template<class T>
		inline DataCopy<T>::DataCopy(const DataCopy &other) :
							data(other.data),
							id(other.id)
		{}

		template<class T>
		inline T DataCopy<T>::GetData() const
		{
			return data;
		}

		template<class T>
		inline int DataCopy<T>::GetId() const
		{
			return id;
		}

		template<class T>
		inline DataCopy &DataCopy<T>::operator=(const DataCopy &other)
		{
			data = other.data;
			id = other.id;
			return (*this);
		}

		template<class T>
		inline DataCopy<T> &DataCopy<T>::UpdateData(T &_data)
		{
			data = _data;
			return (*this);
		}

		
	PKG_END
RDPS_END

#endif//__DATA_COPY_H__


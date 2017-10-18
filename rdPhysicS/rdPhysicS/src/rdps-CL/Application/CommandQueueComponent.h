#ifndef	__COMMAND_QUEUE_COMPONENTE_H__
#define	__COMMAND_QUEUE_COMPONENTE_H__

#include "BaseClComponent.h"
#include "ClConfig.h"
#include "MemObjectComponent.h"
#include "../Util/LogError.h"

RDPS_BEGIN
	CL_BEGIN
		class ContextComponent;
		class DeviceComponent;
		class ItensWorkGroupComponent;
		class KernelComponent;

		/********************************************************************************************************************************************
		 *
		 * Classe que contem a fila para enfileirar, escrever e ler os objetos 
		 * do kernel 
		 *
		 ********************************************************************************************************************************************/
		class CommmandQueueComponent : BaseClComponent<cl_command_queue>
		{
		public:
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * Adiciona a referencia do pai nullptr
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			CommmandQueueComponent();
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * Ocorre a constru��o da Fila utilizando um  Contexto e um device j� criado.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			CommmandQueueComponent(const ContextComponent &context, 
								    const DeviceComponent &device);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * Adiciona a referencia do pai um cl_command_queue j� construido fora.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			CommmandQueueComponent(const cl_command_queue &queue);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor de c�pia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			CommmandQueueComponent(const CommmandQueueComponent &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Destrutor
			 * Destroi chamando a fun��o Release();
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			~CommmandQueueComponent();
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Destroi o Contexto.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual void Release();
			virtual void Retain();
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Fun��o que retorna uma string contendo as informa��es da fila
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			std::string GetInfo(const cl_command_queue_info paramName);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Fun��o auxiliar para a leitura dos dados de retorna da fun��o kernel.
			 * Recebe o Objeto de mem�ria referente ao buffer na CPU/DISPOSITIVO,
			 * o tamanho do buffer e o a referencia do buffer.
			 * Generico por que pode ser retornado qualquer tipo de dados validos.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			template<class T>
			inline CommmandQueueComponent &ReadBuffer(const MemObjectComponent &memObj, const size_t size, T *data);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Fun��o auxiliar para a Escrita dos dados da fun��o kernel no DISPOSITIVO.
			 * Recebe o Objeto de mem�ria referente ao buffer na CPU/DISPOSITIVO,
			 * o tamanho do buffer e o a referencia do buffer.
			 * Generico por que pode ser lido qualquer tipo de dados validos.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			template<class T>
			inline CommmandQueueComponent &WriteBuffer(const MemObjectComponent &memObj, const size_t size, T *data);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Fun��o auxiliar que d� o comando para ocorrer o processamento dos dados no DISPOSITIVO.
			 * Recebe como parametro a refer�ncia da kernel que ser� executado, Refer�ncia ao n�mero de
			 * dimen��es dos grupos de trabalho, n�meros de itens globais e itens locais em cada grupo.
			 * os itens de trabalho s�o necess�rios para a execu��o com sucesso.
			 *--------------------------------------------------------------------------------------------------------------------------------------*/
			CommmandQueueComponent &EnqueueNDRangeKernel(const KernelComponent &kernel, const ItensWorkGroupComponent &itens);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Fun��o auxiliar que d� o comando para ocorrer o processamento dos dados no DISPOSITIVO.
			 * Recebe como parametro a refer�ncia da kernel que ser� executado.
			 *--------------------------------------------------------------------------------------------------------------------------------------*/
			CommmandQueueComponent &EnqueueTask(const KernelComponent &kernel);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Fun��o de sobrecar de operador para c�pia, chama a fun��o de c�pia do pai.
			 *-------------------------------------------------------------------------------------------------------------------------------------*/
			inline CommmandQueueComponent &operator=(const CommmandQueueComponent &other)
			{
				if (this != &other)
					BaseClComponent<Type>::operator=(other);
				return (*this);
			}
		};

		//posteriormente passa uma classe ArrayBuffer contendo o id do mem_obj, 
		//os dados do do buffer, tamanho do buffer em bytes e quantidade de elementos 
		//no buffer.
		template<class T>
		inline CommmandQueueComponent 
					&CommmandQueueComponent::ReadBuffer(const MemObjectComponent &memObj,
														const size_t size, T *data)
		{
			/*adicionar mem_obj para funcionar*/
			if (int status = clEnqueueReadBuffer(object, memObj(), CL_TRUE,
												 0, sizeof(T) * size, data, 
												 0, nullptr, nullptr       ))
			{
				Logger::Log("ERROR when writing the data in the buffer."
							"\nERROR: " + std::to_string(status));
			}
			return (*this);
		}

		template<class T>
		inline CommmandQueueComponent 
				&CommmandQueueComponent::WriteBuffer(const MemObjectComponent &memObj, 
													 const size_t size, T *data)
		{
			/*adicionar mem_obj para funcionar*/
			if (int status = clEnqueueWriteBuffer(object, memObj(), CL_TRUE, 
												  0, sizeof(T) * size, data, 
												  0, nullptr, nullptr))
			{
				/****Tratar erro****/
			}
			return (*this);
		}
	CL_END
RDPS_END

#endif//__COMMAND_QUEUE_COMPONENTE_H__
#ifndef	__MESSAGE_H__
#define	__MESSAGE_H__

#include "..\..\GlobalDefs.h"
#include <string>

RDPS_BEGIN
	PDCT_BEGIN

		class Entity;
		/********************************************************************************************************************************************
		 *
		 * Classe auxiliar para guardar as mensagens enviadas.
		 * Nela consiste:
		 * -> Entity *sender: uma referencia de quem esta enviando;
		 * -> Entity *receiver: uma referencia de quem esta recebendo;
		 * -> std::string message: a mensagem;
		 * -> void *data: o dado extra que ser� enviado para possivelmente 
		 *    ser processado por quem recebe.
		 *
		 ********************************************************************************************************************************************/
		class Message
		{
		private:
			Entity *sender;
			Entity *receiver;
			std::string message;
			void *data;

		public:
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * recebe como parametro Entity *msgSender quem esta enviando,
			 * Entity *msgReceiver para que sera a mensagem,
			 * const std::string msg a mensagem,
			 * void *_data dados extras que por padrao eh nulo
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Message(Entity *msgSender,
					Entity *msgReceiver,
					const std::string msg,
					void *_data = nullptr);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor de copia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Message(const Message &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Destrutor padrao
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			~Message();

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna a referencia de quem enviou a mensagem
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Entity *GetSender() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna a referencia de quem vai receber
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Entity *GetReceiver() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna a mensagem
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			const std::string &GetMessage() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna a referencia aos dados extras que 
			 * possivelmente sera processado
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			void *GetData() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a referencia de quem envia a mensagem
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Message &SetSender(Entity *_sender);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a referencia de quem vai receber
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Message &SetReceiver(Entity *_receiver);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a mensagem
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Message &SetMessage(const std::string msg);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar os dados estras
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Message &SetData(void *_data);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar de sobrecarga de operador para copia de dados
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Message &operator=(const Message &other);
		};

	PDCT_END
RDPS_END

#endif//__MESSAGE_H__
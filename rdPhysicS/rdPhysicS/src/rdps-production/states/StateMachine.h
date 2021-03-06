#ifndef	__STATE_MACHINE_H__
#define	__STATE_MACHINE_H__

#include "..\base\State.h"

RDPS_BEGIN
	PDCT_BEGIN

		class Collaborator;

		/********************************************************************************************************************************************
		 *
		 * Classe Resposavel em gerenciar os estados de que a possui.
		 * Faz a troca de estados quando necessario e a execucao deste estado,
		 * tambem da o  comando para tratar as mensagens recebidas.
		 *
		 * Nela consiste:
		 * -> Collaborator *myOwner: uma referencia ao colaborador que possui esse gerenciador;
		 * -> State<Collaborator> *currentState: o estado atual;
		 * -> State<Collaborator> *previousState: o estado anterior;
		 * -> State<Collaborator> *globalState: o estado global.
		 *
		 ********************************************************************************************************************************************/
		class StateMachine
		{
		private:
			Collaborator *myOwner;
			State<Collaborator> *currentState;
			State<Collaborator> *previousState;
			State<Collaborator> *globalState;

		public:
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * recebe como parametro a referencia de que possui esse gerenciador
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine(Collaborator *owner);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor de copia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine(const StateMachine &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Destrutor padrao
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			~StateMachine();

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que gera uma copia do objeto.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine *Clone() const;

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Fun��o de sobrecarga de operador para c�pia de dados de outra StateMachine
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine &operator=(const StateMachine &other);

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna a referencia de quem possui esse gerenciador 
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Collaborator *GetOwner() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna o estado atual
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			State<Collaborator> *GetCurrentState()  const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna o estado anterior
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			State<Collaborator> *GetPreviousState() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna o estado global
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			State<Collaborator> *GetGlobalState()   const;

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que seta o estado atual
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine &SetCurrentState(State<Collaborator> *_currentState);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que seta o estado anterior
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine &SetPreviousState(State<Collaborator> *_previousState);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que seta o estado global
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine &SetGlobalState(State<Collaborator> *_globalState);

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que da o comando de execucao dos estados
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine &Update();
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que faz a troca de estados.
			 * o estado anterior recebe a referencia do estado atual,
			 * e o atual da o comando exit e troca para o novo estado.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine &ChangeState(State<Collaborator> *newState);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Reverte para o estado anterior
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			StateMachine &ReverToPreviousState();
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que trata as mensagens
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			bool HandleMessage(const Message &message);
		};

	PDCT_END
RDPS_END

#endif//__STATE_MACHINE_H__
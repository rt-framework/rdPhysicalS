#ifndef	__ACTOR_H__
#define	__ACTOR_H__

#include "..\..\GlobalDefs.h"
#include <string>
#include <RTmath.h>

RDPS_BEGIN
	FRWK_BEGIN
		
		class Transform;

		/********************************************************************************************************************************************
		 *
		 * Classe Ator que contem apenas um transform e uma tag
		 * para possiveis criacoes de objetos vazios ou containers.
		 * Os objetos que tiverem transformações geometricas precisam
		 * herdar desta classe.
		 *
		 ********************************************************************************************************************************************/
		class Actor
		{
		protected:
			Transform *transform;
			std::string tag;

		public:
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor.
			 * Cria o transform
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Actor();
			//Actor(Transform *_transform);
			/*Actor(const RT::Vec3f &position,
				  const RT::Vec3f &rotation,
				  const RT::Vec3f &scale);*/
			/*Actor(const RT::Vec3f &position);*/
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor de copia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Actor(const Actor &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Destrutor.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			~Actor();

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que gera uma copia do objeto
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Actor *Clone() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao de sobrecarga de operador para copia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Actor &operator=(const Actor &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna o tranform
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Transform *GetTransform() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna a tag (string)
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			const std::string &GetTag() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar dados no transform
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Actor &SetTansform(const Transform &_transform);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a tag
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Actor &SetTag(const std::string _tag);
		};

	FRWK_END
RDPS_END

#endif//__ACTOR_H__
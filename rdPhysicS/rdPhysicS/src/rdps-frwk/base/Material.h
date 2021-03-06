#ifndef	__MATERIAL_H__
#define	__MATERIAL_H__

#include "..\..\GlobalDefs.h"
#include <RTmath.h>

RDPS_BEGIN
	FRWK_BEGIN
		class Material
		{
		private:
			TypeMaterial type;

		public:
			Material(const TypeMaterial type);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor de copia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Material(const Material &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Destrutor padrao
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual ~Material();
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que gera uma copia do objeto.
			 * O filho desta classe deve reescrever esta funcao.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual Material *Clone() const = 0;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao de sobrecarga de operador para copia.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			Material &operator=(const Material &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			* Funcao auxiliar que retorna o tipo do material
			*---------------------------------------------------------------------------------------------------------------------------------------*/
			TypeMaterial GetType() const;

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a cor do Componente BRDF (ambient),
			 * recebendo como parametro um vector3 (valores de 0 a 1).
			 * O filho desta classe deve reescrever esta funcao.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual Material &SetColor(const RT::Vec3f &color) = 0;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a cor do Componente BRDF (ambient),
			 * recebendo como parametro um 3 floats (r, g, b - valores de 0 a 1).
			 * O filho desta classe deve reescrever esta funcao.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual Material &SetColor(const float r, const float g, const float b) = 0;
		};

	FRWK_END
RDPS_END

#endif//__MATERIAL_H__
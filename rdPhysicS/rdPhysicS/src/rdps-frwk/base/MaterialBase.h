#ifndef	__MATERIAL_BASE_H__
#define	__MATERIAL_BASE_H__

#include "Material.h"

RDPS_BEGIN
	FRWK_BEGIN
		
		class BRDF;
		/********************************************************************************************************************************************
		 *
		 * Classe Base para o material (todo material prcisa herdar desta class), 
		 * nela um Componente BRDF com a informa��o do ambientMaterial,
		 * o tipo do material que sera enviado para o dispositivo,
		 * e um bool que indicara se existira calculo de sombra.
		 * para o dispositivo.
		 *
		 ********************************************************************************************************************************************/
		class MaterialBase : public Material
		{
		protected:
			BRDF *ambient;
			bool shadow;

		public:
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * recebe um parametro que determina o tipo do material.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			MaterialBase(const TypeMaterial _type);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * recebe 3 parametros:
			 * -> uma cor;
			 * -> um multiplicador de potencia para a cor;
			 * -> tipo do material;
			 * A cor e float s�o para a criacao do Componete BRDF (ambient);
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			MaterialBase(const RT::Vec3f &color, 
					     const float _ambient,
				         const TypeMaterial _type);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * recebe 2 parametros:
			 * -> BRDF (ambient)
			 * -> tipo do material.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			MaterialBase(BRDF *_ambient,
				         const TypeMaterial _type);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor de copia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			MaterialBase(const MaterialBase &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Destrutor padrao
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual ~MaterialBase();
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que gera uma copia do objeto.
			 * O filho desta classe deve reescrever esta funcao.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual MaterialBase *Clone() const = 0;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao de sobrecarga de operador para copia.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			MaterialBase &operator=(const MaterialBase &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna o Componente BRDF (ambient).
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			BRDF *GetAmbient() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna o shadow
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			bool GetShadow() const;

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar os dados do Componente BRDF (ambient).
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			MaterialBase &SetAmbient(BRDF *_ambient);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a cor do Componente BRDF (ambient),
			 * recebendo como parametro um vector3 (valores de 0 a 1).
			 * O filho desta classe deve reescrever esta funcao.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual MaterialBase &SetColor(const RT::Vec3f &color) = 0;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a cor do Componente BRDF (ambient),
			 * recebendo como parametro um 3 floats (r, g, b - valores de 0 a 1).
			 * O filho desta classe deve reescrever esta funcao.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual MaterialBase &SetColor(const float r, const float g, const float b) = 0;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar o multiplicador de potencia para o Componenete BRDF (ambient).
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			MaterialBase &SetAmbientK(const float _ambient);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar o shadow.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			MaterialBase &SetShadow(const bool _shadow);

		};

	FRWK_END
RDPS_END

#endif//__MATERIAL_H__
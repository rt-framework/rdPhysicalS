#ifndef	__POINT_LIGHT_H__
#define	__POINT_LIGHT_H__

#include "..\base\Light.h"
#include <RTmath.h>

RDPS_BEGIN
	FRWK_BEGIN

		/********************************************************************************************************************************************
		 *
		 * Classe de iluminacao por ponto nela contem:
		 * -> position- posicao da luz;
		 * -> color - cor da luz
		 * -> ls - um percentual para o retorno da cor
		 * Ilumina toda a cena com apenas um raio de luz.
		 *
		 ********************************************************************************************************************************************/
		class PointLight : public Light
		{
		private:
			RT::Vec3f position;
			RT::Vec3f color;
			float ls;
			int indexObject;

		public:
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor
			 * recebe 3 parametros;
			 * posicao, cor, percentual e 
			 * um bool shadow que indica se havera calculo de sombra. 
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			PointLight(const RT::Vec3f &_position,
					   const RT::Vec3f &_color,
					   const float _ls,
					   const int _indexObject = -1,
					   bool shadow = true);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Construtor de copia
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			PointLight(const PointLight &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Destrutor padrao
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			~PointLight();

			int GetIndexObject() const;
			PointLight &SetIndexObject(const int index);

			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que gera uma copia do objeto.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			virtual Light *Clone() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao de sobrecarga de operador para copia.
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			PointLight &operator=(const PointLight &other);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna a posicao
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			const RT::Vec3f &GetPosition() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna a cor
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			const RT::Vec3f &GetColor() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar que retorna o percentual de cor
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			float GetLs() const;
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a cor atraves de um vector3
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			PointLight &SetColor(const RT::Vec3f &_color);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a cor atraves de um 3 floats
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			PointLight &SetColor(const float r, const float g, const float b);
			/*---------------------------------------------------------------------------------------------------------------------------------------
			 * Funcao auxiliar para setar a percetual de cor
			 *---------------------------------------------------------------------------------------------------------------------------------------*/
			PointLight &SetLs(const float _ls);
		};

	FRWK_END
RDPS_END

#endif//__POINT_LIGHT_H__

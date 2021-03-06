#include "SceneBase.h"
#include "..\camera\Camera.h"
#include "ObjectBase.h"
#include "Light.h"
#include "..\lights\AmbientLight.h"
#include "..\..\World.h"
#include "..\..\rdps-production\collaborators\ManagerObjects.h"
#include "..\..\rdps-production\Util\ObjectsHostPkg.h"
#include "..\includes_frwk.h"
#include <vector>

USING_RDPS
USING_FRWK

SceneBase::SceneBase() :
	camera(new Camera(RT::Vec3f(0.0f, 0.0f, -300.0f), 
					  RT::Vec3f(0.0f, 0.0f, 0.0f), 
					  RT::Vec3f(0.0f, 1.0f, 0.0f), 
					  600.0f)),
	ambient(new AmbientLight())
{
	World::GetManager()->SetCamera(camera);
	World::GetManager()->AddLight(ambient);
}

int SceneBase::AddObject(ObjectBase *obj)
{
	World::GetManager()->AddObject(obj);
	return (int)World::GetManager()->GetPackage()->GetObjects().size() - 1;
}

int SceneBase::AddLight(Light *light)
{
	World::GetManager()->AddLight(light);
	return (int)World::GetManager()->GetPackage()->GetLights().size() - 1;
}

int SceneBase::CreateCube(const RT::Vec3f &initPoint, 
						  const RT::Vec3f &size, 
						  Material *material)
{
	return AddObject(new Cube(initPoint, size, material));
}

int SceneBase::CreatePlane(const RT::Vec3f &point, 
						   const RT::Vec3f &normal, 
						   Material *material)
{
	return AddObject(new Plane(point, normal, material));
}

int SceneBase::CreateSphere(const RT::Vec3f &center, 
							const float radius, 
							Material *material)
{
	return AddObject(new Sphere(center, radius, material));
}

int SceneBase::CreatePointLight(const RT::Vec3f &point, 
								const RT::Vec3f &color, 
								const float exp)
{
	return AddLight(new PointLight(point, color, exp));
}

int SceneBase::CreatePointLight(EmissiveObject *lamp, 
								const RT::Vec3f &point, 
								const RT::Vec3f &color,
							    const float exp)
{
	return AddLight(new PointLight(point, color, exp, AddObject(lamp)));
}

int SceneBase::CreateAreaLight(EmissiveObject *lamp)
{
	return AddLight(new AreaLight(AddObject(lamp)));
}

ObjectBase *SceneBase::GetObject(const size_t id) const
{
	return World::GetManager()->GetPackage()->GetObject(id);
}

Light *SceneBase::GetLight(const size_t id) const
{
	return World::GetManager()->GetPackage()->GetLight(id);
}

SceneBase &SceneBase::SetAmbient(Light *_ambient)
{
	if (ambient)
		delete ambient;
	ambient = _ambient;

	return (*this);
}

SceneBase::~SceneBase()
{}

PKG Renderer *SceneBase::GetRenderer() const
{
	return World::GetRenderer();
}

Camera *SceneBase::GetCamera() const
{
	return camera;
}

Light *SceneBase::GetAmbientLight() const
{
	return ambient;
}

void SceneBase::Draw()
{
	camera->Render(*this);
}

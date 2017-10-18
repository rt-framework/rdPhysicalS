#include "MemObjectComponent.h"
#include "ContextComponent.h"
#include "../Util/LogError.h"

USING_RDPS
USING_CL

MemObjectComponent::MemObjectComponent() :
					 BaseClComponent<Type>()
{}

MemObjectComponent::MemObjectComponent(const ContextComponent &context,
										 const  ActionFile typeAction,
										 const size_t size               ) :
					 BaseClComponent<Type>(Create(context, typeAction, size))
{}

MemObjectComponent::MemObjectComponent(const cl_mem &memObj) :
					 BaseClComponent<Type>(memObj)
{}

MemObjectComponent::MemObjectComponent(const MemObjectComponent &other) :
					 BaseClComponent<Type>(other)
{}

MemObjectComponent::~MemObjectComponent()
{
	Release();
}

void MemObjectComponent::Release()
{
	if (object)
	{
		if (int status = clReleaseMemObject(object) !=
			CL_SUCCESS)
			Logger::Log("clReleaseMemObject - Error when destroying the" 
						"memory object. ERROR: " + std::to_string(status));

		object = nullptr;
	}
}

void MemObjectComponent::Retain()
{
	if (object)
	{
		if (int status = clRetainMemObject(object) !=
			CL_SUCCESS)
			Logger::Log("clRetainMemObject - ERROR: " + std::to_string(status));
	}
}

cl_mem MemObjectComponent::Create(const ContextComponent &context, 
								   const  ActionFile typeAction,
								   const size_t size)
{
	int status = 0;
	Type mem = clCreateBuffer(context(), typeAction, size, nullptr, &status);
	/*tratar erro*/
	return mem;
}
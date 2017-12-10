#pragma once
#include <CryEntitySystem/IEntityComponent.h>
#include <CryEntitySystem/IEntity.h>

////////////////////////////////////////////////////////
// Spawn point
////////////////////////////////////////////////////////
class CShip final : public IEntityComponent
{

public:
	CShip() = default;
	virtual ~CShip() {}

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CShip>& desc)
	{
		desc.SetGUID("{41316132-8A1E-4073-B0CD-A242FD3D2E99}"_cry_guid);
		desc.SetEditorCategory("Game");
		desc.SetLabel("Ship");
		desc.SetDescription("This is a ship point");
		desc.SetComponentFlags({ IEntityComponent::EFlags::Transform, IEntityComponent::EFlags::Socket, IEntityComponent::EFlags::Attach });

	}

	virtual void Initialize() override;

	void shipHop();

protected:
	int health;

};
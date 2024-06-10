#include "mock/ModImplMock.hpp"
#include <gtest/gtest.h>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/mod/states/ModStateWaitingDependenciesLoad.hpp>
#include <supermod/modloader/mod/states/ModStateWaitingDependentsUnload.hpp>
#include <supermod/game/Game.hpp>

using namespace sm;
using namespace sm::io;
using namespace sm::modloader;

class ModloaderFixture : public testing::Test
{
protected:
    void SetUp() override { ASSERT_TRUE(ModManager::GetMods().empty()) << "Modloader list was not empty"; }

    void TearDown() override { ModManager::Reset(); }

    static std::shared_ptr<Mod> AddMod(const std::string& id) { return AddMod(std::make_shared<ModInfo>(id)); }

    static std::shared_ptr<Mod> AddMod(const std::shared_ptr<ModInfo>& info)
    {
        auto mod = std::make_shared<Mod>(info, std::make_unique<testing::NiceMock<ModImplMock>>());
        ModManager::AddMod(mod);
        return ModManager::FindModByID(info->GetID());
    }
};

TEST_F(ModloaderFixture, ShouldAddMod)
{
    AddMod("test");
    ASSERT_EQ(ModManager::GetMods().size(), 1);
    ASSERT_EQ(ModManager::GetMods()[0]->GetInfo()->GetID(), "test");
}

TEST_F(ModloaderFixture, ShouldFindModByID)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(mod->GetInfo()->GetID(), "test");
}

TEST_F(ModloaderFixture, ShouldLoadDependentlessMod)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
    mod->Toggle(true);
    ModManager::Tick();
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::ENABLED);
}

TEST_F(ModloaderFixture, ShouldUnloadDependentlessMod)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
    mod->Toggle(true);
    ModManager::Tick();
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::ENABLED);
    mod->Toggle(false);
    ModManager::Tick();
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
}

#pragma region Load dependencies
TEST_F(ModloaderFixture, ShouldLoadOrderedWaitingDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto parent = AddMod(infoParent);
    const auto child = AddMod(infoChild);

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    child->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::WAITING_DEPENDENCIES_LOAD);

    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);
}

TEST_F(ModloaderFixture, ShouldLoadOrderedDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto parent = AddMod(infoParent);
    const auto child = AddMod(infoChild);

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    child->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);
}

TEST_F(ModloaderFixture, ShouldLoadUnorderedWaitingDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    child->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::WAITING_DEPENDENCIES_LOAD);

    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);
}

TEST_F(ModloaderFixture, ShouldLoadUnorderedDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    child->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);
}
#pragma endregion

#pragma region Unload dependencies
TEST_F(ModloaderFixture, ShouldUnloadOrderedDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto parent = AddMod(infoParent);
    const auto child = AddMod(infoChild);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    child->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    parent->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);
}

TEST_F(ModloaderFixture, ShouldUnloadOrderedWaitingDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto parent = AddMod(infoParent);
    const auto child = AddMod(infoChild);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    parent->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::WAITING_DEPENDENTS_UNLOAD);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    child->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);
}

TEST_F(ModloaderFixture, ShouldUnloadUnorderedDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    child->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    parent->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);
}

TEST_F(ModloaderFixture, ShouldUnloadUnorderedWaitingDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    parent->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::WAITING_DEPENDENTS_UNLOAD);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    child->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);
}
#pragma endregion

#pragma region Active state
TEST_F(ModloaderFixture, ShouldReturnNotActiveWhenDisabled)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(mod->IsActive(), false);
}

TEST_F(ModloaderFixture, ShouldReturnNotActiveWhenWaitingDependencies)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto parent = AddMod(infoParent);
    const auto child = AddMod(infoChild);

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    child->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::WAITING_DEPENDENCIES_LOAD);
    ASSERT_EQ(child->IsActive(), false);
}

TEST_F(ModloaderFixture, ShouldReturnActiveWhenWaitingDependents)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto parent = AddMod(infoParent);
    const auto child = AddMod(infoChild);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    parent->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::WAITING_DEPENDENTS_UNLOAD);
    ASSERT_EQ(parent->IsActive(), true);
}

TEST_F(ModloaderFixture, ShouldReturnActiveWhenEnabled)
{
    const auto mod = AddMod("test");
    mod->Toggle(true);
    ModManager::Tick();
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(mod->IsActive(), true);
}
#pragma endregion

TEST_F(ModloaderFixture, ShouldDeleteDisabledMod)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(ModManager::GetMods().size(), 1);
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
    mod->SetFlag(Mod::Flag::REMOVAL_SCHEDULED);
    ASSERT_EQ(ModManager::GetMods().size(), 1);
    ModManager::Tick();
    ASSERT_EQ(ModManager::GetMods().size(), 0);
}

TEST_F(ModloaderFixture, ShouldNotDeleteEnabledMod)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(ModManager::GetMods().size(), 1);
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
    mod->Toggle(true);
    ModManager::Tick();
    ASSERT_EQ(ModManager::GetMods().size(), 1);
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::ENABLED);
    mod->SetFlag(Mod::Flag::REMOVAL_SCHEDULED);
    ModManager::Tick();
    ASSERT_EQ(ModManager::GetMods().size(), 1);
    mod->Toggle(false);
    ModManager::Tick();
    ASSERT_EQ(ModManager::GetMods().size(), 0);
}

TEST_F(ModloaderFixture, ShouldDeleteModWaitingDependencies)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    child->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::WAITING_DEPENDENCIES_LOAD);
    ASSERT_EQ(ModManager::GetMods().size(), 2);

    child->SetFlag(Mod::Flag::REMOVAL_SCHEDULED);
    ModManager::Tick();

    ASSERT_EQ(ModManager::GetMods().size(), 1);
}

TEST_F(ModloaderFixture, ShouldNotDeleteModWaitingDependendants)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    parent->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::WAITING_DEPENDENTS_UNLOAD);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    parent->SetFlag(Mod::Flag::REMOVAL_SCHEDULED);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::WAITING_DEPENDENTS_UNLOAD);
    ASSERT_EQ(ModManager::GetMods().size(), 2);

    child->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(ModManager::GetMods().size(), 1);
}

TEST_F(ModloaderFixture, ShouldReturnEmptyDependentsList)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    auto dependents = ModManager::GetModDependents(infoChild->GetID());
    ASSERT_EQ(dependents.size(), 0);
}

TEST_F(ModloaderFixture, ShouldReturnFilledDependentsList)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->dependencies.push_back(infoParent->AsDependency());

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    auto dependents = ModManager::GetModDependents(infoParent->GetID());
    ASSERT_EQ(dependents.size(), 1);
    ASSERT_EQ(dependents[0]->GetInfo()->GetID(), infoChild->GetID());
}

TEST_F(ModloaderFixture, ShouldLoadMatchingDependencyVersion)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    infoParent->version = semver::version::parse("1.0.0");

    const auto infoChild = std::make_shared<ModInfo>("test-child");
    auto dependency = infoParent->AsDependency();
    dependency.version = VersionRange::Parse(">=1.0.0");

    infoChild->dependencies.push_back(dependency);

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);
    child->Toggle(true);
    parent->Toggle(true);

    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);
}

TEST_F(ModloaderFixture, ShouldNotLoadMismatchingDependencyVersion)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    infoParent->version = semver::version::parse("1.0.0");

    const auto infoChild = std::make_shared<ModInfo>("test-child");
    auto dependency = infoParent->AsDependency();
    dependency.version = VersionRange::Parse(">2.0.0");

    infoChild->dependencies.push_back(dependency);

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);
    child->Toggle(true);
    parent->Toggle(true);

    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::WAITING_DEPENDENCIES_LOAD);
}
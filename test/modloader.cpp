#include <Log.h>
#include <gtest/gtest.h>
#include <modloader_new/ModManager.h>
#include <sdk/Game.h>
#include "mock/ModImplMock.h"

using namespace modloader;

class ModloaderFixture : public testing::Test
{
protected:
    void SetUp() override
    {
        ASSERT_TRUE(ModManager::GetMods().empty()) << "Modloader list was not empty";
    }

    void TearDown() override
    {
        ModManager::Reset();
    }

    static Mod* AddMod(const std::string& id)
    {
        return AddMod(std::make_shared<ModInfo>(id));
    }

    static Mod* AddMod(const std::shared_ptr<ModInfo>& info)
    {
        auto mod = std::make_unique<Mod>(info, std::make_unique<testing::NiceMock<ModImplMock>>());
        ModManager::AddMod(std::move(mod));
        return ModManager::FindModByID(info->id);
    }
};

TEST_F(ModloaderFixture, ShouldAddMod)
{
    AddMod("test");
    ASSERT_EQ(ModManager::GetMods().size(), 1);
    ASSERT_EQ(ModManager::GetMods()[0]->GetInfo()->id, "test");
}

TEST_F(ModloaderFixture, ShouldFindModByID)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(mod->GetInfo()->id, "test");
}

TEST_F(ModloaderFixture, ShouldLoadDependentlessMod)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
    mod->Toggle(true);
    mod->Tick();
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::ENABLED);
}

TEST_F(ModloaderFixture, ShouldUnoadDependentlessMod)
{
    const auto mod = AddMod("test");
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
    mod->Toggle(true);
    mod->Tick();
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::ENABLED);
    mod->Toggle(false);
    mod->Tick();
    ASSERT_EQ(mod->GetState()->GetType(), ModState::Type::DISABLED);
}

TEST_F(ModloaderFixture, ShouldLoadOrderedWaitingDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->deps.insert("test-parent");

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
    infoChild->deps.insert("test-parent");

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
    infoChild->deps.insert("test-parent");

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
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::WAITING_DEPENDENCIES_LOAD);

    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);
}


TEST_F(ModloaderFixture, ShouldLoadUnorderedDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->deps.insert("test-parent");

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

TEST_F(ModloaderFixture, ShouldUnloadOrderedDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->deps.insert("test-parent");

    const auto parent = AddMod(infoParent);
    const auto child = AddMod(infoChild);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();
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
    infoChild->deps.insert("test-parent");

    const auto parent = AddMod(infoParent);
    const auto child = AddMod(infoChild);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    parent->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::WAITING_DEPENDANTS_UNLOAD);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    child->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::WAITING_DEPENDANTS_UNLOAD);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);

    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);
}

TEST_F(ModloaderFixture, ShouldUnloadUnorderedDependantMod)
{
    const auto infoParent = std::make_shared<ModInfo>("test-parent");
    const auto infoChild = std::make_shared<ModInfo>("test-child");
    infoChild->deps.insert("test-parent");

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();
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
    infoChild->deps.insert("test-parent");

    const auto child = AddMod(infoChild);
    const auto parent = AddMod(infoParent);

    child->Toggle(true);
    parent->Toggle(true);
    ModManager::Tick();
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::ENABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    parent->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::WAITING_DEPENDANTS_UNLOAD);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::ENABLED);

    child->Toggle(false);
    ModManager::Tick();

    ASSERT_EQ(parent->GetState()->GetType(), ModState::Type::DISABLED);
    ASSERT_EQ(child->GetState()->GetType(), ModState::Type::DISABLED);
}
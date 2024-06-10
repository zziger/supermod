#include <gtest/gtest.h>
#include <supermod/modloader/mod/impl/ModImplLua.hpp>
#include <supermod/game/Game.hpp>

using namespace sm;
using namespace sm::modloader;

class LuaFilesystemFixture : public testing::Test
{
protected:
    std::filesystem::path cwd;

    void SetUp() override { cwd = std::filesystem::current_path(); }

    void TearDown() override { current_path(cwd); }

    static std::shared_ptr<sol::state> CreateState()
    {
        auto state = std::make_shared<sol::state>();
        state->open_libraries();
        registerLuaFilesystem(state->create_table("fs"));
        return state;
    }
};

TEST_F(LuaFilesystemFixture, ShouldReturnStringCorrectly)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):string())").get<std::string>(), "test");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/path'):string())").get<std::string>(), "test/path");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('/test/path'):string())").get<std::string>(), "/test/path");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('/test/path/'):string())").get<std::string>(), "/test/path/");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('C:/'):string())").get<std::string>(), "C:/");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test\\path'):string())").get<std::string>(), "test\\path");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('\\test\\path'):string())").get<std::string>(), "\\test\\path");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('\\test\\path\\'):string())").get<std::string>(), "\\test\\path\\");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('C:\\'):string())").get<std::string>(), "C:\\");
}

TEST_F(LuaFilesystemFixture, ShouldReturnGenericStringCorrectly)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):genericString())").get<std::string>(), "test");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/path'):genericString())").get<std::string>(), "test/path");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('/test/path'):genericString())").get<std::string>(), "/test/path");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('/test/path/'):genericString())").get<std::string>(), "/test/path/");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('C:/'):genericString())").get<std::string>(), "C:/");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test\\path'):genericString())").get<std::string>(), "test/path");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('\\test\\path'):genericString())").get<std::string>(), "/test/path");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('\\test\\path\\'):genericString())").get<std::string>(),
              "/test/path/");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('C:\\'):genericString())").get<std::string>(), "C:/");
}

TEST_F(LuaFilesystemFixture, ShouldReturnGenericPathInToString)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('test')))").get<std::string>(), "test");
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('test/path')))").get<std::string>(), "test/path");
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('/test/path')))").get<std::string>(), "/test/path");
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('/test/path/')))").get<std::string>(), "/test/path/");
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('C:/')))").get<std::string>(), "C:/");
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('test\\path')))").get<std::string>(), "test/path");
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('\\test\\path')))").get<std::string>(), "/test/path");
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('\\test\\path\\')))").get<std::string>(), "/test/path/");
    ASSERT_EQ(lua->safe_script(R"(return tostring(fs.path('C:\\')))").get<std::string>(), "C:/");
}

TEST_F(LuaFilesystemFixture, ShouldClearPath)
{
    auto lua = CreateState();
    ASSERT_EQ(
        lua->safe_script(R"(local path = fs.path('test'); path:clear(); return path:string())").get<std::string>(), "");
}

TEST_F(LuaFilesystemFixture, ShouldRemoveFilename)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):removeFilename():string())").get<std::string>(), "test/");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file/'):removeFilename():string())").get<std::string>(),
              "test/file/");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):removeFilename():string())").get<std::string>(), "");
}

TEST_F(LuaFilesystemFixture, ShouldReplaceFilename)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):replaceFilename('new'):string())").get<std::string>(),
              "test/new");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file/'):replaceFilename('new'):string())").get<std::string>(),
              "test/file/new");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):replaceFilename('new'):string())").get<std::string>(), "new");
    ASSERT_EQ(
        lua->safe_script(R"(return fs.path('test/file'):replaceFilename(fs.path('new')):string())").get<std::string>(),
        "test/new");
    ASSERT_EQ(
        lua->safe_script(R"(return fs.path('test/file/'):replaceFilename(fs.path('new')):string())").get<std::string>(),
        "test/file/new");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):replaceFilename(fs.path('new')):string())").get<std::string>(),
              "new");
}

TEST_F(LuaFilesystemFixture, ShouldReplaceExtension)
{
    auto lua = CreateState();
    ASSERT_EQ(
        lua->safe_script(R"(return fs.path('test/file.txt'):replaceExtension('new'):string())").get<std::string>(),
        "test/file.new");
    ASSERT_EQ(
        lua->safe_script(R"(return fs.path('test/file.txt'):replaceExtension('.new'):string())").get<std::string>(),
        "test/file.new");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):replaceExtension('new'):string())").get<std::string>(),
              "test/file.new");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):replaceExtension('.new'):string())").get<std::string>(),
              "test/file.new");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):replaceExtension(''):string())").get<std::string>(),
              "test/file");
    ASSERT_EQ(
        lua->safe_script(R"(return fs.path('test/file'):replaceExtension(fs.path('new')):string())").get<std::string>(),
        "test/file.new");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):replaceExtension(fs.path('.new')):string())")
                  .get<std::string>(),
              "test/file.new");
    ASSERT_EQ(
        lua->safe_script(R"(return fs.path('test/file'):replaceExtension(fs.path('')):string())").get<std::string>(),
        "test/file");
    ASSERT_EQ(
        lua->safe_script(R"(return fs.path('test/file'):replaceExtension(fs.path()):string())").get<std::string>(),
        "test/file");
}

TEST_F(LuaFilesystemFixture, ShouldMakePreferred)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(local path = fs.path('test\\file'); path:makePreferred(); return path:string())")
                  .get<std::string>(),
              "test\\file");
    ASSERT_EQ(lua->safe_script(R"(local path = fs.path('test/file'); path:makePreferred(); return path:string())")
                  .get<std::string>(),
              "test\\file");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test\\file'):makePreferred():string())").get<std::string>(),
              "test\\file");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):makePreferred():string())").get<std::string>(),
              "test\\file");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):makePreferred():string())").get<std::string>(), "test");
}

TEST_F(LuaFilesystemFixture, ShouldAppend)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return (fs.path('test') / 'file'):string())").get<std::string>(), "test\\file");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path('test') / '..'):string())").get<std::string>(), "test\\..");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path() / 'test'):string())").get<std::string>(), "test");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path() / './test/'):string())").get<std::string>(), "./test/");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path() / ''):string())").get<std::string>(), "");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):append('file'):string())").get<std::string>(), "test\\file");

    ASSERT_EQ(lua->safe_script(R"(return (fs.path('test') / fs.path('file')):string())").get<std::string>(),
              "test\\file");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path('test') / fs.path('..')):string())").get<std::string>(), "test\\..");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path() / fs.path('test')):string())").get<std::string>(), "test");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path() / fs.path('./test/')):string())").get<std::string>(), "./test/");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path() / fs.path('')):string())").get<std::string>(), "");
    ASSERT_EQ(lua->safe_script(R"(return (fs.path() / fs.path()):string())").get<std::string>(), "");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):append(fs.path('file')):string())").get<std::string>(),
              "test\\file");
}

TEST_F(LuaFilesystemFixture, ShouldReturnParentPath)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):parentPath():string())").get<std::string>(), "test");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file/'):parentPath():string())").get<std::string>(),
              "test/file");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):parentPath():string())").get<std::string>(), "");
}

TEST_F(LuaFilesystemFixture, ShouldReturnFilename)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):filename():string())").get<std::string>(), "file");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file/'):filename():string())").get<std::string>(), "");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):filename():string())").get<std::string>(), "test");
}

TEST_F(LuaFilesystemFixture, ShouldReturnStem)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file.txt'):stem():string())").get<std::string>(), "file");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file.tar.gz'):stem():string())").get<std::string>(), "file.tar");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):stem():string())").get<std::string>(), "file");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):stem():string())").get<std::string>(), "test");
}

TEST_F(LuaFilesystemFixture, ShouldReturnExtension)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file.txt'):extension():string())").get<std::string>(), ".txt");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file.tar.gz'):extension():string())").get<std::string>(), ".gz");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test/file'):extension():string())").get<std::string>(), "");
    ASSERT_EQ(lua->safe_script(R"(return fs.path('test'):extension():string())").get<std::string>(), "");
}

TEST_F(LuaFilesystemFixture, ShouldReturnEmpty)
{
    auto lua = CreateState();
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test/file'):isEmpty())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test/file/'):isEmpty())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test'):isEmpty())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path(''):isEmpty())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path():isEmpty())").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldReturnHasParentPath)
{
    auto lua = CreateState();
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file'):hasParentPath())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file/'):hasParentPath())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('/test'):hasParentPath())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test'):hasParentPath())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path(''):hasParentPath())").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldReturnHasFilename)
{
    auto lua = CreateState();
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file'):hasFilename())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test/file/'):hasFilename())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test'):hasFilename())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path(''):hasFilename())").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldReturnHasStem)
{
    auto lua = CreateState();
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file.txt'):hasStem())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file.tar.gz'):hasStem())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file'):hasStem())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test'):hasStem())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path(''):hasStem())").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldReturnHasExtension)
{
    auto lua = CreateState();
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file.txt'):hasExtension())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file.tar.gz'):hasExtension())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test/file'):hasExtension())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test'):hasExtension())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path(''):hasExtension())").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldReturnIsAbsolute)
{
    auto lua = CreateState();
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('C:/test/file'):isAbsolute())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('C:\\test/file'):isAbsolute())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('/test/file'):isAbsolute())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('\\test/file'):isAbsolute())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test/file'):isAbsolute())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('test'):isAbsolute())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path(''):isAbsolute())").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldReturnIsRelative)
{
    auto lua = CreateState();
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('C:/test/file'):isRelative())").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.path('C:\\test/file'):isRelative())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('/test/file'):isRelative())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('\\test/file'):isRelative())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test/file'):isRelative())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path('test'):isRelative())").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.path(''):isRelative())").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldReturnCurrentPath)
{
    auto lua = CreateState();
    auto cwd = std::filesystem::current_path().string();
    ASSERT_EQ(lua->safe_script(R"(return fs.currentPath():string())").get<std::string>(), cwd);
    std::filesystem::current_path("C:\\");
    ASSERT_EQ(lua->safe_script(R"(return fs.currentPath():string())").get<std::string>(), "C:\\");
}

TEST_F(LuaFilesystemFixture, ShouldChangeCurrentPath)
{
    auto lua = CreateState();
    auto cwd = std::filesystem::current_path();

    ASSERT_EQ(lua->safe_script(R"(fs.currentPath('C:/'); return fs.currentPath():string())").get<std::string>(),
              "C:\\");
    ASSERT_EQ(std::filesystem::current_path().string(), "C:\\");
    current_path(cwd);

    ASSERT_EQ(
        lua->safe_script(R"(fs.currentPath(fs.path('C:/')); return fs.currentPath():string())").get<std::string>(),
        "C:\\");
    ASSERT_EQ(std::filesystem::current_path().string(), "C:\\");
    current_path(cwd);
}

TEST_F(LuaFilesystemFixture, ShouldReturnTempDirectoryPath)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.tempDirectoryPath():string())").get<std::string>(),
              std::filesystem::temp_directory_path().string());
}

TEST_F(LuaFilesystemFixture, ShouldReturnAbsolute)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.absolute('test'):string())").get<std::string>(),
              std::filesystem::absolute("test").string());
    ASSERT_EQ(lua->safe_script(R"(return fs.absolute('test/file'):string())").get<std::string>(),
              std::filesystem::absolute("test/file").string());
    ASSERT_EQ(lua->safe_script(R"(return fs.absolute('test/file/'):string())").get<std::string>(),
              std::filesystem::absolute("test/file/").string());
    ASSERT_EQ(lua->safe_script(R"(return fs.absolute('C:/test/file'):string())").get<std::string>(), "C:\\test\\file");
    ASSERT_EQ(lua->safe_script(R"(return fs.absolute('C:\\test/file'):string())").get<std::string>(), "C:\\test\\file");
}

TEST_F(LuaFilesystemFixture, ShouldReturnRelative)
{
    auto lua = CreateState();
    ASSERT_EQ(lua->safe_script(R"(return fs.relative(fs.currentPath() / "test\\path"):string())").get<std::string>(),
              "test\\path");
    ASSERT_EQ(lua->safe_script(R"(return fs.relative(fs.currentPath() / "test\\path", fs.currentPath()):string())")
                  .get<std::string>(),
              "test\\path");
    ASSERT_EQ(lua->safe_script(R"(return fs.relative("C:\\test\\path", "C:/"):string())").get<std::string>(),
              "test\\path");
}

TEST_F(LuaFilesystemFixture, ShouldReturnIsDirectory)
{
    auto lua = CreateState();
    ASSERT_TRUE(lua->safe_script(R"(return fs.isDirectory(fs.currentPath()))").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.isDirectory("C:/"))").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.isDirectory(fs.currentPath() / "test.exe"))").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldReturnIsEmpty)
{
    auto lua = CreateState();

    auto tempDir = std::filesystem::temp_directory_path() / "supermod-test-empty-dir";
    if (exists(tempDir))
        remove_all(tempDir);
    create_directories(tempDir);

    auto tempFile = std::filesystem::temp_directory_path() / "supermod-test-empty-file";
    if (exists(tempFile))
        remove(tempFile);
    std::ofstream file(tempFile);
    file.close();

    ASSERT_FALSE(lua->safe_script(R"(return fs.isEmpty(fs.currentPath()))").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.isEmpty(fs.currentPath() / "test.exe"))").get<bool>());
    ASSERT_TRUE(
        lua->safe_script(R"(return fs.isEmpty(fs.tempDirectoryPath() / "supermod-test-empty-dir"))").get<bool>());
    ASSERT_TRUE(
        lua->safe_script(R"(return fs.isEmpty(fs.tempDirectoryPath() / "supermod-test-empty-file"))").get<bool>());

    std::filesystem::remove_all(tempDir);
    std::filesystem::remove(tempFile);
}

TEST_F(LuaFilesystemFixture, ShouldReturnExists)
{
    auto lua = CreateState();
    ASSERT_TRUE(lua->safe_script(R"(return fs.exists(fs.currentPath()))").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.exists("C:/"))").get<bool>());
    ASSERT_TRUE(lua->safe_script(R"(return fs.exists(fs.currentPath() / "test.exe"))").get<bool>());
    ASSERT_FALSE(lua->safe_script(R"(return fs.exists(fs.currentPath() / "nonexistentpath"))").get<bool>());
}

TEST_F(LuaFilesystemFixture, ShouldRemoveFile)
{
    auto lua = CreateState();

    auto tempFile = std::filesystem::temp_directory_path() / "supermod-test-remove-file";
    if (exists(tempFile))
        remove(tempFile);
    std::ofstream file(tempFile);
    file.close();

    ASSERT_TRUE(
        lua->safe_script(R"(return fs.remove(fs.tempDirectoryPath() / "supermod-test-remove-file"))").get<bool>());
    ASSERT_FALSE(exists(tempFile));
}

TEST_F(LuaFilesystemFixture, ShouldRemoveEmptyDirectory)
{
    auto lua = CreateState();

    auto tempDir = std::filesystem::temp_directory_path() / "supermod-test-remove-dir-empty";
    if (exists(tempDir))
        remove_all(tempDir);
    create_directories(tempDir);

    ASSERT_TRUE(
        lua->safe_script(R"(return fs.remove(fs.tempDirectoryPath() / "supermod-test-remove-dir-empty"))").get<bool>());
    ASSERT_FALSE(exists(tempDir));
}

TEST_F(LuaFilesystemFixture, ShouldRemoveDirectory)
{
    auto lua = CreateState();

    auto tempDir = std::filesystem::temp_directory_path() / "supermod-test-remove-dir";
    if (exists(tempDir))
        remove_all(tempDir);
    create_directories(tempDir);

    auto tempFile = tempDir / "supermod-test-remove-file";
    if (exists(tempFile))
        remove(tempFile);
    std::ofstream file(tempFile);
    file.close();

    ASSERT_EQ(
        lua->safe_script(R"(return fs.removeAll(fs.tempDirectoryPath() / "supermod-test-remove-dir"))").get<uint64_t>(),
        2);
    ASSERT_FALSE(exists(tempDir));
    ASSERT_FALSE(exists(tempFile));
}

TEST_F(LuaFilesystemFixture, ShouldCreateDirectory)
{
    auto lua = CreateState();

    auto tempDir = std::filesystem::temp_directory_path() / "supermod-test-create-dir";
    if (exists(tempDir))
        remove_all(tempDir);

    ASSERT_TRUE(lua->safe_script(R"(return fs.createDirectory(fs.tempDirectoryPath() / "supermod-test-create-dir"))")
                    .get<bool>());
    ASSERT_TRUE(exists(tempDir));
    remove_all(tempDir);
}

TEST_F(LuaFilesystemFixture, ShouldCreateDirectories)
{
    auto lua = CreateState();

    auto tempDirRoot = std::filesystem::temp_directory_path() / "supermod-test-create-dir";
    auto tempDir = tempDirRoot / "subdir";
    if (exists(tempDirRoot))
        remove_all(tempDirRoot);
    if (exists(tempDir))
        remove_all(tempDir);

    ASSERT_TRUE(lua->safe_script(
                       R"(return fs.createDirectories(fs.tempDirectoryPath() / "supermod-test-create-dir" / "subdir"))")
                    .get<bool>());
    ASSERT_TRUE(exists(tempDir));
    if (exists(tempDirRoot))
        remove_all(tempDirRoot);
}

TEST_F(LuaFilesystemFixture, ShouldCopyFile)
{
    auto lua = CreateState();

    auto tempFile = std::filesystem::temp_directory_path() / "supermod-test-copy-file";
    auto tempFileCopy = std::filesystem::temp_directory_path() / "supermod-test-copy-file-copy";
    if (exists(tempFile))
        remove(tempFile);
    if (exists(tempFileCopy))
        remove(tempFileCopy);
    std::ofstream file(tempFile);
    file.close();

    lua->safe_script(
        R"(fs.copy(fs.tempDirectoryPath() / "supermod-test-copy-file", fs.tempDirectoryPath() / "supermod-test-copy-file-copy"))");
    ASSERT_TRUE(exists(tempFileCopy));
    remove(tempFile);
    remove(tempFileCopy);
}

TEST_F(LuaFilesystemFixture, ShouldCopyDirectory)
{
    auto lua = CreateState();

    auto tempDir = std::filesystem::temp_directory_path() / "supermod-test-copy-dir";
    auto tempDirCopy = std::filesystem::temp_directory_path() / "supermod-test-copy-dir-copy";
    auto tempFile = tempDir / "supermod-test-copy-file";

    if (exists(tempDir))
        remove_all(tempDir);
    if (exists(tempDirCopy))
        remove_all(tempDirCopy);
    create_directories(tempDir);
    std::ofstream file(tempFile);
    file.close();

    lua->safe_script(
        R"(fs.copy(fs.tempDirectoryPath() / "supermod-test-copy-dir", fs.tempDirectoryPath() / "supermod-test-copy-dir-copy"))");
    ASSERT_TRUE(exists(tempDirCopy));
    ASSERT_TRUE(exists(tempDirCopy / tempFile.filename()));
    remove_all(tempDir);
    remove_all(tempDirCopy);
}

TEST_F(LuaFilesystemFixture, ShouldNotCopySubdirectories)
{
    auto lua = CreateState();

    auto tempDir = std::filesystem::temp_directory_path() / "supermod-test-copy-dir";
    auto tempSubdir = tempDir / "subdir";
    auto tempFile1 = tempDir / "supermod-test-copy-file";
    auto tempFile2 = tempSubdir / "supermod-test-copy-file";
    auto tempDirCopy = std::filesystem::temp_directory_path() / "supermod-test-copy-dir-copy";

    if (exists(tempDir))
        remove_all(tempDir);
    if (exists(tempDirCopy))
        remove_all(tempDirCopy);
    create_directories(tempSubdir);
    std::ofstream file1(tempFile1);
    file1.close();
    std::ofstream file2(tempFile2);
    file2.close();

    lua->safe_script(
        R"(fs.copy(fs.tempDirectoryPath() / "supermod-test-copy-dir", fs.tempDirectoryPath() / "supermod-test-copy-dir-copy"))");
    ASSERT_TRUE(exists(tempDirCopy));
    ASSERT_TRUE(exists(tempDirCopy / "supermod-test-copy-file"));
    ASSERT_FALSE(exists(tempDirCopy / "subdir"));
    remove_all(tempDir);
    remove_all(tempDirCopy);
}

TEST_F(LuaFilesystemFixture, ShouldCopyDirectoryRecursively)
{
    auto lua = CreateState();

    auto tempDir = std::filesystem::temp_directory_path() / "supermod-test-copy-dir";
    auto tempSubdir = tempDir / "subdir";
    auto tempFile1 = tempDir / "supermod-test-copy-file";
    auto tempFile2 = tempSubdir / "supermod-test-copy-file";
    auto tempDirCopy = std::filesystem::temp_directory_path() / "supermod-test-copy-dir-copy";

    if (exists(tempDir))
        remove_all(tempDir);
    if (exists(tempDirCopy))
        remove_all(tempDirCopy);
    create_directories(tempSubdir);
    std::ofstream file1(tempFile1);
    file1.close();
    std::ofstream file2(tempFile2);
    file2.close();

    lua->safe_script(
        R"(fs.copy(fs.tempDirectoryPath() / "supermod-test-copy-dir", fs.tempDirectoryPath() / "supermod-test-copy-dir-copy", { recursive = true }))");
    ASSERT_TRUE(exists(tempDirCopy));
    ASSERT_TRUE(exists(tempDirCopy / "supermod-test-copy-file"));
    ASSERT_TRUE(exists(tempDirCopy / "subdir" / "supermod-test-copy-file"));
    remove_all(tempDir);
    remove_all(tempDirCopy);
}

TEST_F(LuaFilesystemFixture, ShouldMoveFile)
{
    auto lua = CreateState();

    auto tempFile = std::filesystem::temp_directory_path() / "supermod-test-move-file";
    auto tempFileMove = std::filesystem::temp_directory_path() / "supermod-test-move-file-move";
    if (exists(tempFile))
        remove(tempFile);
    if (exists(tempFileMove))
        remove(tempFileMove);
    std::ofstream file(tempFile);
    file.close();

    lua->safe_script(
        R"(fs.move(fs.tempDirectoryPath() / "supermod-test-move-file", fs.tempDirectoryPath() / "supermod-test-move-file-move"))");
    ASSERT_TRUE(exists(tempFileMove));
    ASSERT_FALSE(exists(tempFile));

    lua->safe_script(
        R"(fs.rename(fs.tempDirectoryPath() / "supermod-test-move-file-move", fs.tempDirectoryPath() / "supermod-test-move-file"))");
    ASSERT_FALSE(exists(tempFileMove));
    ASSERT_TRUE(exists(tempFile));

    remove(tempFile);
}
#include <supermod/Config.hpp>
#include <supermod/pch.hpp>

#include <fstream>

Config::Config()
{
    if (exists(path))
    {
        node = YAML::LoadFile(path.string());
    }
    else
    {
        std::ofstream fstream(path);
        fstream << node;
    }
    node.SetStyle(YAML::EmitterStyle::Block);
    Process(true);
}

void Config::Save()
{
    Process(false);
    node.SetStyle(YAML::EmitterStyle::Block);
    std::ofstream fstream(path);
    fstream << node;
}

#pragma once
#ifndef _KML_MATERIAL_H_
#define _KML_MATERIAL_H_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Texture.h"

namespace kml
{
    class Material
    {
    public:
        Material();
        void SetInteger(const std::string& key, int val);
        void SetFloat(const std::string& key, float val);
        void SetString(const std::string& key, const std::string& val);
        void SetTexture(const std::string& key, std::shared_ptr<Texture> tex);
        int GetInteger(const std::string& key) const;
        float GetFloat(const std::string& key) const;
        std::string GetString(const std::string& key) const;
        std::shared_ptr<Texture> GetTexture(const std::string& key) const;

        std::vector<std::string> GetTextureKeys() const;

    public:
        float GetValue(const std::string& key) const
        {
            return GetFloat(key);
        }

        std::string GetName() const
        {
            return name_;
        }
        void SetName(const std::string& name)
        {
            name_ = name;
        }

    protected:
        std::map<std::string, int> imap;
        std::map<std::string, float> fmap;
        std::map<std::string, std::string> smap;
        std::map<std::string, std::shared_ptr<Texture> > tmap;
        std::string name_;
    };
} // namespace kml

#endif

//
// Created by roman on 4/6/18.
//

#ifndef KEYCHAINAPP_KEYCHAIN_HPP
#define KEYCHAINAPP_KEYCHAIN_HPP

#include <functional>
#include <vector>
#include <iostream>
#include <fstream>

#include <fc_light/crypto/hex.hpp>
#include <fc_light/variant.hpp>

#include <boost/filesystem.hpp>
#include <boost/signals2.hpp>

#include "keychain_commands.hpp"

namespace keychain_app
{

namespace bfs = boost::filesystem;

class keychain : public keychain_base
{
public:
  static keychain& instance(std::string&& uid_hash);
  virtual ~keychain();
  virtual std::string operator()(const fc_light::variant& command) override;
private:
  bfs::path m_init_path;
  keychain(std::string&& uid_hash, const char* default_key_dir = KEY_DEFAULT_PATH);
};

struct keychain_commands_singletone
{
    using command_ptr = std::shared_ptr<keychain_command_base>;
    static const keychain_commands_singletone& instance();
    const command_ptr operator[](command_te cmd_type) const;
private:
    std::vector<command_ptr> m_command_list;
    keychain_commands_singletone();
};

}

#endif //KEYCHAINAPP_KEYCHAIN_HPP

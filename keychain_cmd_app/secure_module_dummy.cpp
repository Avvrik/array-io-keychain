//
// Created by roman on 5/14/18.
//

#include "secure_module_dummy.hpp"

using namespace keychain_app;

sec_mod_dummy::sec_mod_dummy()
{}

sec_mod_dummy::~sec_mod_dummy()
{}

std::wstring sec_mod_dummy::get_passwd_trx(const graphene::chain::transaction& trx) const
{
  return std::wstring(L"blank_password");
}

std::string sec_mod_dummy::get_uid() const
{
  return std::string("uid");
}

void sec_mod_dummy::print_mnemonic(const string_list& mnemonic) const
{

}

std::wstring sec_mod_dummy::get_passwd_trx_raw(const std::string& raw_trx) const
{
  return std::wstring(L"blank_password");
}

std::wstring sec_mod_dummy::get_passwd(const std::string& str) const
{
  return std::wstring(L"blank_password");
}
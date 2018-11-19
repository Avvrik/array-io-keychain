
#ifndef KEYCHAINAPP_SEC_MOD_LINUX_HPP
#define KEYCHAINAPP_SEC_MOD_LINUX_HPP

#include <keychain_lib/keychain_wrapper.hpp>

namespace keychain_app
{

    class sec_mod_linux: public secure_dlg_mod_base
    {
    public:
        sec_mod_linux();
        virtual ~sec_mod_linux();
        virtual keychain_app::byte_seq_t  get_passwd_trx_raw(const std::string& raw_trx, std::string binary_dir) const override;
        virtual keychain_app::byte_seq_t get_passwd_on_create(std::string binary_dir) const override;
        virtual void print_mnemonic(const string_list& mnemonic) const override;
    private:
        static constexpr const char* pass_str = "blank_password";
    };

}

#endif //KEYCHAINAPP_SEC_MOD_LINUX_HPP

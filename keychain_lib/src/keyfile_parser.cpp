//
// Created by roman on 16/1/19
//

#include "keyfile_parser.hpp"

using namespace keychain_app;

const dev::Public& keyfile_format::keyfile_t::public_key() const
{
  return keyinfo.public_key;
}

const fc_light::time_point& keyfile_format::keyfile_t::last_date() const
{
  if (usage_time.sec_since_epoch() == 0)
    return creation_time;
  return usage_time;
}
//
// Created by roman on 4/20/18.
//

#include <fc_light/exception/exception.hpp>

#include "keychain_logger.hpp"
#include "secmod_protocol.hpp"
#include "secmod_parser_cmd.hpp"

namespace keychain_app
{

namespace secmod_commands
{

blockchain_secmod_te secmod_parser_f::operator()(const std::string& json)
{
  auto log = logger_singletone::instance();
  try
  {
    auto variant = fc_light::json::from_string(json);
    m_cmd = variant.as<secmod_command_common>();
  }
  catch (const fc_light::exception& exc){
    BOOST_LOG_SEV(log.lg, error) << "secmod common command parse error: " << exc.what();
    m_cmd.blockchain = blockchain_secmod_te::parse_error;
  }
  return m_cmd.blockchain;
}

blockchain_secmod_te secmod_parser_f::cmd_type() const
{
  return m_cmd.blockchain;
}

int secmod_parser_f::unlock_time() const
{
  return m_cmd.unlock_time;
}

bool secmod_parser_f::is_json() const
{
  return m_cmd.json;
}

secmod_parser_f::ethereum_cmd secmod_parser_f::to_ethereum() const
{
  auto check = m_cmd.blockchain == blockchain_secmod_te::ethereum && m_cmd.json;
  assert(check);
  if(!check)
    throw std::runtime_error("secmod_parser_f::to_ethereum(): cast error");
  try
  {
    return m_cmd.data.as<ethereum_cmd>();
  }
  catch (const fc_light::exception& exc)
  {
    auto log = logger_singletone::instance();
    BOOST_LOG_SEV(log.lg, error) << "secmod_parser_f::to_ethereum(): " << exc.what();
    throw std::runtime_error("secmod_parser_f::to_ethereum() error: parse error");
  }
}

secmod_parser_f::bitcoin_cmd secmod_parser_f::to_bitcoin() const
{
  auto check = m_cmd.blockchain == blockchain_secmod_te::bitcoin && m_cmd.json;
  assert(check);
  if(!check)
    throw std::runtime_error("secmod_parser_f::to_bitcoin(): cast error");
  try
  {
    return m_cmd.data.as<bitcoin_cmd>();
  }
  catch (const fc_light::exception& exc)
  {
    auto log = logger_singletone::instance();
    BOOST_LOG_SEV(log.lg, error) << "ssecmod_parser_f::to_bitcoin(): " << exc.what();
    throw std::runtime_error("secmod_parser_f::to_bitcoin() error: pasrse error");
  }
}

secmod_parser_f::ethereum_swap_cmd secmod_parser_f::to_ethereum_swap() const
{
  auto check = m_cmd.blockchain == blockchain_secmod_te::ethereum_swap && m_cmd.json;
  assert(check);
  if(!check)
    throw std::runtime_error("secmod_parser_f::to_ethereum_swap(): cast error");
  try
  {
    return m_cmd.data.as<ethereum_swap_cmd>();
  }
  catch (const fc_light::exception& exc)
  {
    auto log = logger_singletone::instance();
    BOOST_LOG_SEV(log.lg, error) << "secmod_parser_f::to_ethereum_swap(): " << exc.what();
    throw std::runtime_error("secmod_parser_f::to_ethereum_swap() error: parse error");
  }
}

secmod_parser_f::rawhash_cmd secmod_parser_f::to_rawhash() const
{
  auto check = m_cmd.blockchain == blockchain_secmod_te::rawhash && m_cmd.json;
  assert(check);
  if(!check)
    throw std::runtime_error("secmod_parser_f::to_rawhash(): cast error");
  try
  {
    return m_cmd.data.as<rawhash_cmd>();
  }
  catch (const fc_light::exception& exc)
  {
    auto log = logger_singletone::instance();
    BOOST_LOG_SEV(log.lg, error) << "secmod_parser secmod_parser_f::to_rawhash(): " << exc.what();
    throw std::runtime_error("secmod_parser_f::to_rawhash(): parse error");
  }
}

std::string secmod_parser_f::to_raw_tx() const
{
  auto check = !m_cmd.json;
  assert(check);
  if(!check)
    throw std::runtime_error("secmod_parser_f::to_raw_tx(): cast error");
  return m_cmd.data.as<std::string>();
}

std::string secmod_parser_f::to_pretty_string() const
{
  try
  {
    switch (m_cmd.blockchain)
    {
      case blockchain_secmod_te::ethereum:
        return fc_light::json::to_pretty_string(fc_light::variant(m_cmd.data.as<ethereum_cmd>()));
      case blockchain_secmod_te::bitcoin:
        return fc_light::json::to_pretty_string(fc_light::variant(m_cmd.data.as<bitcoin_cmd>()));
      case blockchain_secmod_te:: ethereum_swap:
        return fc_light::json::to_pretty_string(fc_light::variant(m_cmd.data.as<ethereum_swap_cmd>()));
      case blockchain_secmod_te::rawhash:
        return fc_light::json::to_pretty_string(fc_light::variant(m_cmd.data.as<rawhash_cmd>()));
      default:
        return std::string();
    }
  }
  catch (const fc_light::exception& exc)
  {
    auto log = logger_singletone::instance();
    BOOST_LOG_SEV(log.lg, error) << "secmod nested command error: " << exc.what();
    return std::string();
  }
  
}

}

}



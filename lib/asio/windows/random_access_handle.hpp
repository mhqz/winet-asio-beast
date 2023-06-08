#ifndef RANDOM_ACCESS_HANDLE_ADAPTER_HPP
#define RANDOM_ACCESS_HANDLE_ADAPTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio.hpp>
#include "boost/asio/windows/random_access_handle.hpp"
#include <boost/asio/detail/config.hpp>

using io_service = boost::asio::io_service;

//namespace boost {
//namespace asio {
//namespace windows {

//template <typename Executor = boost::asio::any_io_executor>
class basic_random_access_handle_extended : public boost::asio::windows::random_access_handle {
public:
  basic_random_access_handle_extended(io_service &service)
      : boost::asio::windows::random_access_handle(service) {}

};
typedef basic_random_access_handle_extended random_access_handle_extended;

//} // namespace windows
//} // namespace asio
//} // namespace boost

#endif // RANDOM_ACCESS_HANDLE_ADAPTER_HPP

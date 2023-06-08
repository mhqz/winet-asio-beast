#ifndef RANDOM_ACCESS_HANDLE_ADAPTER_HPP
#define RANDOM_ACCESS_HANDLE_ADAPTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio.hpp>
#include "boost/asio/windows/random_access_handle.hpp"
#include <boost/asio/detail/config.hpp>

using io_context = boost::asio::io_context;
using executor = boost::asio::executor;

//namespace boost {
//namespace asio {
//namespace windows {

//template <typename Executor = boost::asio::any_io_executor>
class basic_random_access_handle_extended : public boost::asio::windows::random_access_handle {
public:
  basic_random_access_handle_extended(io_context &ctx)
      : boost::asio::windows::random_access_handle(ctx) {}

  basic_random_access_handle_extended(executor exe)
      : boost::asio::windows::random_access_handle(exe) {}
};
typedef basic_random_access_handle_extended random_access_handle_extended;

//} // namespace windows
//} // namespace asio
//} // namespace boost

#endif // RANDOM_ACCESS_HANDLE_ADAPTER_HPP

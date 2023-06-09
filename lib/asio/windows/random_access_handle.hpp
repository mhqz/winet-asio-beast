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
using native_handle_t = HANDLE;
using error_code = boost::system::error_code;
namespace errc = boost::system::errc;

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

  std::size_t async_write_some(
          boost::asio::const_buffer buffer, boost::system::error_code& ec)
  {
      auto offset = current_position(ec);
      return this->impl_.get_service().write_some_at(
              this->impl_.get_implementation(), offset, buffer, ec);
  }

  static
  error_code last_error()
  {
      return make_error_code(static_cast<errc::errc_t>(errno));
  }

  size_t
  current_position(error_code& ec)
  {
      native_handle_t native_handle = this->native_handle();
      auto offset = SetFilePointer(native_handle, 0, NULL, FILE_CURRENT);
      if(INVALID_SET_FILE_POINTER ==  offset)
      {
          ec = last_error();
          if (!ec) ec = make_error_code(errc::no_message);
          return size_t(-1);
      }

      return offset;
  }
};
typedef basic_random_access_handle_extended random_access_handle_extended;

//} // namespace windows
//} // namespace asio
//} // namespace boost

#endif // RANDOM_ACCESS_HANDLE_ADAPTER_HPP

#ifndef RANDOM_ACCESS_HANDLE_ADAPTER_HPP
#define RANDOM_ACCESS_HANDLE_ADAPTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "boost/callable_traits/is_noexcept.hpp"
#include "boost/asio/any_io_executor.hpp"
#include "boost/asio/windows/overlapped_ptr.hpp"
#include "boost/asio/windows/stream_handle.hpp"
#include <boost/asio/detail/config.hpp>
#include <boost/asio/detail/type_traits.hpp>
#include <boost/core/enable_if.hpp>

#include <list>
#include <map>
#include <memory>

#include <iostream> //debug

namespace boost {
namespace asio {
namespace windows {

template <typename Executor = boost::asio::any_io_executor>
class basic_random_access_handle_extended : public boost::asio::windows::basic_stream_handle<Executor> {
public:
  typedef Executor executor_type;
  typedef std::string endpoint_type;
  typedef boost::asio::windows::basic_stream_handle<executor_type> parent_type;

  basic_random_access_handle_extended(executor_type &ex)
      : boost::asio::windows::basic_stream_handle<executor_type>(ex) {}

  template <typename ExecutionContext>
  basic_random_access_handle_extended(
      ExecutionContext &context,
      typename boost::asio::constraint<boost::asio::is_convertible<
          ExecutionContext &, boost::asio::execution_context &>::value>::type =
          0)
      : boost::asio::windows::basic_stream_handle<executor_type>(
            context.get_executor()) {}

  /*template <BOOST_ASIO_COMPLETION_TOKEN_FOR(void(boost::system::error_code,
                                                 std::size_t)) ConnectHandler
                BOOST_ASIO_DEFAULT_COMPLETION_TOKEN_TYPE(executor_type)>
  BOOST_ASIO_INITFN_AUTO_RESULT_TYPE(ConnectHandler,
                                     void(boost::system::error_code,
                                          std::size_t))*/

  typedef basic_random_access_handle_extended<> random_access_handle_extended;
};

} // namespace windows
} // namespace asio
} // namespace boost

#endif // RANDOM_ACCESS_HANDLE_ADAPTER_HPP

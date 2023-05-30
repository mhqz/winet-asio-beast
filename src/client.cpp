#include "util/signal.h"

#include <boost/asio/spawn.hpp>
#include <boost/asio/write_at.hpp>
#include <boost/asio/read_at.hpp>
#include <boost/asio/steady_timer.hpp>

namespace asio = boost::asio;
namespace errc = boost::system::errc;
namespace fs = boost::filesystem;
namespace sys = boost::system;

using Cancel = ouinet::Signal<void()>;

int main() {
    asio::io_context ctx;
    sys::error_code ec;
    Cancel cancel;

    //TODO: Convert into unit tests
    asio::spawn(ctx, [&](asio::yield_context yield){
        asio::steady_timer timer{ctx};
        timer.expires_from_now(std::chrono::seconds(2));
        timer.async_wait(yield);
    });
    ctx.run();
    return 0;
}

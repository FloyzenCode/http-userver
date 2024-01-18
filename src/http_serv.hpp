#include <userver/components/minimal_server_component_list.hpp>
#include <userver/server/handlers/http_handler_base.hpp>
#include <userver/utils/daemon_run.hpp>
 
namespace http_serv {
 
class Hello final : public userver::server::handlers::HttpHandlerBase {
 public:
  // `kName` is used as the component name in static config
  static constexpr std::string_view kName = "handler-hello-sample";
 
  // Component is valid after construction and is able to accept requests
  using HttpHandlerBase::HttpHandlerBase;
 
  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest&,
      userver::server::request::RequestContext&) const override;
};
 
}  // namespace samples::hello
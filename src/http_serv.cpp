#include "http_serv.hpp"

std::string http_serv::Hello::HandleRequestThrow(
    const userver::server::http::HttpRequest&,
    userver::server::request::RequestContext&) const {
  return "Hello world!\n";
}
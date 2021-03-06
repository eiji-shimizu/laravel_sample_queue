#include "LSQ.h"
#include "ServerApplication/Subsystems/LSQSubsystem.h"
#include "ServerApplication/Subsystems/LSQQueue.h"
#include "RequestHandler/SizeRequestHandler.h"

#include "Poco/Util/ServerApplication.h"

using namespace Poco::Util;

namespace LSQ
{

void SizeRequestHandler::handleRequest(HTTPServerRequest &request, HTTPServerResponse &response)
{
    app().logger().information("SizeRequestHandler::handleRequest");

    response.setChunkedTransferEncoding(true);
    response.setContentType("text");
    response.send() << app().getSubsystem<LSQQueue>().size();
}

} // namespace LSQ

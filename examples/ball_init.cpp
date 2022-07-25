#include <ball_log.h>
#include <ball_loggermanager.h>
#include <ball_loggermanagerconfiguration.h>
#include <ball_streamobserver.h>

#include <bsl_iostream.h>
#include <bsl_memory.h>

#include <unistd.h>

using namespace BloombergLP;

BALL_LOG_SET_NAMESPACE_CATEGORY("MAIN");

int main(int argc, char ** argv)
{
    ball::LoggerManagerConfiguration configuration;

    configuration.setDefaultThresholdLevelsIfValid(ball::Severity::e_INFO);
    ball::LoggerManagerScopedGuard lmGuard(configuration);


    bsl::shared_ptr<ball::StreamObserver> observer =
                            bsl::make_shared<ball::StreamObserver>(&bsl::cout);

    // Register file observer with the Logger Manager.
    ball::LoggerManager::singleton().registerObserver(observer, "default");

    // Start logging.
    BALL_LOG_INFO << "Hello, World!";
    
    std::ifstream inFile;
    inFile.open(argv[1]);

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str(); //str holds the content of the file
    
    BALL_LOG_INFO << str;
    
    inFile.close();

    return 0;
}

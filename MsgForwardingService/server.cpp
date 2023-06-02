#include<iostream>
#include "MsgForwarding.pb.h"
#include "MsgForwardingServer.grpc.pb.h"

#include<grpc/grpc.h>
#include<grpcpp/server_builder.h>

using namespace MsgForwarding;
using namespace grpc;

//Implement the interface
class ForwardingServer final: public Afredo::Service
{
public:
    virtual grpc::Status GetLiveUpdates(::grpc::ServerContext* context, const ::MsgForwarding::UpdateRequest* request, ::MsgForwarding::UpdateReply* response) override {
        std::cout<< "Server Live Update On Demand Requests" <<std::endl;
        
        return grpc::Status::OK;
    }

    // Implement Streaming
    virtual grpc::Status StreamLiveUpdates(ServerContext* context, const UpdateRequest* request, ServerWriter<UpdateReply>* writer) override 
    {
        // Loop through a thread safe container and wirte the data to socket

        return grpc::Status::OK;
    } 
};

int main(int argc, char* argv[]){
    std::cout<<"This sht is running" <<std::endl;
    grpc::ServerBuilder builder;
    builder.AddListeningPort("0.0.0.0:50051", grpc::InsecureServerCredentials());

    ForwardingServer fserver;
    builder.RegisterService(&fserver);
    std::unique_ptr<grpc::Server> server{builder.BuildAndStart()};
    server->Wait();

    return 0;
}
#include<iostream>
#include "MsgForwarding.pb.h"
#include "MsgForwardingServer.grpc.pb.h"

#include<grpc/grpc.h>
#include<grpcpp/create_channel.h>

using namespace MsgForwarding;
using namespace grpc;

int main(int argc, char* argv[]){

    UpdateRequest request;
    UpdateReply reply;
    request.set_name("Bin Pan");

    auto channel = grpc::CreateChannel(
        "0.0.0.0:50051", grpc::InsecureChannelCredentials()
    );
    std::unique_ptr<Afredo::Stub> stub = Afredo::NewStub(channel);

    grpc::ClientContext context;
    grpc::Status status = stub->GetLiveUpdates(&context, request, &reply);

    std::cout << reply.name() <<std::endl;

    return 0;
}
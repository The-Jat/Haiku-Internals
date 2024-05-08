#include <Messenger.h>
#include <Handler.h>
#include <Looper.h>
#include <Message.h>
#include <stdio.h>
#include <unistd.h>

class MyHandler : public BHandler {
public:
    MyHandler() : BHandler() {}

    virtual void MessageReceived(BMessage* message) {
        printf("Message received\n");
        
        int32 value;
        if (message->FindInt32("value", &value) == B_OK) {
        		printf("Received value: %ld\n", value);
        } else {
        	printf("Failed to receive value\n");
        }
    }
};

int main() {

    MyHandler* handler = new  MyHandler();
    BLooper* looper = new BLooper();
    looper->AddHandler(handler);
    
    // Start the event loop
    looper->Run();

    BMessenger messenger(handler, looper);

    // 1. Send message with command
    messenger.SendMessage('CMD1');

    // 2. Send message with message
    BMessage message('MAIL');
    message.AddInt32("value", 7);
    messenger.SendMessage(&message);

    // Wait for a while to allow messages to be processed
    usleep(10000000);

    return 0;
}

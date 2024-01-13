#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

const int BUFFER_SIZE = 5;

class Buffer {
private:
    std::queue<int> data;
    std::mutex mutex;
    std::condition_variable notEmpty;
    std::condition_variable notFull;

public:
    void produce(int item) {
        {
            std::unique_lock<std::mutex> lock(mutex);
            notFull.wait(lock, [this] { return data.size() < BUFFER_SIZE; });
            data.push(item);
        }
        notEmpty.notify_one();
    }

    int consume() {
        int item;
        {
            std::unique_lock<std::mutex> lock(mutex);
            notEmpty.wait(lock, [this] { return !data.empty(); });
            item = data.front();
            data.pop();
        }
        notFull.notify_one();
        return item;
    }
};

void producer(Buffer& buffer, int id) {
    for (int i = 0; i < 10; ++i) {
        int item = id * 100 + i;
        buffer.produce(item);
        std::cout << "Producer " << id << " produced item: " << item << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(Buffer& buffer, int id) {
    for (int i = 0; i < 10; ++i) {
        int item = buffer.consume();
        std::cout << "Consumer " << id << " consumed item: " << item << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    // Client code using the Producer-Consumer Pattern

    Buffer buffer;

    // Create producer and consumer threads
    std::thread producer1(producer, std::ref(buffer), 1);
    std::thread producer2(producer, std::ref(buffer), 2);
    std::thread consumer1(consumer, std::ref(buffer), 1);
    std::thread consumer2(consumer, std::ref(buffer), 2);

    // Wait for threads to finish
    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();

    return 0;
}

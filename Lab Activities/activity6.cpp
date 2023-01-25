/*

When burning a DVD, it is essential that the laser beam burning pits onto
the surface is constantly fed with data, otherwise the DVD fails. Most
leading DVD burn applications make use of a circular buffer to stream data
from the hard disk onto the DVD. The first part, the ‘writing process’ fills
up a circular buffer with data, then the ‘burning process’ begins to read
from the buffer as the laser beam burns pits onto the surface of the DVD.
If the buffer starts to become empty, the application should continue filling
up the emptied space in the buffer with new data from the disk. Implement
this scenario using Circular Queue.

*/

#include <iostream>
#include <fstream>
using namespace std;
const int BLOCK_SIZE = 32;               // Size of blocks to read from
disk in bytes.const int QUEUE_SIZE = 32; // Size of circular queue in
blocks.const int DVD_SIZE = 256;         // Size of DVD in bytes.
class CircularQueue
{
public:
    CircularQueue() : head_(0), tail_(0) {}
    void Enqueue(char *data)
    {
        // Check if the queue is full.
        if ((tail_ + 1) % QUEUE_SIZE == head_)
        {
            std::cout << "Queue is full, cannot enqueue 
                         data." << std::endl;
                         return;
        }
        queue_[tail_] = data;
        tail_ = (tail_ + 1) % QUEUE_SIZE;
    }
    char *Dequeue()
    {
        // Check if the queue is empty.
        if (head_ == tail_)
        {
            std::cout << "Queue is empty, cannot dequeue 
                         data." << std::endl;
                         return nullptr;
        }
        char *data = queue_[head_];
        head_ = (head_ + 1) % QUEUE_SIZE;
        return data;
    }
    int GetHead()
    {
        return head_;
    }
    int GetTail()
    {
        return tail_;
    }

private:
    char *queue_[QUEUE_SIZE];
    int head_;
    int tail_;
};
int main()
{
    // Initialize variables.
    CircularQueue queue;
    int bytes_written = 0;
    int bytes_read = 0;
    int bytes_remaining = DVD_SIZE;
    char *buffer = new char[BLOCK_SIZE];
    // Open file input.txt
    ifstream file("input.txt", ios::in | ios::binary);
    // Check if file is open.
    if (!file.is_open())
    {
        std::cout << "Could not open file." << std::endl;
        return 1;
    }
    // Read data from file.
    // and display messages accordingly while filling up
    the buffer.and writing in dvd while (bytes_remaining > 0)
    {
        // Read data from file.
        file.read(buffer, BLOCK_SIZE);
        // if full file was read then exit
        // Check if data was read.
        if (file.gcount() > 0)
        {
            // Enqueue data.
            queue.Enqueue(buffer);
            // Update bytes read.
            bytes_read += file.gcount();
            // Update bytes remaining.
            bytes_remaining -= file.gcount();
            // Display message.
            std::cout << "Read " << file.gcount() << " 
                                                     bytes from file." << std::endl;
        }
        else
        {
            // Display message.
            if (file.eof())
            {
                break;
            }
            std::cout << "Could not read data from file."
                      << std::endl;
        }
        // write to dvd
        if (queue.GetHead() != queue.GetTail())
        {
            // Dequeue data.
            buffer = queue.Dequeue();
            // Update bytes written.
            bytes_written += BLOCK_SIZE;
            // Update bytes remaining.
            bytes_remaining -= BLOCK_SIZE;
            // Display message.
            std::cout << "Wrote " << BLOCK_SIZE << " 
                                                   bytes to DVD." << std::endl;
        }
    }
    // Close file.
    file.close();
    return 0;
}

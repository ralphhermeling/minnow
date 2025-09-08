#include "byte_stream.hh"
#include <algorithm>
#include <ranges>

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ), buffer_() {
  buffer_.reserve(capacity);
}

void Writer::push( string data )
{
  const auto space_available = capacity_ - buffer_.size();
  const auto bytes_to_push = std::min(data.size(), space_available);
  
  buffer_ += data.substr(0, bytes_to_push);
  bytes_pushed_ += bytes_to_push;
}

void Writer::close()
{
  is_closed_ = true;
}

bool Writer::is_closed() const
{
  return is_closed_; 
}

uint64_t Writer::available_capacity() const
{
  return capacity_ - buffer_.size();
}

uint64_t Writer::bytes_pushed() const
{
  return bytes_pushed_;
}

string_view Reader::peek() const
{
  return string_view(buffer_);
}

void Reader::pop( uint64_t len )
{
  const auto bytes_to_pop = std::min(len, buffer_.size());
  buffer_.erase(0, bytes_to_pop);
  bytes_popped_ += bytes_to_pop;
}

bool Reader::is_finished() const
{
  return is_closed_ && !buffer_.size();
}

uint64_t Reader::bytes_buffered() const
{
  return buffer_.size(); 
}

uint64_t Reader::bytes_popped() const
{
  return bytes_popped_;
}


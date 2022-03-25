#pragma once

//
// INVARIANT: w_deleted_count <= w_deleting_count <= w_cached_read_count <= shared_read_count <= r_reading_count <= r_cached_write_count <= shared_write_count <= w_writing_count <= w_deleted_count + MAX_SIZE
//
// INVARIANT:      w_writing_count      - w_deleted_count     <= MAX_SIZE
// =========>      w_writing_count      - w_cached_read_count <= MAX_SIZE
// =========>      shared_write_count   - w_cached_read_count <= MAX_SIZE
// =========>      shared_write_count   - shared_read_count   <= MAX_SIZE
//
//
// INVARIANT: 0 <= r_cached_write_count - r_reading_count
// =========> 0 <= r_cached_write_count - shared_read_count
// =========> 0 <= shared_write_count   - shared_read_count
//
//
// THEOREM: =========> 0 <= shared_write_count   - shared_read_count   <= MAX_SIZE
//





//
//
// Channel/Queue:
//
// Shared between Producer and Consumer
//
struct channel_t{
public:
  size_t left, right;

  //
  // Intialize
  //
  channel_t(){
    this->left = this->right = 0;
  }
};


//
// Producer's (not shared)
//
struct writeport_t{
public:
  size_t sz, right, left;

  //
  // Intialize
  //
  writeport_t(size_t tsize)
  {
    this->sz = tsize;
    this->right = this->left = 0;
  }

  //
  // no of entries available to write
  //
  // helper function for write_canreserve
  //
  size_t write_reservesize(){
    return this->left > this->right ? this->left - this->right : this->sz - this->right + this->left;
  }

  //
  // Can write 'n' entries?
  //
  bool write_canreserve(size_t n){
    return n <= this->write_reservesize();
  }

  //
  // Reserve 'n' entries for write
  //
  size_t write_reserve(size_t n){
    hoh_assert(write_canreserve(n), "write_reserve");
    size_t ret = this->right;
    this->right = (this->right + n) % this->sz;
    return ret;
  }

  //
  // Commit
  //
  // Read/Write shared memory data structure
  //
  void write_release(channel_t& ch){
    ch.right = this->right;
  }

  //
  //
  // Read/Write shared memory data structure
  //
  void read_acquire(channel_t& ch){
    this->left = ch.left;
  }

  //
  // No of entires available to delete
  //
  size_t delete_reservesize(){
    return this->right >= this->left ? this->right - this->left : this->sz - this->left + this->right;
  }

  //
  // Can delete 'n' entires?
  //
  bool delete_canreserve(size_t n){
    return n <= this->delete_reservesize();
  }

  //
  // Reserve 'n' entires for deletion
  //
  size_t delete_reserve(size_t n){
    hoh_assert(delete_canreserve(n), "delete_reserve");
    size_t ret = this->left;
    this->left = (this->left + n) % this->sz;
    return ret;
  }

  //
  // Update the state, if any.
  //
  void delete_release(){
    return;
  }
};


//
// Consumer's (not shared)
//
//
struct readport_t{
public:
  size_t sz, right, left;

  //
  // Initialize
  //
  readport_t(size_t tsize)
  {
    this->sz = tsize;
    this->right = this->left = 0;
  }

  //
  // Read/Write shared memory data structure
  //
  void write_acquire(channel_t& ch){
    this->right = ch.right;
  }

  //
  // no of entries available to read
  //
  size_t read_reservesize(){
    return this->right >= this->left ? this->right - this->left : this->sz - this->left + this->right;
  }

  //
  // Can Read 'n' entires?
  //
  bool read_canreserve(size_t n){
    return n <= this->read_reservesize();
  }

  //
  // Reserve 'n' entires to be read
  //
  size_t read_reserve(size_t n){
    hoh_assert(read_canreserve(n), "read_reserve");
    size_t ret = this->left;
    this->left = (this->left + n) % this->sz;
    return ret;
  }

  //
  // Read/write shared memory data structure
  //
  void read_release(channel_t& ch){
    ch.left = this->left;
  }
};



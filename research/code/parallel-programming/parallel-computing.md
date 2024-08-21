# Parallel Computing Notes

When processing a large distributed data structure, each node will have a portion of the data structure and must index it starting at 0 without context of how it fits into the larger data structure. After processing is complete, the components are reassembled from the nodes into the final data structure. 

In parallel computing:
- synchronous means that the operations occur one after the other (sequential; this usually involves blocking or waiting to prevent events from executing out of order 
- asynchronous tasks execute independently and concurrently without context of the other asynchronous tasks 
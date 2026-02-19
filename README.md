# io-stream

**io-stream** is a buffered I/O stream abstraction for reading structured text data incrementally from file descriptors in C.

It is designed to handle continuous input safely and predictably, exposing a simple line-oriented interface while maintaining explicit control over memory and state.

---

## Philosophy

Low-level I/O is inherently stateful.

Rather than treating input as a sequence of isolated reads, this project models input as a continuous stream that must be managed carefully across function calls.

The core principles are:

- **Explicit state management**  
  Buffered data is preserved and consumed deliberately.

- **Clear memory ownership**  
  Allocation, reuse, and cleanup responsibilities are unambiguous.

- **Deterministic behavior**  
  Each call advances the stream in a predictable way.

- **Boundary-aware reading**  
  Buffer limits, delimiters, and end-of-file conditions are handled explicitly.

---

## What It Provides

`io-stream` implements a line-oriented input mechanism that:

- Reads from file descriptors incrementally
- Accumulates partial reads into complete lines
- Preserves leftover data between calls
- Handles end-of-file and error conditions gracefully
- Supports multiple file descriptors independently

All functionality is implemented from scratch without relying on higher-level I/O utilities.

---

## Structure

.
├── include/ # Public interface
├── src/ # Core implementation
├── Makefile
└── README.md


The project is intentionally minimal, focusing on correctness and clarity rather than abstraction depth.

---

## Usage

Build the library:

```sh
make


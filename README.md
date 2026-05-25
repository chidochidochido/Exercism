# 🏋️ Exercism Solutions

Welcome to my personal repository of solutions for **[Exercism](https://exercism.org)** exercises! 

This repository contains my solutions to various coding challenges across multiple programming languages, helping me hone my problem-solving skills, learn language-specific idioms, and practice clean code principles.

---

## 📊 Overview & Progress

Here is a summary of the tracks and exercises completed:

| Track / Language | Icon | Completed Exercises | Test Runner Command |
| :--- | :---: | :---: | :--- |
| **C** | 🇨 | **29** | `make` |
| **Python** | 🐍 | **17** | `pytest` |
| **Rust** | 🦀 | **2** | `cargo test` |
| **C++** | ⚙️ | **1** | `cmake` / `make` |
| **Elixir** | 💧 | **1** | `mix test` |

---

## 📁 Repository Structure

The repository is organized by language tracks, with each subfolder containing individual exercise folders downloaded from Exercism:

```text
Exercism/
├── c/                     # C language track (29 exercises)
│   ├── acronym/
│   ├── binary/
│   └── ...
├── cpp/                   # C++ language track (1 exercise)
│   └── hello-world/
├── elixir/                # Elixir language track (1 exercise)
│   └── hello-world/
├── python/                # Python language track (17 exercises)
│   ├── bob/
│   ├── pangram/
│   └── ...
└── rust/                  # Rust language track (2 exercises)
    ├── hello-world/
    └── reverse-string/
```

---

## 🧪 Running the Tests

To verify the solutions locally, navigate to the specific exercise directory and run the respective test suite:

### 🇨 C
Make sure you have `make` and a C compiler (like `gcc` or `clang`) installed:
```bash
cd c/<exercise-name>
make
```

### ⚙️ C++
Make sure you have CMake and a C++ compiler installed:
```bash
cd cpp/<exercise-name>
mkdir -p build && cd build
cmake ..
make
./<exercise-name>
```

### 🐍 Python
Make sure you have `pytest` installed:
```bash
cd python/<exercise-name>
pytest
```

### 🦀 Rust
Make sure you have Rust/Cargo installed:
```bash
cd rust/<exercise-name>
cargo test
```

### 💧 Elixir
Make sure you have Elixir installed:
```bash
cd elixir/<exercise-name>
mix test
```

---

## 🛠️ Git Configuration

This repository uses a global [.gitignore](file:///D:/5_EXERCISES/Exercism/.gitignore) to automatically exclude Exercism boilerplate metadata, build artifacts, compiler caches, and test suites, ensuring only the core solution files are tracked in git history.

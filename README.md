# 🛒 E-Commerce Order Management System

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)

A lightweight, terminal-based **Order Management System** written in C, designed to simulate the core backend operations of an e-commerce platform. It allows businesses or developers to manage customer orders efficiently through a clean console interface — with full support for creating, viewing, searching, updating, and persisting order records.

---

## 📌 Table of Contents

- [Overview](#overview)
- [Real-World Use Cases](#real-world-use-cases)
- [Features](#features)
- [Project Structure](#project-structure)
- [Data Model](#data-model)
- [Getting Started](#getting-started)
- [Usage Guide](#usage-guide)
- [Input Validation](#input-validation)
- [File Persistence](#file-persistence)
- [Sample Output](#sample-output)
- [Limitations & Future Improvements](#limitations--future-improvements)
- [Author](#author)

---

## 🧭 Overview

This project was built as a **Final Project** for a C programming course, demonstrating practical use of:

- Structs and arrays
- File I/O (reading/writing to `.txt`)
- Input validation and error handling
- Modular function design
- Menu-driven console applications

While console-based, the logic mirrors what real inventory and order management backends do — maintain records, validate data, allow updates, and persist state between sessions.

---

## 🌍 Real-World Use Cases

Although this is a terminal application, the concepts it implements are directly applicable to real-world systems:

| Scenario | How This Project Applies |
|---|---|
| **Small retail shops** | Track customer orders without expensive software |
| **Student projects / prototyping** | Blueprint for building a full-stack order system |
| **Learning C programming** | Demonstrates structs, file I/O, and validation in practice |
| **Logistics backends** | Order status tracking (Pending → Shipped → Delivered) mirrors real courier systems |
| **Inventory management** | Quantity and price fields simulate basic stock tracking |
| **Offline POS systems** | Can be adapted for point-of-sale terminals without internet |

In a production environment, this system would typically be extended with a database (e.g., MySQL), a REST API layer, and a frontend UI — but the **core data flow and business logic remain the same**.

---

## ✨ Features

- ➕ **Add Orders** — Create new orders with full customer and product details
- 📋 **Display All Orders** — View all orders in a formatted table
- 🔍 **Search Orders** — Look up any order instantly by its unique ID
- ✏️ **Update Orders** — Modify existing order details in place
- 💾 **Save Orders** — Persist all records to a local `orders.txt` file
- 📂 **Load Orders** — Automatically restore saved orders on startup
- ✅ **Input Validation** — Prevents invalid names, prices, quantities, and statuses
- 🔄 **Order Status Lifecycle** — Supports: `Pending` → `Shipped` → `Delivered` / `Cancelled`

---

## 🗂 Project Structure

```
Ecommerce-Order-Management/
│
├── FINAL_PROJECT.c       # Main source file (all logic)
├── orders.txt            # Auto-generated data file (created on first run)
└── README.md             # Project documentation
```

> The entire project is contained in a single `.c` file, following a clean modular approach using separate functions for each operation.

---

## 🧱 Data Model

Each order is stored as a `struct` with the following fields:

```c
typedef struct {
    int   id;           // Unique Order ID
    int   qty;          // Quantity ordered
    float price;        // Price per unit
    char  name[50];     // Customer name
    char  product[50];  // Product name
    char  status[20];   // Order status
} Order;
```

Orders are stored in an in-memory array of up to **100 records**, and saved to `orders.txt` using a pipe-delimited (`|`) format for easy parsing.

---

## 🚀 Getting Started

### Prerequisites

- A C compiler such as **GCC** (comes with MinGW on Windows, built-in on Linux/macOS)

### Compile

```bash
gcc FINAL_PROJECT.c -o order_manager
```

### Run

```bash
# On Linux / macOS
./order_manager

# On Windows
order_manager.exe
```

---

## 📖 Usage Guide

When you run the program, you'll see the main menu:

```
|=================================================|
        E-Commerce Order Management System
|=================================================|
 1. Add Order
 2. Display All Orders
 3. Search Order
 4. Update Order
 5. Save Orders
 6. Load Orders
 7. Exit
|-------------------------------------------------|
```

### Adding an Order
Choose option `1` and fill in:
- A unique numeric **Order ID**
- **Customer Name** (letters and spaces only)
- **Product Name** (must contain at least one letter)
- **Quantity** (integer)
- **Price** (decimal number)
- **Status**: must be one of `Pending`, `Shipped`, `Delivered`, `Cancelled`

### Searching for an Order
Choose option `3` and enter the Order ID. The matching record is displayed instantly.

### Updating an Order
Choose option `4`, enter the Order ID, and re-enter all fields with new values.

### Saving & Loading
- Option `5` saves all current orders to `orders.txt`
- Option `6` loads orders from `orders.txt`
- **Orders are loaded automatically every time the program starts**

---

## 🛡 Input Validation

The system enforces strict input rules to prevent bad data:

| Field | Rule |
|---|---|
| Order ID | Must be a valid integer; duplicates rejected |
| Customer Name | Letters and spaces only |
| Product Name | Must contain at least one letter; allows digits, `-`, `#`, spaces |
| Quantity | Must be a valid integer |
| Price | Must be a valid decimal number |
| Status | Must exactly match: `Pending`, `Shipped`, `Delivered`, or `Cancelled` |

Invalid inputs prompt the user to re-enter until a valid value is provided.

---

## 💾 File Persistence

Orders are saved in `orders.txt` using a pipe-delimited format:

```
1|John Doe|Laptop Pro|2|750.000000|Shipped
2|Jane Smith|Wireless Mouse|5|29.990000|Pending
3|Ali Rahman|USB-C Hub #3|1|45.500000|Delivered
```

This file is created automatically if it doesn't exist, and is read on every program launch to restore the previous session's data.

---

## 📸 Sample Output

```
ID    Name            Product         Qty   Price      Status
---------------------------------------------------------------------
1     John Doe        Laptop Pro      2     750.00     Shipped
2     Jane Smith      Wireless Mouse  5     29.99      Pending
3     Ali Rahman      USB-C Hub #3    1     45.50      Delivered
```

---

## 🔮 Limitations & Future Improvements

| Current Limitation | Potential Improvement |
|---|---|
| Max 100 orders | Use dynamic memory allocation (`malloc`) |
| Single file storage | Integrate with SQLite or MySQL database |
| No delete function | Add order deletion by ID |
| Terminal only | Build a GUI using GTK or port to a web API |
| No sorting/filtering | Add sort by price, date, or status |
| No authentication | Add user login and role-based access |
| Single user | Support multi-user concurrent access |

---

## 👨‍💻 Author

**Rithik** — [@Rithik-HyperLoop69](https://github.com/Rithik-HyperLoop69)

> Built as a Final Project for a C Programming course.  
> Feel free to fork, improve, and use as a learning reference!

---

*If you found this project helpful, consider giving it a ⭐ on GitHub!*

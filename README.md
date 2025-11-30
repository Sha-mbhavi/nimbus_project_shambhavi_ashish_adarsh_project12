 Project Information
- Project Name (Nimbus): Project_Shambhavi
- GitHub Repository: Nimbus_Project_Shambhavi_Project12
- Assigned Project Number: Project 12
- Submission Deadline: 30th November 2025, 23:59 IST

🎯 Objective
The goal of this project is to design and implement a Smart Parking Management System that efficiently allocates parking slots, computes fees, and generates occupancy/revenue reports. The system applies C programming concepts such as structures, arrays, loops, functions, pointers, and dynamic memory management to solve a real-world problem in urban parking optimization.

🛠️ Features Implemented
- Slot Management:
- Each slot has attributes: slotID, size (small/medium/large), occupied flag, and vehicle info.
- Dynamic resizing of slots using realloc() to simulate parking lot expansion.
- Slot Allocation Algorithm (Greedy):
- Allocates the smallest adequate free slot for a vehicle.
- Ensures optimal utilization of parking space.
- Billing System:
- Computes fees based on entry/exit time difference.
- Supports day/night rates.
- Applies fines for overstays.
- Functional Operations:
- Search: Find vehicles or slots.
- Free-up: Release a slot when a vehicle exits.
- Display: Show current occupancy and slot details.
- Reports:
- Daily occupancy report.
- Revenue aggregation report.

📚 Development Steps
- Problem Analysis & Flowchart Creation
- Designed slot allocation and billing algorithms.
- Data Structures Setup
- Defined struct Slot and struct Vehicle.
- Core Functions Implemented
- allocateSlot(), freeSlot(), searchSlot(), displaySlots(), generateReport().
- Pointer Integration
- Linked vehicles to slots using pointers.

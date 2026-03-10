# DSS and Schnorr Signature Project

This project implements a **toy version of Digital Signature Standard (DSS)** and **Schnorr Signature** using **C++ with Object-Oriented Programming (OOP) principles**. The goal is to understand digital signatures, apply OOP concepts, and follow good coding practices (“8 golden rules”) in a clear, modular project.

---

## Project Highlights

- C++ implementation of DSS and Schnorr signature algorithms using **classes and objects**  
- Demonstrates **signature generation and verification**  
- Applies **OOP principles**: encapsulation, abstraction, modularity, and reusability  
- Follows **8 golden rules** for clean, readable, and maintainable code  
- HTML documentation explains step-by-step workings of the algorithms  
- PDF report provides methodology, analysis, and results  
- PowerPoint slides summarize the project workflow for presentations  

---

## Tools & Technologies

- **C++** – Core implementation of DSS and Schnorr signatures  
- **Object-Oriented Programming (OOP)** – Classes, encapsulation, modular design  
- **HTML** – Interactive documentation  
- **PDF** – Project report detailing methodology and results  
- **PowerPoint (PPT)** – Presentation slides  
- **Git & GitHub** – Version control  

---

## Project Structure
DSS-and-Schnorr-Signature-Project/
│
├── cpp/ # C++ source files
│ ├── dss_schnorr.cpp # Main code with OOP design
│ └── dss_schnorr.txt # Optional readable version of code
├── html/ # HTML documentation/webpage
│ └── dss_schnorr.html
├── docs/ # Project report PDF
│ └── Project_Report.pdf
├── ppt/ # Presentation slides
│ └── DSS_Schnorr_Presentation.pptx
├── README.md
└── .gitignore

---

## Methodology

1. **C++ Implementation**  
   - Designed using **classes** to represent key components of DSS and Schnorr signature algorithms.  
   - Functions include **key generation, signing, and verification**.  
   - Encapsulation and abstraction ensure modularity and readability.  

2. **OOP Principles Applied**  
   - **Encapsulation:** Secure data members in classes  
   - **Abstraction:** Provide clean interfaces for signing/verification  
   - **Modularity:** Separate code into classes and functions  
   - **Reusability & Maintainability:** Designed following best practices  

3. **8 Golden Rules of Coding**  
   - Meaningful variable names  
   - Proper indentation and formatting  
   - Avoid hardcoding values  
   - Separate logical components into classes/functions  
   - Document code properly  
   - Use constants where needed  
   - Handle errors and exceptions  
   - Optimize for clarity over cleverness  

4. **HTML Documentation**  
   - Provides **step-by-step explanation** of DSS and Schnorr signatures  
   - Interactive webpage allows easy understanding of algorithm workflow  

5. **PDF Report & Presentation**  
   - PDF (`Project_Report.pdf`) describes methodology, implementation, and results  
   - PPT summarizes the workflow and key concepts  

---

## Usage Instructions

### Run C++ Code
1. Compile:

```bash
g++ cpp/dss_schnorr.cpp -o dss_schnorr
./dss_schnorr
Purpose

The project demonstrates how to implement digital signature algorithms using C++ with OOP principles. It emphasizes clean code, modularity, and best practices while providing educational resources through HTML, PDF, and presentation slides.

Future Improvements

Implement larger key sizes for realistic cryptography

Add real-time signature verification

Expand HTML documentation with interactive examples

Include additional signature algorithms for comparison

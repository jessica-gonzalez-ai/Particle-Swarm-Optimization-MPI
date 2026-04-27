# Parallel Particle Swarm Optimization (PSO) with MPI 🧬

This repository contains a high-performance implementation of the **Particle Swarm Optimization (PSO)** algorithm, developed in **C**. It includes both a serial version and a parallel version utilizing **MPI** (Message Passing Interface) for distributed computing.

##  Overview
Particle Swarm Optimization is a computational method that optimizes a problem by iteratively trying to improve a candidate solution with regard to a given measure of quality. This project focuses on the parallelization of the swarm's movement and fitness evaluation to achieve significant speedups in optimization tasks.

##  Technical Stack
* **Language:** C
* **Parallel Framework:** MPI (Message Passing Interface)
* **Mathematical Tools:** MT (Mersenne Twister) for high-quality statistical procedures.

## 📁 Repository Structure
* `swarmOp.c`: Serial implementation of the PSO algorithm.
* `swarmOp_paralelo_MPI_PSO.c`: Parallel implementation optimized for distributed memory systems.
* `alea.h`: Header for random number generation and MPI support.
* `mt.h`: Header for statistical and mathematical procedures.

##  Academic Context
This project was developed as part of the **Artificial Intelligence Engineering** curriculum at the **Instituto Tecnológico de La Paz**, focusing on advanced optimization techniques and parallel architectures.

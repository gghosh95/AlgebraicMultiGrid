/*
==================================================

CONJUGATE GRADIENT SOLVER CLASS

AUTHOR : GAUTAM D GHOSH
DATE   : 06/07/2020

==================================================
*/

#include<iostream>
#include<vector>
#include<fstream>
#include<thread>
#include<chrono>
#include<stdlib.h>
#include<time.h>

#include<Eigen/Dense>
#include "../utility/MatrixIO.hpp"

#ifndef CONJUGATEGRADIENTSOLVER
#define CONJUGATEGRADIENTSOLVER

typedef Eigen::MatrixXd DenseMatrix;
typedef Eigen::VectorXd Vector;

class ConjugateGradientSolver
{
 // private vectors/matrices
  private:
    Vector F;
    DenseMatrix K;
    Vector U_guess;   
  
  // private member variables
  private:
    double tolerance; 
    int max_iterations, total_equations;
  
    std::ofstream file_writer; 

  // Constuctor/destructor
  public:
    ConjugateGradientSolver(std::string K_file, std::string F_file, const unsigned total_equations);
   ~ConjugateGradientSolver();
   
  // public member functions 
  public:
    void Solve();
};

#endif

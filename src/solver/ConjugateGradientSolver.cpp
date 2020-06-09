#include "ConjugateGradientSolver.hpp"

ConjugateGradientSolver::ConjugateGradientSolver(std::string K_file, std::string F_file,const unsigned total_equations)
 : tolerance(0.0001),
   max_iterations(total_equations),
   total_equations(total_equations)                                    
{
  std::cout << "=================Initialzing Solver=================\n" << std::endl;
  
  // Allocate memory
  F.resize(this->total_equations,1);
  U_guess.resize(this->total_equations,1);
  K.resize(this->total_equations,this->total_equations);
  
  // Load data from text files
  DenseMatIO::ReadAndStoreVector(F_file,F);
  DenseMatIO::ReadAndStoreMatrix(K_file,K);
  
  // Print information to console
  std::cout << "Number of equations = " << total_equations << std::endl;
  std::cout << "Size of K = " << K.rows() << "x" << K.rows() << std::endl;
  std::cout << "Size of F = " << F.size() << "x" << "1" << std::endl; 
  std::cout << "Taking inital guess as zero" << std::endl;
  std::cout << "error tolerance = " << tolerance << "\n" << std::endl;
  
  std::cout << "===============Initialization Finished==============\n" << std::endl; 
  
}

ConjugateGradientSolver::~ConjugateGradientSolver()
{
}

void ConjugateGradientSolver::Solve()
{
  std::vector<double> X;
  std::vector<double> Y;
  
  file_writer.open("../src/plotter/coords.csv");
  if(!file_writer.is_open()) throw std::runtime_error("ERROR: Unable to open file!");
  file_writer.clear();
  
  for(int ii=100; ii>0; ii--)
  {
    X.push_back(ii);
    Y.push_back(ii);
    std::cout << ii << "," << ii << std::endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    file_writer << ii << "," << ii << "\n";
    file_writer.flush();
  }  
  file_writer.close();
}

















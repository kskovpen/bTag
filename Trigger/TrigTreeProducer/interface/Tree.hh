#ifndef TREE_H
#define TREE_H

#include <TTree.h>
#include <string>
#include <iostream>
#include <vector>

#include <boost/any.hpp>
using boost::any_cast;

#define DEFVAL -666

#include "Trigger/TrigTreeProducer/interface/Helper.hh"

class Tree
{
 public:

   Tree(TTree* _tree) {tr = _tree;};
   TTree* tr;

   void Init();
   void CreateBranches();

   std::vector<int> trigID;
   std::vector<int> trigPass;
   std::vector<float> trigPS;
   
   std::vector<int> objN;
   std::vector<std::vector<float> > objPt;
   std::vector<std::vector<float> > objEta;
   std::vector<std::vector<float> > objPhi;
   
   int jetN;
   
//   float mc_weight;

};

#endif

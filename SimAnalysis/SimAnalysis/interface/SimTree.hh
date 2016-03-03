#ifndef SIMTREE_H
#define SIMTREE_H

#include <TTree.h>
#include <TLorentzVector.h>
#include <string>
#include <iostream>
#include <vector>

#include <boost/any.hpp>
using boost::any_cast;
typedef std::map<std::string, std::map<std::string, boost::any> >  t_map;

#define DEFVAL -666

class SimTree
{
 public:

   SimTree(TTree* _tree) {tree = _tree;};
   TTree* tree;

   void Init();
   void CreateBranches(int buffersize);

//   int el_n;

   std::vector<float> primVtxX;
   std::vector<float> primVtxY;
   std::vector<float> primVtxZ;
   
   std::vector<int> momId;
   std::vector<float> momPt;
   std::vector<float> momEta;
   
   std::vector<float> muR;
   std::vector<float> muRpv;
   std::vector<float> muPosX;
   std::vector<float> muPosY;
   std::vector<float> muPosZ;
   std::vector<float> muPt;
   std::vector<float> muEta;

   std::vector<float> muSimR;
   std::vector<float> muSimRpv;
   std::vector<float> muSimPosX;
   std::vector<float> muSimPosY;
   std::vector<float> muSimPosZ;
   std::vector<float> muSimPt;
   std::vector<float> muSimEta;
   
   std::vector<int> partonId;
   std::vector<float> partonPt;
   std::vector<float> partonEta;

/*   std::vector<int> momGenId;
   std::vector<float> momGenPt;
   std::vector<float> momGenEta;
   
   std::vector<float> muGenPt;
   std::vector<float> muGenEta;
   
   std::vector<int> partonGenId;
   std::vector<float> partonGenPt;
   std::vector<float> partonGenEta;*/
};

#endif
